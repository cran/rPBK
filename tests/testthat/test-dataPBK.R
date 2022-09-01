test_that("dataPBK", {
    
    # load data
    data("dataMaleGammarusSingle")
    data_MGS <- dataMaleGammarusSingle[dataMaleGammarusSingle$replicate == 1,]
    data("dataCompartment4")
    data_C4 <- dataCompartment4

    # test function
    modelData_MGS <- dataPBK(
            object = data_MGS,
            col_time = "time",
            col_replicate = "replicate",
            col_exposure = "expw",
            col_compartment = "conc",
            time_accumulation = 4,
            nested_model = NA
        )
    testthat::expect_true(is.list(modelData_MGS))
})
