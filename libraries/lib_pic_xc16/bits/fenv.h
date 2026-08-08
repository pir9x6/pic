#define FE_INVALID    1
#define FE_DIVBYZERO  2
#define FE_OVERFLOW   4
#define FE_UNDERFLOW  8
#define FE_INEXACT    16
#define FE_HUGEINT    32
#define FE_SUBNORMAL  64

#define FE_ALL_EXCEPT 127

#define FE_TONEAREST  0
#define FE_TOWARDZERO 0x100
#define FE_UPWARD     0x200
#define FE_DOWNWARD   0x300

#include <stdint.h>

typedef uint32_t fexcept_t;

typedef struct {
  uint32_t __control_word;
  uint32_t __status_word;
  uint32_t __fear_word;
} fenv_t;

#define FE_DFL_ENV      ((const fenv_t *) -1)
