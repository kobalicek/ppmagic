PPMagic
=======

C/C++ Preprocessor Magic:

  * [Official Repository (kobalicek/ppmagic)](https://github.com/kobalicek/ppmagic)
  * [Unlicense] (http://unlicense.org)

Introduction
------------

`PPMagic` defines some useful C/C++ preprocessor macros that you can use to simplify your life while using C/C++ preprocessor. In C++ projects you had better not to use preprocessor at all, but the world is not purely black nor white, and sometimes preprocessor macros are necessary.

Documentation
-------------

Macro                        | Description
:--------------------------- | :-----------------------------------------------
`_PP_1(...)` to `_PP_9(...)` | Select Nth element from `__VA_ARGS__` list of arguments.
`_PP_BOOL(_X)                | Convert `_X` expression to a boolean value (`0` or `1`).
`_PP_CONCAT(_A, _B)          | Concatenate `_A` and `_B` by using `##` operator.
`_PP_COUNT(...)              | Expands to the count of `__VA_ARGS__` passed.
`_PP_DUMMY(...)              | Prepends `dummy` into the `__VA_ARGS__`. You don't want to use this one.
`_PP_IF_ELSE(_Exp)(_A)(_B)   | If the expression `_Exp` evaluates to true expand `_A`, otherwise expand `_B`.
`_PP_INDIRECT(_X)            | Indirection used by some workarounds, expands to `_X`.
`_PP_NOT(_X)                 | Negate `_X` expression.
`_PP_STRINGIFY(...)          | Stringify anything passed to it (after it has been evaluated).

For a more complete documentation with some example usage see [ppmagic.h](ppmagic.h) header.
