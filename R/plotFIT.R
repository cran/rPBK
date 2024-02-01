#' Plotting method for \code{fitPBK} objects
#'
#' This is the generic \code{plot} S3 method for the
#' \code{fitTK}.  It plots the fit obtained for each
#' variable in the original dataset.
#'
#' @param x And object returned by \code{fitPBK}
#' @param \dots Additional arguments
#'
#' @return a plot of class \code{ggplot}
#'
#' @export
#'
#' @examples
#' # (1) load a fitPBK object
#' data("fitPBK_C4")
#' # (2) plot result of bayesian fitting
#' plot(fitPBK_C4)
#'
#' @import ggplot2
#'
plot.fitPBK <- function(x, ...){

  out_fit <- rstan::extract(x$stanfit)
  out_data <- x$stanPBKdata

  # data.frame for observation
  ls_data <- lapply(1:out_data$N_comp, function(i_comp){
    df = data.frame(observation = c(out_data$val_obs_comp[,,i_comp]))
    df$time = rep(out_data$time_obs_comp, out_data$N_rep)
    df$compartment = out_data$col_compartment[i_comp]
    return(df)
  })
  df_data = do.call("rbind", ls_data)

  # data.frame for prediction
  val_pred_quant <- lapply(1:out_data$N_comp, function(i_comp){
    df = df_quant95_(out_fit$val_pred_comp[,,i_comp])
    df$time = out_data$time_obs_comp
    df$compartment = out_data$col_compartment[i_comp]
    return(df)
  })
  df_fit <- do.call("rbind", val_pred_quant)

  df_fit$q50 = ifelse( df_fit$q50 < 0, 0, df_fit$q50)
  df_fit$qinf95 = ifelse( df_fit$qinf95 < 0, 0, df_fit$qinf95)
  df_fit$qsup95 = ifelse( df_fit$qsup95 < 0, 0, df_fit$qsup95)

  # plot
  plt <- ggplot(data = df_fit) +
    theme_classic() +
    labs(x = "Time", y = "Concentration") +
    # scale_y_continuous(limits = c(0,NA)) +
    geom_ribbon(
      aes_string(x = 'time', ymin = 'qinf95', ymax = 'qsup95'),
      fill = "grey80") +
    geom_line(
      aes_string(x = 'time', y = 'q50'),
      color = "orange") +
    geom_point(data = df_data,
               aes_string(x = 'time', y = 'observation' )) +
    facet_wrap(~compartment, scales = "free")

  return(plt)
}


# internal #####################################################################

#' Compute 95 credible intervals
#' 
#' Compute quantiles 95 credible intervals
#' 
#' @param x An object of class \code{fitPBK}
#' @param \dots Additional arguments
#' @importFrom stats quantile
#'
#' @return An object of class \code{data.frame} returning median and 95 credible interval
#'
df_quant95_ <- function(x,...){

  mat_quants = apply(x, 2, quantile, probs = c(0.025, 0.5, 0.975), ...)
  df = data.frame(
    q50 = mat_quants[2,],
    qinf95 = mat_quants[1,],
    qsup95 = mat_quants[3,]
  )
  return(df)
}
