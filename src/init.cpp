#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

SEXP test();

static const R_CallMethodDef CallEntries[] = {
  {"test_c", (DL_FUNC) &test, 0},
  {NULL, NULL, 0}
};

extern "C" void R_init_shader(DllInfo *dll) {
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}
