/* Construct a 256-bit vector from 4 64-bit doubles. Add it to itself
 * and print the result.
 */

#include <stdio.h>
#include <immintrin.h>
#include <avx2intrin.h>

int main() {
  // Construction from scalars or literals.
  __m256d a = _mm256_set_pd(1.0, 2.0, 3.0, 4.0);

  // Does GCC generate the correct mov, or (better yet) elide the copy
  // and pass two of the same register into the add? Let's look at the assembly.
  __m256d b = a;

  // Add the two vectors, interpreting the bits as 4 double-precision
  // floats.
  __m256d c = _mm256_add_pd(a, b);

  // Do we ever touch DRAM or will these four be registers?
  __attribute__ ((aligned (32))) double output[4];
  _mm256_store_pd(output, c);

  printf("%f %f %f %f\n",
         output[0], output[1], output[2], output[3]);
  return 0;
}
