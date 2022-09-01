#' Interpolate function implemented in Stan only export for checking
#'
#' This function export the linear iterpolation implemented in Stan. It
#' can be use to re-sample the exposure profiles. 
#'
#' @param x interpolation point x
#' @param xpt a vector of x axis (has to be same size as \code{ypt} vector)
#' @param ypt a vector of y axis (has to be same size as \code{ypt} vector)
#' @param chain number of chain
#' @param iter number of iteration
#' @param \dots Arguments passed to `rstan::sampling`
#'
#' @return A sample of a stanfit object returning a linear interpolation 
#'
#' @export
export_interpolate <- function(x, xpt, ypt, chain = 1, iter =1, ...) {
  if(length(xpt) != length(ypt)) stop("length xpt and ypt mismatch")
  data = list(x=x,xpt=xpt,ypt=ypt,N=length(xpt))
  stanfit <- rstan::sampling(stanmodels$export_interpolate, data = data,
                             algorithm = "Fixed_param", chain = chain, iter = iter, ...)
  out <- rstan::extract(stanfit)
  return(out$y)
}
