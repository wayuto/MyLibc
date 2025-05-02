# MyLibc

MyLibc is a lightweight implementation of the C Standard Library, designed to provide common C library functionalities. This project serves as a learning tool to understand the inner workings of the C Standard Library and as an experimental project.

## Project Structure

```
.
├── asm             # Assembly code for low-level functionalities
│   ├── file.asm    # Assembly functions for file operations
│   └── io.asm      # Assembly functions for basic input/output
├── include         # Header files for the C Standard Library
│   ├── convert.h   # Type conversion functions
│   ├── stdio.h     # Standard input/output functions
│   ├── string.h    # String manipulation functions
│   ├── stdbool.h   # Boolean type support
│   └── stdarg.h    # Variadic argument support
├── so              # Directory for shared library files
│   ├── libio.so    # Shared library for I/O operations
│   ├── libfile.so  # Shared library for file operations
├── wcc.c           # Custom wrapper for GCC compilation
├── setup.sh        # Setup script for environment variables and tool installation
└── main.c          # Example usage of MyLibc
```

## Features

### Assembly Implementations
- **file.asm**
  - `open`: Opens a file
  - `read`: Reads content from a file
  - `write`: Writes content to a file
  - `close`: Closes a file

- **io.asm**
  - `couts`: Outputs a string to standard output
  - `cins`: Reads a string from standard input
  - `exit`: Exits the program

### Standard Library Implementations
- **convert.h**
  - `itoa`: Converts an integer to a string
  - `ftoa`: Converts a floating-point number to a string
  - `atoi`: Converts a string to an integer
  - `atof`: Converts a string to a floating-point number

- **stdio.h**
  - `printf`: Formatted output function, supporting `%s`, `%d`, `%f`, and `%c`
  - `scanf`: Formatted input function, supporting `%s`, `%d`, and `%f`
  - File operation functions: `open`, `read`, `write`, `close`
  - `exit`: Exits the program

- **string.h**
  - `strlen`: Calculates the length of a string
  - `strcmp`: Compares two strings for equality
  - `strcpy`: Copies a string
  - `strcat`: Concatenates two strings
  - `strchr`: Finds the first occurrence of a character in a string
  - `strrchr`: Finds the last occurrence of a character in a string
  - `strstr`: Finds the first occurrence of a substring in a string

- **stdbool.h**
  - Provides boolean type `bool` and values `true` and `false`

- **stdarg.h**
  - Provides support for variadic arguments

### Custom Wrapper Compiler (`wcc`)
The `wcc` tool is a custom wrapper for `gcc`, simplifying the inclusion of the MyLibc headers and shared libraries during compilation.

#### How `wcc` Works
1. It reads the `LD_PATHS` environment variable to automatically include the directory containing the MyLibc header files.
2. It reads the `SO_PATHS` environment variable to link the required shared libraries.
3. Compiles the provided source files using `gcc` with these predefined paths.

### Example

Here's a simple example showcasing the usage of MyLibc:

```c
#include "include/stdio.h"
#include "include/string.h"

void main() {
    const char *filename = "hello.txt";
    char buffer[1024];
    ssize_t fd = open(filename, O_RDONLY, 0);
    ssize_t bytes_read = read(fd, buffer, sizeof buffer - 1);
    buffer[bytes_read] = '\0';

    strcat(buffer, "!");
    printf("%s\n", strrchr(buffer, 'H'));
    printf("There are %d characters.\n", strlen(buffer));

    close(fd);
    exit(0);
}
```

### Output

Assuming `hello.txt` contains the text `HHHHello, world`, the output of the program will be:

```
Hello, world!
There are 16 characters.
```

## Setup

1. Run the `setup.sh` script to configure the environment:
   ```bash
   ./setup.sh
   ```

   This will:
   - Set the environment variables `LD_PATHS` and `SO_PATHS` in your shell configuration files (`~/.zshrc` and/or `~/.bashrc`).
   - Compile the `wcc` tool.
   - Create a symbolic link for `wcc` in `/usr/bin`.

2. Reload your shell configuration:
   ```bash
   source ~/.zshrc  # For Zsh users
   source ~/.bashrc # For Bash users
   ```

## Building and Running with `wcc`

1. Use `wcc` to compile your program:
   ```bash
   wcc -o main main.c
   ```

   The `wcc` tool automatically includes the MyLibc headers and links the shared libraries specified in the `SO_PATHS` environment variable.

2. Run your program:
   ```bash
   ./main
   ```

## Contributions

Contributions are welcome! Feel free to submit issues or pull requests if you have suggestions or improvements.

## License

This project is licensed under the MIT License. For more details, see the [LICENSE](LICENSE) file.
