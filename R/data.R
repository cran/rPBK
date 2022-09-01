#' An example data set with 4 compartment
#'
#' A dataset containing an example with 4 compartments.
#'
#' @format A data frame with 21 rows and 7 variables:
#' \describe{
#'   \item{temps}{vector of time}
#'   \item{condition}{exposure concentration}
#'   \item{replicat}{replicate of experiment}
#'   \item{intestin}{compartiment 'intestin'}
#'   \item{caecum}{compartiment 'caecum'}
#'   \item{cephalon}{compartiment 'cephalon'}
#'   \item{reste}{compartiment 'reste'}#'
#' }
#'
#' @usage data(dataCompartment4)
"dataCompartment4"

#' An example data set with 1 compartment
#'
#' A dataset containing an example with a single compartment.
#'
#' @format A data frame with 22 rows and 4 variables:
#' \describe{
#'   \item{time}{vector of time}
#'   \item{expw }{exposure concentration}
#'   \item{replicate}{replicat of experiment}
#'   \item{conc}{internal measured concentration}#'
#' }
#' @usage data(dataMaleGammarusSingle)
#'
"dataMaleGammarusSingle"


#' An example of fitPBK object
#'
#' A fitPBK object containing Bayesian inference of the 
#' \code{dataCompartment4} data set.
#'
#' @format A \code{fitPBK} object with: 
#' \describe{
#'   \item{stanPBKdata}{original data frame wrap in a formatted list for inference}
#'   \item{stanfit}{a \code{stanfit} object resulting from inference with stan}
#' }
#'
#' @usage data(fitPBK_C4)
"fitPBK_C4"