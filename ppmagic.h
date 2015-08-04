// [PPMagic]
// C/C++ Preprocessor Magic
//
// [License]
// Public Domain <http://unlicense.org>

// DISCLAIMER: I didn't want to write this file, however, it happened, because
// I needed to use some macros to implement certain functionality. After hours
// of googling I decided to simplify my life and to write something that I can
// test and extend in the future.

// EMBEDDERS: All macros use `_PP` prefix, you can just replace it with
// anything you prefer more so it can fit into your project's conventions.

// [Guard]
#ifndef _PP_MAGIC_H
#define _PP_MAGIC_H

// ----------------------------------------------------------------------------
// Just in case there are other compilers relying on such behavior or VS team
// fixed this issue in some future version.
#if defined(_MSC_VER)
# define _PP_MSVC_BEHAVIOR
#endif // _MSC_VER

// Select Nth element from `__VA_ARGS__` list of arguments and forget about
// the rest.
#define _PP_1(_1, ...) _1
#define _PP_2(_1, _2, ...) _2
#define _PP_3(_1, _2, _3, ...) _3
#define _PP_4(_1, _2, _3, _4, ...) _4
#define _PP_5(_1, _2, _3, _4, _5, ...) _5
#define _PP_6(_1, _2, _3, _4, _5, _6, ...) _6
#define _PP_7(_1, _2, _3, _4, _5, _6, _7, ...) _7
#define _PP_8(_1, _2, _3, _4, _5, _6, _7, _8, ...) _8
#define _PP_9(_1, _2, _3, _4, _5, _6, _7, _8, _9, ...) _9

// Indirection (required for some workarounds and stringify).
#define _PP_INDIRECT(_X) _X

// Prepend a dummy `dummy` argument before __VA_ARGS__, used to add something
// to simplify dangling comma handling in case __VA_ARGS__ is empty.
//
// Examples:
//   `_PP_DUMMY_VA()`     -> `dummy`
//   `_PP_DUMMY_VA(0)`    -> `dummy, 0`
//   `_PP_DUMMY_VA(0, 1)` -> `dummy, 0, 1`
#if defined(_PP_MSVC_BEHAVIOR)
# define _PP_DUMMY_VA(...) dummy,__VA_ARGS__
#else
# define _PP_DUMMY_VA(...) dummy,##__VA_ARGS__
#endif

// Concatenate two tokens `_A` and `_B` by using `##` operator.
//
// Examples:
//   `_PP_CONCAT(A, B)` -> AB
#define _PP_CONCAT(_A, _B) _A##_B

// Negate an expression `_X` passed to `_PP_NOT(_X)`.
//
// Examples:
//   `_PP_NOT(0)`  -> `1`
//   `_PP_NOT(1)`  -> `0`
//   `_PP_NOT(42)` -> `0`
#if defined(_PP_MSVC_BEHAVIOR)
# define _PP_IS(...) _PP_INDIRECT(_PP_2(__VA_ARGS__, 0))
#else
# define _PP_IS(...) _PP_2(__VA_ARGS__, 0)
#endif
#define _PP_PROBE() ~, 1

#define _PP_NOT(_X) _PP_IS(_PP_CONCAT(_PP_NOT_, _X))
#define _PP_NOT_0 _PP_PROBE()

// Convert an expression `_X` to a boolean value `0` or `1`.
//
// Examples:
//   `_PP_BOOL(0)`  -> `0`
//   `_PP_BOOL(1)`  -> `1`
//   `_PP_BOOL(42)` -> `1`
#define _PP_BOOL(_X) _PP_NOT(_PP_NOT(_X))

// Pure C/C++ preprocessor-based `_PP_IF_ELSE(_Expression)(IsTaken)(NotTaken)`
// implementation that can be used to conditionally compile code based on a
// condition known during preprocessing. Maybe the syntax is not the  best
// possible, but it works and it doesn't violate the standard at all.
//
// The implementation is based on <http://jhnet.co.uk/articles/cpp_magic> and
// was fixed to work also with MSVC, which incorrectly expands `__VA_ARGS__`.
//
// Examples:
//   `_PP_IF(_Exp)(_EvaluatedIfTrue)`
//   `_PP_IF_ELSE(_Exp)(_EvaluatedIfTrue)(_EvaluatedIfFalse)`
#define _PP_IF(_Exp) _PP_IF_INTERNAL(_PP_BOOL(_Exp))
#define _PP_IF_ELSE(_Exp) _PP_IF_ELSE_INTERNAL(_PP_BOOL(_Exp))

