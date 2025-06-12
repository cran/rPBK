test_that("plot", {
    # (1) load data
    data("fitPBK_C4")
    # (3) run plot
    plotPBK_C4 = plot(fitPBK_C4)
    # (4) check plot has been executed:
    testthat::expect_true(ggplot2::is_ggplot(plotPBK_C4))
})
