// [PPMagic]
// C/C++ Preprocessor Magic
//
// [License]
// Public Domain <http://unlicense.org>

// [Dependencies]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// [PPMagic]
#include "./ppmagic.h"

static int nFailures = 0;

static void expectInt(int a, int b) {
  if (a == b) {
    printf("[SUCCESS] %d == %d\n", a, b);
  }
  else {
    printf("[FAILURE] %d == %d\n", a, b);
    nFailures++;
  }
}

static void expectStr(const char* a, const char* b) {
  if (::strcmp(a, b) == 0) {
    printf("[SUCCESS] \"%s\" == \"%s\"\n", a, b);
  }
  else {
    printf("[FAILURE] \"%s\" == \"%s\"\n", a, b);
    nFailures++;
  }
}

int main(int argc, char* argv[]) {
  // --------------------------------------------------------------------------
  // [_PP_0..9]
  // --------------------------------------------------------------------------

  expectStr(_PP_STRINGIFY(_PP_1(A, B, C, D, E, F, G, H, I, J)), "A");
  expectStr(_PP_STRINGIFY(_PP_2(A, B, C, D, E, F, G, H, I, J)), "B");
  expectStr(_PP_STRINGIFY(_PP_3(A, B, C, D, E, F, G, H, I, J)), "C");
  expectStr(_PP_STRINGIFY(_PP_4(A, B, C, D, E, F, G, H, I, J)), "D");
  expectStr(_PP_STRINGIFY(_PP_5(A, B, C, D, E, F, G, H, I, J)), "E");
  expectStr(_PP_STRINGIFY(_PP_6(A, B, C, D, E, F, G, H, I, J)), "F");
  expectStr(_PP_STRINGIFY(_PP_7(A, B, C, D, E, F, G, H, I, J)), "G");
  expectStr(_PP_STRINGIFY(_PP_8(A, B, C, D, E, F, G, H, I, J)), "H");
  expectStr(_PP_STRINGIFY(_PP_9(A, B, C, D, E, F, G, H, I, J)), "I");

  // --------------------------------------------------------------------------
  // [_PP_DUMMY]
  // --------------------------------------------------------------------------

  expectStr(_PP_STRINGIFY(_PP_DUMMY())     , "dummy");
  expectStr(_PP_STRINGIFY(_PP_DUMMY(0))    , "dummy,0");
  expectStr(_PP_STRINGIFY(_PP_DUMMY(0,1))  , "dummy,0,1");
  expectStr(_PP_STRINGIFY(_PP_DUMMY(0,1,2)), "dummy,0,1,2");

  // --------------------------------------------------------------------------
  // [_PP_CONCAT]
  // --------------------------------------------------------------------------

  expectInt(_PP_CONCAT(0, 0), 0);
  expectInt(_PP_CONCAT(0, 10), 8); // 010 == 8 (Octal).
  expectInt(_PP_CONCAT(1, 2), 12);

  expectStr(_PP_STRINGIFY(_PP_CONCAT(0, 1)), "01");
  expectStr(_PP_STRINGIFY(_PP_CONCAT(A, B)), "AB");

  // --------------------------------------------------------------------------
  // [_PP_NOT]
  // --------------------------------------------------------------------------

  expectInt(_PP_NOT(0) , 1);
  expectInt(_PP_NOT(1) , 0);
  expectInt(_PP_NOT(42), 0);

  expectStr(_PP_STRINGIFY(_PP_NOT(0)) , "1");
  expectStr(_PP_STRINGIFY(_PP_NOT(1)) , "0");
  expectStr(_PP_STRINGIFY(_PP_NOT(42)), "0");

  // --------------------------------------------------------------------------
  // [_PP_BOOL]
  // --------------------------------------------------------------------------

  expectInt(_PP_BOOL(0) , 0);
  expectInt(_PP_BOOL(1) , 1);
  expectInt(_PP_BOOL(42), 1);

  expectStr(_PP_STRINGIFY(_PP_BOOL(0)) , "0");
  expectStr(_PP_STRINGIFY(_PP_BOOL(1)) , "1");
  expectStr(_PP_STRINGIFY(_PP_BOOL(42)), "1");

  // --------------------------------------------------------------------------
  // [_PP_IF_ELSE]
  // --------------------------------------------------------------------------

  expectInt(_PP_IF_ELSE(0)(1)(0), 0);
  expectInt(_PP_IF_ELSE(1)(1)(0), 1);
  expectInt(_PP_IF_ELSE(2)(1)(0), 1);

  expectStr(_PP_STRINGIFY(_PP_IF_ELSE(0)(True)(False)), "False");
  expectStr(_PP_STRINGIFY(_PP_IF_ELSE(1)(True)(False)), "True");
  expectStr(_PP_STRINGIFY(_PP_IF_ELSE(2)(True)(False)), "True");

  // --------------------------------------------------------------------------
  // [_PP_COUNT]
  // --------------------------------------------------------------------------

  expectInt(_PP_COUNT(), 0);
  expectInt(_PP_COUNT(0), 1);
  expectInt(_PP_COUNT(0, 1), 2);
  expectInt(_PP_COUNT(0, 1, 2), 3);

  expectStr(_PP_STRINGIFY(_PP_COUNT()), "0");
  expectStr(_PP_STRINGIFY(_PP_COUNT(0)), "1");
  expectStr(_PP_STRINGIFY(_PP_COUNT(0, 1)), "2");
  expectStr(_PP_STRINGIFY(_PP_COUNT(0, 1, 2)), "3");

  // --------------------------------------------------------------------------
  // [End]
  // --------------------------------------------------------------------------

  // Return `1` if there is a failure, for CI environments.
  if (nFailures == 0) {
    printf("[SUCCESS] All tests passed!\n");
    return 0;
  }
  else {
    printf("[FAILURE] %d tests failed!\n", nFailures);
    return 1;
  }
}