#define _PP_IF_INTERNAL(_Exp) _PP_CONCAT(_PP_IF_INTERNAL_,_Exp)
#define _PP_IF_INTERNAL_0(...)
#define _PP_IF_INTERNAL_1(...) __VA_ARGS__

#define _PP_IF_ELSE_INTERNAL(_Exp) _PP_CONCAT(_PP_IF_ELSE_INTERNAL_, _Exp)
#define _PP_IF_ELSE_INTERNAL_0(...) _PP_IF_ELSE_INTERNAL_ELSE_0
#define _PP_IF_ELSE_INTERNAL_1(...) __VA_ARGS__ _PP_IF_ELSE_INTERNAL_ELSE_1
#define _PP_IF_ELSE_INTERNAL_ELSE_0(...) __VA_ARGS__
#define _PP_IF_ELSE_INTERNAL_ELSE_1(...)

// Count the number of `__VA_ARGS__` arguments. Should work with C99 compilers
// and MSVC, not sure about others, maybe some fixes will be needed.
//
// Examples:
//   `_PP_COUNT_VA()`     -> `0`
//   `_PP_COUNT_VA(1)`    -> `1`
//   `_PP_COUNT_VA(1, 2)` -> `2`
#define _PP_COUNT_VA(...) _PP_INDIRECT(_PP_COUNT_VA_INTERNAL_0((_PP_DUMMY_VA(__VA_ARGS__),\
  63,62,61,60,59,58,57,56,\
  55,54,53,52,51,50,49,48,\
  47,46,45,44,43,42,41,40,\
  39,38,37,36,35,34,33,32,\
  31,30,29,28,27,26,25,24,\
  23,22,21,20,19,18,17,16,\
  15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0)))

#define _PP_COUNT_VA_INTERNAL_0(_X) _PP_INDIRECT(_PP_COUNT_VA_INTERNAL_1 _X)
#define _PP_COUNT_VA_INTERNAL_1(\
  _01,_02,_03,_04,_05,_06,_07,_08,\
  _09,_10,_11,_12,_13,_14,_15,_16,\
  _17,_18,_19,_20,_21,_22,_23,_24,\
  _25,_26,_27,_28,_29,_30,_31,_32,\
  _33,_34,_35,_36,_37,_38,_39,_40,\
  _41,_42,_43,_44,_45,_46,_47,_48,\
  _49,_50,_51,_52,_53,_54,_55,_56,\
  _57,_58,_59,_60,_61,_62,_63,_64,_X,...) _X

// Get whether the `...` contains one or more argument.
//
// Examples:
//   `_PP_HAS_VA()`     -> `0`
//   `_PP_HAS_VA(1)`    -> `1`
//   `_PP_HAS_VA(1, 2)` -> `1`
#define _PP_HAS_VA(...) _PP_INDIRECT(_PP_BOOL(_PP_COUNT_VA(__VA_ARGS__)))

// Expand to `, __VA_ARGS__` if `__VA_ARGS__` contains at least one argument,
// expands to `` otherwise. This is basically a workaround to having a dangling
// comma after `, __VA_ARGS__` expansion.
//
// Examples:
//   `_PP_COMMA_VA()`     -> ``
//   `_PP_COMMA_VA(A)`    -> `, A`
//   `_PP_COMMA_VA(A, B)` -> `, A, B`
#define _PP_COMMA_VA(...) _PP_IF(_PP_HAS_VA(__VA_ARGS__))(, __VA_ARGS__)

// Convert the given token(s) to a string form at a preprocessor time.
#define _PP_STRINGIFY(...) _PP_STRINGIFY_INTERNAL(__VA_ARGS__)
#define _PP_STRINGIFY_INTERNAL(...) _PP_INDIRECT(#__VA_ARGS__)
// ----------------------------------------------------------------------------

// [Guard]
#endif // _PP_MAGIC_H
