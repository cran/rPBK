test_that("ppc", {
    # (1) load data
    data("fitPBK_C4")
    # (3) run plot
    ppcPBK_C4 = ppc(fitPBK_C4)
    # (4) check plot has been executed:
    testthat::expect_true(all(class(ppcPBK_C4) == c("gg", "ggplot")))
})