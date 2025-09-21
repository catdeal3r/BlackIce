# Usage

This markdown file details how to use `scr` (the command provided by SCReate).

## Commandline Options:
- `--test-parse`:<br>
Test parsing of the `scrfile` file.<br><br>

- `--test-metadata [FILE]`:<br>
Test checking of time metadata for passed `[FILE]`.<br><br>

- `--reset-cache`:<br>
Clear `.scrcache` file before recompiling (useful for linking errors between switching compilers).<br>

## `scrfile` Options:
- `compiler`:<br>
**Type**: String<br>
**Optional**: False<br>
**Description**: The compiler to use. Currently only supports `g++` and `gcc`.<br><br>

- `files`:<br>
**Type**: Array<br>
**Optional**: False<br>
**Description**: An array of paths pointing to files to be compiled.<br><br>

- `compiler_options`:
**Type**: String<br>
**Optional**: True<br>
**Description**: A string that is passed to the compiler<br><br>

- `output_file`:<br>
**Type**" String<br>
**Optional**: False<br>
**Description**: The path of the output file.<br>

## Parsing Specifications:
- String:<br>
**Examples**:
```
"This is a string"
"Another one: @#$%^&*5432345678:{>}"
```

**Explanation**:<br>
Can contain anything but a double quote (`"`).

- Array:<br>
**Examples**:
```
"This" "is" "an" "array"
"So", "is", "this"
[ "And, "this", "!" ]
```

**Explanation**:<br>
Can have anything outside of the double quotes. Same restrictions as a string for each array 'object'.