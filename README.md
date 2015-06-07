PPMagic
=======

C/C++ Preprocessor Magic:

  * [Official Repository (kobalicek/ppmagic)](https://github.com/kobalicek/ppmagic)
  * [Unlicense] (http://unlicense.org)

Introduction
------------

`PPMagic` defines some useful C/C++ preprocessor macros that you can use to simplify your life. Ideally, you don't need any of macros provided, however, the C/C++ world is full of projects and demands and these macros are sometimes needed, and you had better testing them before they are incorporated into your code-base.

The `PPMagic` is more likely a playground (with continuous integration enabled) than a library. You can just copy&paste what you need from [ppmagic.h](ppmagic.h) header and rename all macros to fit your conventions. The main goal is to have a small project where these macros can be tested by using various compilers and settings.

Documentation
-------------

Macro                        | Description
:--------------------------- | :-----------------------------------------------
`_PP_1(...)` to `_PP_9(...)` | Select Nth element from `__VA_ARGS__` list of arguments.
`_PP_BOOL(_X)`               | Converts `_X` to a boolean value (`0` or `1`).
`_PP_CONCAT(_A, _B)`         | Concatenates `_A` and `_B` by using `##` operator.
`_PP_COUNT(...)`             | Counts the number of `__VA_ARGS__` arguments.
`_PP_DUMMY(...)`             | Prepends `dummy` before `__VA_ARGS__`.
`_PP_HAS_ARG(...)`           | Expands to `1` if `...` contains one or more argument, otherwise expands to `0`.
`_PP_IF(_Exp)(_OnTrue)`      | Expands `_OnTrue` if the expression `_Exp` evaluates to true.
`_PP_IF_ELSE(_Exp)(_A)(_B)`  | Expands `_A` if the expression `_Exp` evaluates to true, expands `_B` otherwise.
`_PP_INDIRECT(_X)`           | Expands to `_X`, indirection used by some workarounds.
`_PP_NOT(_X)`                | Negates `_X` expression.
`_PP_STRINGIFY(...)`         | Converts to string anything passed to it.

For a more complete documentation with some example usage see [ppmagic.h](ppmagic.h) header.

Contributing
------------

  * If provided macros are failing please report that problem by creating an issue and specify failing compiler and environment. The best scenario is to identify the problem yourself and provide a pull request, however, I can help with fixing the problem if it's possible.
  * Proposal of new macros should be reported by opening an issue as well, but please add use cases and reason why the macro should be included in `PPMagic`. The main goal is not to have 1000 macros, but to have the most useful and complicated ones implemented and tested.
