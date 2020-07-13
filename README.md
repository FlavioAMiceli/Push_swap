# push_swap
Project about sorting algorithms on stacks with limited available operations.

### TOC
* [What is push_swap?](#what-is-push_swap?)
* [What's in it?](#whats-in-it)
* [Installation](#installation)

### What is push_swap?
This project contains two programs.
One sorts a stack in a way optimized for number of operations.
The other is the checker program, to see if a sequence of operations sorts a given tab of integers.

At [Codam][1] we are generally not allowed to use code that we haven't written ourselves.
This means that for most projects we are only allowed read(), write(), malloc() and free() from libc, and our own [libft library][2].

### What's in it?

This project needs to conform to the [push_swap project][3].
My implementation is based on quick sort. The basecase is hardcoded, but I also started on a heuristic basecase that I might yet finish.

### Installation
This project is installed using the included makefile.

[1]: https://www.codam.nl/
[2]: https://github.com/FlavioAMiceli/libft
[3]: https://cdn.intra.42.fr/pdf/pdf/4744/push_swap.en.pdf
