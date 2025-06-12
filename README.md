# rPBK

An R package for the inference of physiologically-based toxicokinetics model

# Dev R

## Package skeleton

```R
library("rstantools")
rstan_create_package(path = 'rPBK')
```

See further information here [rstantools](https://mc-stan.org/rstantools/articles/minimal-rstan-package.html)

## Dev info

Use this to add a new dependency
```R
usethis::use_package("ggplot2")
usethis::use_package("testthat")
```

Additional dependencies used in the Vignette

```R
usethis::use_package("loo", "Suggests")
```


Use this to add a data to be used in the package
```R
usethis::use_data(dataCompartment4)
usethis::use_data(dataMaleGammarusSingle)
```

Use this to add a test function. ADD A TEST FILE TO EVERY NEW R FILE!
```R
usethis::use_test("data.R")
usethis::use_test("dataPBK.R")
usethis::use_test("fitPBK.R")
usethis::use_test("plotFIT.R")
usethis::use_test("plotPPC.R")
usethis::use_test("predictPBK.R")
```

Add vignette
```R
usethis::use_vignette("Examples")
```

remove files from building
```R
usethis::use_build_ignore("[.]so", escape = FALSE)
usethis::use_build_ignore("[.]o", escape = FALSE)
```

### Rstudio

Before 'Documentation' and 'Clear and Rebuild' and within 'Configure Build Tools...'
untick 'use devtools package function if available'.
Keep 'Generate Configuration with Roxygen'

### little hack

- to load all internal function of a package during dev: `devtools::load_all()`

### A lighter package build

To make the package lighter, we have to remove the vignettes: see file `.Rbuildignore`

### Error to recompile during package dev

Sometimes, there is an Error to recompile during development after change of .stan files.
A solution is to remove the `rPBK` folder in R repository of the win-library (see the path written in the error message).

An other solution is to build the package from the terminal using `R CMD -preclean INSTALL rPBK` from parent directory of `rPBK`.

## Dev tools

- S3 Object System: http://adv-r.had.co.nz/S3.html
- Google's R Style Guide: https://google.github.io/styleguide/Rguide.html
- testthat: https://github.com/r-lib/testthat
- covr: https://github.com/r-lib/covr
- to add a package `xxr`: `usethis::use_package("xxr")`
- to add data set `datar`: `usethis::use_data(datar)`

# Dev In Docker


## Roxygen for the documentation

```R
example(source) # defines the sourceDir() function
try(roxygen2::roxygenize(load_code = sourceDir), silent = TRUE)
roxygen2::roxygenize()
```

## Build

```R
pkgbuild::compile_dll() # to preform a fake R CMD install
roxygen2::roxygenize() # to update the documentation
devtools::install() 
```

Test and Check the package

```R
devtools::test() 
devtools::check() 
```

then to build the package:

```R
 devtools::build() 
```


If the archive produce (`rPBK_X.Y.Z.tar.gz`) is in the workspace of the container (outside RPBK), then move the archive:
```sh
mv rPBK_X.Y.Z.tar.gz rPBK
```

Check as CRAN
```
R CMD check --as-cran
```

or from command line, but not working very well to be send to CRAN:

```
R CMD INSTALL --preclean --no-configure --build .
R CMD INSTALL --preclean --build .
```
