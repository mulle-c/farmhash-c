#ifndef LARGE_INT_H
#define LARGE_INT_H 1

#include <stdint.h>


// (nat) the original uint128_t was bound to clash with some other struct
//       sooner or later, and now it happened with cosmopolitan
struct fh_uint128_t {
  uint64_t a;
  uint64_t b;
};

typedef struct fh_uint128_t fh_uint128_t;

static inline uint64_t fh_uint128_t_low64(const fh_uint128_t x) { return x.a; }
static inline uint64_t fh_uint128_t_high64(const fh_uint128_t x) { return x.b; }

static inline fh_uint128_t make_fh_uint128_t(uint64_t lo, uint64_t hi)
{
  fh_uint128_t x = {lo, hi};
  return x;
}


// conditionally include declarations for versions of city that require SSE4.2
// instructions to be available
#if defined(__SSE4_2__) && defined(__x86_64)

struct fh_uint256_t {
  uint64_t a;
  uint64_t b;
  uint64_t c;
  uint64_t d;
};

typedef struct fh_uint256_t fh_uint256_t;

#endif

#endif
