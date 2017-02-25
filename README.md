# Short examples illustrating AVX2 intrinsics for simple tasks

I was surprised to find a lack of simple examples using AVX and AVX2
instructions for beginners. There doesn't seem to be a definite book
or even a tutorial on the subject.

O Internet, if I am wrong, please correct me! I've learned that the
best way to get information on the internet is not to ask a question,
but to post the wrong answer.

## I'm learning as I go

So I'm writing my own homework problems and solving them as I go,
producing a set of examples in the process. This will be a long and
painful process with many trips to the debugger and disassembler.

I will strive to keep the problems simple and the examples short, but
I can't promise that a simple problem won't have a complex solution.

I hope the examples I end up with will be useful to others looking for
a collection of self-contained code snippets. However, please remember
that I am a beginner in the use of CPU vector instructions. I'm not
claiming this code is exemplary.

## Problem 1: add two 256-bit registers

So it begins! We will construct a vector value from 4 64-bit literals
and then add it to itself.

## Problem 2: add two (properly aligned)  arrays of floats