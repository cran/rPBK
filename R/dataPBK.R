#' Create a list giving data and parameters to use in the model inference.
#'
#' @param object An object of class \code{data.frame}
#' @param col_time Column name of the time column
#' @param col_replicate Column name of the replicate column
#' @param col_exposure Column name of the exposure column.
#' @param col_compartment Column names of the compartment column. If several columns,
#'  give a vector with the column names.
#' @param time_accumulation A scalar giving accumulation time.
#' @param ku_nest Vector of binary (0 or 1) to select the uptake route. Use the
#'  nested_model() on the \code{dataPBK} object to check it.
#' @param ke_nest Vector of binary (0 or 1) to select the excretion route. Use the
#'  nested_model() on the \code{dataPBK} object to check it.
#' @param k_nest Matrix of binary (0 or 1) to select interaction routes. Use the
#'  nested_model() on the \code{dataPBK} object to check it.
#' @param \dots Further arguments to be passed to generic methods
#'
#' @export
#'
#' @return A \code{list} with data and parameters require for model inference.
#'
#'
dataPBK <- function(object, ...){
  UseMethod("dataPBK")
}


#' @rdname dataPBK
#'
#' @export
#' @importFrom stats na.omit
#'
#' @examples
#' # (1) load data file
#' data("dataCompartment4")
#' # (2) prepare data set
#' dataPBK_C4 <- dataPBK(
#'   object = dataCompartment4,
#'   col_time = "temps",
#'   col_replicate = "replicat",
#'   col_exposure = "condition",
#'   col_compartment = c("intestin", "reste", "caecum", "cephalon"),
#'   time_accumulation = 7)
#'
dataPBK.data.frame <- function(
    object,
    col_time = NA,
    col_replicate = NA,
    col_exposure = NA,
    col_compartment = NA,
    time_accumulation = NA,
    ku_nest = NA,
    ke_nest = NA,
    k_nest = NA,
    ...){

  # recover time objects
  if(!is.na(col_time)){
    data_time = object[[col_time]]
  } else{
    data_time = object[["time"]]
  }
  uniq_time = sort(unique(data_time))
  N_time = length(uniq_time)

  # recover replicate objects
  if(!is.na(col_replicate)){
    data_replicate = object[[col_replicate]]
  } else{
    data_replicate = object[["replicate"]]
  }
  uniq_replicate = sort(unique(data_replicate))
  N_replicate = length(uniq_replicate)

  # recover exposure object
  N_exposure <- length(col_exposure)
  ls_exposure <- lapply(1:N_exposure, function(i_exp){
    r <- do.call(
      "cbind",
      lapply(1:N_replicate, function(i) object[data_replicate==uniq_replicate[1],col_exposure[i_exp]])
    )
  })
  Cobs_exposure <- array(unlist(ls_exposure), dim=c(N_time, N_exposure))

  # recover compartment object
  N_compartment <- length(col_compartment)
  ls_compartment <- lapply(1:N_compartment, function(i_comp){
    r <- do.call(
      "cbind",
      lapply(1:N_replicate, function(i) object[data_replicate==uniq_replicate[i],col_compartment[i_comp]])
    )
  })
  Cobs_compartment <- array(unlist(ls_compartment), dim=c(N_time, N_replicate, N_compartment))

  #Value of each organ concentration at t=0 (mean of the N values)
  Cobs_compartment_t0 <- sapply(1:N_compartment, function(i) mean(Cobs_compartment[1,1:N_replicate,i]))
  # to give dimension with a scalar
  Cobs_compartment_t0 <- array(Cobs_compartment_t0, N_compartment)

  nested_model <- nested_model_(col_compartment, ku_nest, ke_nest, k_nest)

  rtrn_ls <- list(
    origin_data = object,
    # ----------------------------------
    col_time = col_time,
    col_replicate = col_replicate,
    col_exposure = col_exposure,
    col_compartment = col_compartment,
    # ----------------------------------
    N_obs_comp = N_time,
    time_obs_comp = uniq_time,
    time_eval = uniq_time[-1],
    N_rep = N_replicate,
    N_exp = N_exposure,
    N_comp = N_compartment,
    val_obs_comp = Cobs_compartment,
    C0_obs_comp = Cobs_compartment_t0,
    val_obs_exp = Cobs_exposure,
    N_obs_exp = N_time,
    time_obs_exp = uniq_time,
    t0 = 0,
    tacc = time_accumulation,
    ku_nest = array(nested_model$ku_nest, dim = N_compartment),
    ke_nest = array(nested_model$ke_nest, dim = N_compartment),
    k_nest = nested_model$k_nest
  )

  class(rtrn_ls) <- append("stanPBKdata", class(rtrn_ls))

  return(rtrn_ls)
}

