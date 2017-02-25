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

## Problem 2: add two (properly aligned)  arrays of floats