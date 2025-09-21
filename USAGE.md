# Usage

This markdown file details how to use `scr` (the command provided by SCReate).

## Commandline Options:
- `--test-parse`
Test parsing of the `scrfile` file.
- `--test-metadata [FILE]`
Test checking of time metadata for passed `[FILE]`.
- `--reset-cache`
Clear `.scrcache` file before recompiling (useful for linking errors between switching compilers).

## `scrfile` Options:
- `compiler`
**Type**: String
**Optional**: False
**Description**: The compiler to use. Currently only supports `g++` and `gcc`.
- `files`
**Type**: Array
**Optional**: False
**Description**: An array of paths pointing to files to be compiled.
- `compiler_options`
**Type**: String
**Optional**: True
**Description**: A string that is passed to the compiler
- `output_file`
**Type**" String
**Optional**: False
**Description**: The path of the output file.

## Parsing Specifications:
- String
**Examples**:
```
"This is a string"
"Another one: @#$%^&*5432345678:{>}"
```

Can contain anything but a double quote (`"`).

- Array
**Examples**:
```
"This" "is" "an" "array"
"So", "is", "this"
[ "And, "this", "!" ]
```

Can have anything outside of the double quotes. Same restrictions as a string for each array 'object'.