##########
#' @rdname dataPBK
#'
#' @param object An object of class \code{stanPBKdata} (from \code{dataPBK()} function.
#' @param ku_nest Vector of binary (0 or 1) to select the uptake route. Use the
#'  nested_model() on the \code{stanPBKdata} object to check it.
#' @param ke_nest Vector of binary (0 or 1) to select the excretion route. Use the
#'  nested_model() on the \code{stanPBKdata} object to check it.
#' @param k_nest Matrix of binary (0 or 1) to select interaction routes. Use the
#'  nested_model() on the \code{stanPBKdata} object to check it.
#'
#' @export
#'
nested_model <- function(object){
  UseMethod("nested_model")
}

#' @rdname dataPBK
#'
#' @examples
#' # (1) load data file
#' data("dataCompartment4")
#' # (2) prepare data set
#' dataPBK_C4 <- dataPBK(
#'   object = dataCompartment4,
#'   col_time = "temps",
#'   col_replicate = "replicat",
#'   col_exposure = "condition",
#'   col_compartment = c("intestin", "reste", "caecum", "cephalon"),
#'   time_accumulation = 7)
#' # (3) check nesting
#' nested_model(dataPBK_C4)
#' # (2bis)
#' dataPBK_C42 <- dataPBK(
#'   object = dataCompartment4,
#'   col_time = "temps",
#'   col_replicate = "replicat",
#'   col_exposure = "condition",
#'   col_compartment = c("intestin", "reste", "caecum", "cephalon"),
#'   time_accumulation = 7,
#'   ku_nest = c(1,1,1,1), # No Change here
#'   ke_nest = c(1,1,1,1), # No Change here
#'   k_nest = matrix(c(
#'             c(0,1,1,1),
#'             c(0,0,1,1),
#'             c(0,0,0,0),
#'             c(0,0,0,0)),
#'             ncol=4,nrow=4,byrow=TRUE) # Remove 
#'   )
#' # (3bis) re-checking nesting
#' nested_model(dataPBK_C42)
#'
#' @export
#'
nested_model.stanPBKdata = function(object){
  nested_model_(
    object$col_compartment,
    ku_nest = object$ku_nest,
    ke_nest = object$ke_nest,
    k_nest = object$k_nest)
}

# internal #####################################################################
nested_model_ = function(col_compartment, ku_nest = NA, ke_nest = NA, k_nest = NA){
  N_comp = length(col_compartment)
  # uptake
  if(all(is.na(ku_nest))){
    ku_nest = rep(1,N_comp)
  }
  names(ku_nest) = paste("uptake", col_compartment)
  # excretion
  if(all(is.na(ke_nest))){
    ke_nest = rep(1,N_comp)
  }
  names(ke_nest) = paste("excretion", col_compartment)
  # interaction
  if(all(is.na(k_nest))){
    k_nest = matrix(1,ncol=N_comp,nrow=N_comp)
    diag(k_nest) = 0
  }
  colnames(k_nest) = col_compartment
  rownames(k_nest) = col_compartment

  return(
    list(ku_nest=ku_nest,ke_nest=ke_nest, k_nest=k_nest)
  )
}
################################################################################
