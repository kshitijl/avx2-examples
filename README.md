# Short examples illustrating AVX2 intrinsics for simple tasks

I was surprised by the lack of simple examples showing how to use AVX
and AVX2 intrinsics. There doesn't seem to be a definitive book or
even tutorial on the subject.

O Internet, if I am wrong, please correct me! I've learned that the
best way to get information on the internet is not to ask a question,
but to post the wrong answer.

## Examples in Q&A format

So I'm setting myself homework problems and solving them as I go,
producing a set of examples. This will be a long and painful process
with many trips to the debugger and disassembler.

I will strive to keep the problems simple and the examples short, but
I can't promise that a simple problem won't have a complex solution.

I hope I end up with a collection of self-contained code snippets
that's useful to others. However, please remember that I am a beginner
in the use of CPU vector instructions. I'm not claiming this code is
exemplary.

## Other resources

Unfortunately, most of these resources are old. Others are raw
reference materials like Intel's instruction guides.

https://software.intel.com/en-us/articles/introduction-to-intel-advanced-vector-extensions/
https://software.intel.com/en-us/articles/benefits-of-intel-avx-for-small-matrices/
https://thinkingandcomputing.com/posts/using-avx-instructions-in-matrix-multiplication.html
https://www.codeproject.com/Articles/874396/Crunching-Numbers-with-AVX-and-AVX
https://software.intel.com/en-us/node/523876
https://www.cs.fsu.edu/~engelen/courses/HPC-adv/MMXandSSEexamples.txt
http://sci.tuomastonteri.fi/programming/sse
http://stackoverflow.com/questions/13577226/intel-sse-and-avx-examples-and-tutorials
http://supercomputingblog.com/optimization/getting-started-with-sse-programming/
https://felix.abecassis.me/2011/09/cpp-getting-started-with-sse/
http://www.walkingrandomly.com/?p=3378
https://software.intel.com/sites/landingpage/IntrinsicsGuide/

## Problem 0: get the code to compile and run

### Does my computer support AVX2?

Most CPUs sold in the last 3-4 years should support AVX2. To find out, run

`cat /proc/cpuinfo | grep avx2`

on Linux, or

`sysctl -a | grep AVX2`

on Mac. Sorry Windows friends, I don't write programs on Windows but I
would certainly appreciate a pull request that explains what to do.

### What header files do I need?

It seems that the right header to include is `immintrin.h`, which then
goes and includes individual headers like `avx2intrin.h`. On my
installation, I get errors about unknown types if I include
`avx2intrin.h` directly, as well as an error message saying "Never use
\<avx2intrin.h\> directly; include \<immintrin.h\> instead."

Okay, seems pretty clear.

### What compiler flags do I need?

The two platform combinations I develop on are `clang+Mac` and
`gcc+Linux`. On both of these, `-mavx2` does the right thing and I get
no errors or non-AVX2 instructions in the output assembly.

### Complete example

A complete compilation command looks like

`gcc foo.c -mavx2`

See `examples/00-compile.c` for a complete test program that should
compile if you have everything set up.

## Problem 1: add two 256-bit registers

So it begins! We will construct a vector value from 4 64-bit literals
and then add it to itself.

## Problem 2: add two (properly aligned) arrays of floats

Not only will we assume the input is correctly aligned, but also that
their lengths are multiples of 256 bits.

## Problem 3: add two arbitrary arrays of floats

Are there necessary restrictions on alignment with respect to each
other, or can we take any two arrays of float anywhere in memory?

## Problem 4: dot product

Let's add a reduction to the mix

## Problem 5: linear search through an array

I have seen it asserted online that brute force linear search can beat
binary search for arrays of size up to 10K. The calculations people
give to support this claim involve vector instructions. Let's try
writing a vectorized linear search.

## Problem 6: 4 or 8 square roots at a time

## Problem 7: scalar-vector multiplication

## Problem 8: matrix-vector multiplication

