test_that("fitPBK", {
    options(warn=-1) # bacause warning appears with convergence of the chain
    # (1) load data
    data("dataCompartment4")
    # (2) prepare data set
    dataPBK_C4 <- dataPBK(
        object = dataCompartment4,
        col_time = "temps",
        col_replicate = "replicat",
        col_exposure = "condition",
        col_compartment = c("intestin", "reste", "caecum", "cephalon"),
        time_accumulation = 7)
    # (3) run Bayesian fitting: > 5 sec to be executed
    fitPBK_C4 <- fitPBK(dataPBK_C4, chains = 1, iter = 100)
    # (4) check run has been executed:
    testthat::expect_true(is.list(fitPBK_C4))
    testthat::expect_true(all(class(fitPBK_C4$stanPBKdata) == c("stanPBKdata", "list")))
    testthat::expect_true(class(fitPBK_C4$stanfit) == "stanfit")
})