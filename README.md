# CQUADPACK

[![Build Status](https://travis-ci.org/ESSS/cquadpack.svg?branch=master)](https://travis-ci.org/ESSS/cquadpack)

This package includes a complete port of the *QUADPACK* Fortran codes to C.
Unlike ports created by translators, this port reimplements the algorithms
to take advantage of C progralm structure and dynamic memory. Every effort
has been made to leave the low level code intact, except where some
opportunity to convert from unstructured blocks to more structured form
was taken.

Some changes to the calling conventions for various routines have also
been made. In particular, the low level integrators, such as **'dqk??.c'**,
are treated as functions returning a value. In the original code, these
integrators are subroutines passing the result back through a parameter.

QUADPACK is well documented in the publication, ``QUADPACK, A Subroutine
Package for Automatic Integration,'' by R. Piessens, et al., Springer-Verlag,
1980.

This port was initially done by C. Bond (http://www.crbond.com/) and this is
a repackaging of the initial code with some minor changes.

## DEPENDENCIES

The code has no external dependency. It only depends on the standard C library.

## INSTALLATION

`conda install -c https://conda.anaconda.org/edisongustavo cquadpack`

## BUILDING

[CMake](http://www.cmake.org/) is required.

It is recommended to use [out-of-source builds](http://www.cmake.org/Wiki/CMake_FAQ#Out-of-source_build_trees) builds.
For that, create the **build** directory and run CMake on it:

    mkdir build
    cd build
    cmake ..

### Visual Studio

Open the Visual Studio command prompt and run the above commands. A solution *cquadpack.sln* will be generated, open it
with Visual Studio and compile it.

## FILES

The files are distributed among several directories for convenience in
identification. For application development, a different directory
structure would be necessary. Feel free to move the files according to
your requirements.

### SOURCE FILES

The complete set of source and header files are in the directory: **src/**.

If you have access to the QUADPACK documentation, you will be able to
match files in this directory to the original FORTRAN files.

### TEST PROGRAMS

Some test programs which exercise most of the *CQUADPACK* routines are
included. They are in the directore: **test/**.

If you plan to use *CQUADPACK* for more than one application, it would be
better to compile all the source files into a library, and just add the
library to your project.

### MISCELLANEOUS APPLICATIONS

These include a programs to compute elliptic integrals and demonstrate
double integrals.

## CAVEATS

The author makes no warranty about the correctness of any translation. This
is just as well, because there is no guarantee that the original codes were
error free in the first place. Every effort has been made to assure that the
programs are functional and that they perform as expected.
