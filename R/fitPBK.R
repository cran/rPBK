#' Bayesian inference of TK model with Stan
#'
#' @param stanPBKdata List of Data require for computing
#' @param \dots Arguments passed to `rstan::sampling` (e.g. iter, chains).
#'
#' @return An object of class `fitPBK` containing two object: \code{stanPBKdata}
#' the data set used for inference and \code{stanfit}  returned by `rstan::sampling`
#'
#' @rdname fitPBK
#'
#' @export
#'
fitPBK <- function(stanPBKdata, ...){
  UseMethod("fitPBK")
}

#' @rdname fitPBK
#'
#' @export
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
#' # (3) run Bayesian fitting: <5 sec to be executed
#' # 1 chain and 10 iterations is fast to run but provide
#' # bad goodness-of-fit
#' fitPBK_C4_FASTbadGOF <- fitPBK(dataPBK_C4, chains = 1, iter = 10)
#' \donttest{
#'   # (3) run Bayesian fitting: > 5 sec to be executed
#'   # 4 chains and 2000 iterations provides better estimates
#'   fitPBK_C4 <- fitPBK(dataPBK_C4, chains = 4, iter = 2000)
#' }
#'
fitPBK.stanPBKdata <- function(stanPBKdata, ...) {
  dataFit <- filter_AD_(stanPBKdata)
  stanfit <- rstan::sampling(stanmodels$PBK_AD, data = dataFit, ...)
  out <- list(stanPBKdata = stanPBKdata, stanfit = stanfit)
  class(out) <- append("fitPBK", class(out))

  return(out)
}

# internal #####################################################################
filter_AD_ <- function(x){
  return(
    list(
      N_obs_comp = x$N_obs_comp,
      N_rep = x$N_rep,
      N_comp = x$N_comp,
      time_obs_comp = x$time_obs_comp,
      val_obs_comp = x$val_obs_comp,
      val_obs_exp = x$val_obs_exp[1],
      t0 = x$t0,
      tacc = x$tacc,
      ku_nest = x$ku_nest,
      ke_nest = x$ke_nest,
      k_nest = x$k_nest
    )
  )
}
