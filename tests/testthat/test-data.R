test_that("datasets", {
  data("dataCompartment4")
  data("dataMaleGammarusSingle")
  testthat::expect_true(is.data.frame(dataCompartment4))
  testthat::expect_true(is.data.frame(dataMaleGammarusSingle))
})