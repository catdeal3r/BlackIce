# SCReate - A simpler alternative to make

SCReate is a simple alternative to `make` with intensionally less features.

It is designed to purely compile C and C++ code with gcc and g++ (however I am open to adding support for more languages in the future).

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
- Doesn't currently support dynamic content in the `scrfile`.
- All strings in the `scrfile` can NOT contain double quotes (`"`).
- Is very much is beta, and therefore is pretty unusable.


## Installation
~~Wait until I'm finished.~~ 

> [!Warning]
> Use at your own risk. This project is far from complete and may change drastically.

Assuming you have both `gcc` and `g++` installed on your system correctly, run:
```bash
chmod +x ./compile.sh
./compile.sh
```

or

```bash
chmod +x ./compile.sh
./compile.sh install
```

To install it to `/usr/bin` as well.


## Roadmap

- [x] Implement parsing system.
- [x] Setup support for multiple files, custom compiler, and compiler flags.
- [x] Detect whether a file has been added or been modified.
- [x] Implement basic compiling support for C++.
- [x] Custom output file name.
- [x] Use compiler flags properly and error check.
- [x] Create cache file if not already created.
- [ ] Fully support C.
- [ ] Multiple targets for different compiles.
- [ ] Run commands after completion.
- [ ] `git push` after successful compile.
- [ ] Debug option.
