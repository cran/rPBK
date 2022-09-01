## ---- include = FALSE---------------------------------------------------------
knitr::opts_chunk$set(
  collapse = TRUE,
  comment = "#>"
)

## ----setup--------------------------------------------------------------------
library(rPBK)

## ----MGS_data-----------------------------------------------------------------
data("dataMaleGammarusSingle")
# work only when replicate have the same length !!!
data_MGS <- dataMaleGammarusSingle[dataMaleGammarusSingle$replicate == 1,]

## ----MGS_prepare--------------------------------------------------------------
modelData_MGS <- dataPBK(
  object = data_MGS,
  col_time = "time",
  col_replicate = "replicate",
  col_exposure = "expw",
  col_compartment = "conc",
  time_accumulation = 4,
  nested_model = NA)

## ----MGS_fit------------------------------------------------------------------
fitPBK_MGS <- fitPBK(modelData_MGS)

## ----MGS_plot-----------------------------------------------------------------
plot(fitPBK_MGS)

## ----MGS_WAIC-----------------------------------------------------------------
library(loo)
log_lik_MGS <- loo::extract_log_lik(fitPBK_MGS$stanfit, merge_chains = FALSE)
WAIC_MGS <- waic(log_lik_MGS)

## ----C4_data------------------------------------------------------------------
data("dataCompartment4")
data_C4 <- dataCompartment4

## ----C4_prepare---------------------------------------------------------------
modelData_C4 <- dataPBK(
  object = data_C4,
  col_time = "temps",
  col_replicate = "replicat",
  col_exposure = "condition",
  col_compartment = c("intestin", "reste", "caecum", "cephalon"),
  time_accumulation = 7)

## ----C4_nested----------------------------------------------------------------
nested_model(modelData_C4)

## ----C4_fit-------------------------------------------------------------------
fitPBK_C4 <- fitPBK(modelData_C4, chains = 1, iter = 1000)

## ----C4_plot------------------------------------------------------------------
plot(fitPBK_C4)

## ----C4_WAIC------------------------------------------------------------------
library(loo)
log_lik_C4 <- loo::extract_log_lik(fitPBK_C4$stanfit, merge_chains = FALSE)
WAIC_C4 <- waic(log_lik_C4)
print(WAIC_C4)

## ----C4_LOO-------------------------------------------------------------------
r_eff_C4 <- relative_eff(exp(log_lik_C4))
LOO_C4 <- loo(log_lik_C4, r_eff = r_eff_C4, cores = 2)
print(LOO_C4)

## ----T2_nested_C4-------------------------------------------------------------
nm_C4 = nested_model(modelData_C4)

## ----T2_k_matrix_C4-----------------------------------------------------------
nm_C4$k_nest

## ----T2_k_matrix_C4_----------------------------------------------------------
matrix(c(
  c(0,1,1,1),
  c(1,0,1,1),
  c(1,1,0,0),
  c(1,1,1,0)),
  ncol=4,nrow=4,byrow=TRUE)

## ----T2_k_matrix_C4_h---------------------------------------------------------
matrix(c(
  c(0,1,1,1),
  c(0,0,1,1),
  c(0,0,0,0),
  c(0,0,0,0)),
  ncol=4,nrow=4,byrow=TRUE)

## ----T2_prepare---------------------------------------------------------------
modelData_C42 <- dataPBK(
  object = data_C4,
  col_time = "temps",
  col_replicate = "replicat",
  col_exposure = "condition",
  col_compartment = c("intestin", "reste", "caecum", "cephalon"),
  time_accumulation = 7,
  ku_nest = c(1,1,1,1), # No Change here
  ke_nest = c(1,1,1,1), # No Change here
  k_nest = matrix(c(
            c(0,1,1,1),
            c(0,0,1,1),
            c(0,0,0,0),
            c(0,0,0,0)),
            ncol=4,nrow=4,byrow=TRUE) # Remove 
  )

## ----T2_nested----------------------------------------------------------------
nested_model(modelData_C42)

## ----T2_fit-------------------------------------------------------------------
fitPBK_C42 <- fitPBK(modelData_C42, chains = 1, iter = 1000)

## ----T2_plot------------------------------------------------------------------
plot(fitPBK_C42)

## ----T2_WAIC------------------------------------------------------------------
log_lik_C42 <- loo::extract_log_lik(fitPBK_C42$stanfit, merge_chains = FALSE)
WAIC_C42 <- waic(log_lik_C42)
print(WAIC_C42)

## ----T2_compare---------------------------------------------------------------
comp_C4_C42 <- loo_compare(WAIC_C4, WAIC_C42)
print(comp_C4_C42)

