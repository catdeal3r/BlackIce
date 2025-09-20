# SCreate - A simpler alternative to make

SCreate is a simple alternative to `make` with intensionally less features.

It is designed to purely compile c and c++ code with gcc and g++ (however I am open to adding support for more languages in the future).

## Why?

I created this project because:
- I was frustrated with the complexity of cmake/make.
- I wanted something that could compile object files like cmake/make does to reduce compile times, which is something that a shell script would make annoying to implement.
- Finally, for the learning value.

## Pros and Cons

Upsides:
- It is written in C++.
- Relatively fast.
- Simple to configure (configuration file uses a toml-like syntax).
- No extra libraries are needed; everything uses the c++ standard library.
- Pretty robust parsing system.

Downsides:
- It is written in C++.
- Not as powerful as make.
- Doesn't currently support dynamic content in the `scfile`.
- All strings in the `scfile` can NOT contain double quotes (`"`).
- Is very much is beta, and therefore is pretty unusable.


## Installation and Usage
Wait until I'm finished.
