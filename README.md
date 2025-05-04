# MyLibc

MyLibc is a lightweight implementation of the C Standard Library, designed to provide common C library functionalities. This project serves as a learning tool to understand the inner workings of the C Standard Library and as an experimental project.

## Project Structure

```
.
├── asm             # Assembly code for low-level functionalities
│   ├── file.asm    # Assembly functions for file operations
│   ├── io.asm      # Assembly functions for basic input/output
│   ├── malloc.asm  # Assembly functions for memory allocation
│   └── syscall.asm # Assembly functions for system calls
├── include         # Header files for the C Standard Library
│   ├── convert.h   # Type conversion functions
│   ├── malloc.h    # Memory allocation functions
│   ├── math.h      # Mathematical functions and constants
│   ├── stdio.h     # Standard input/output functions
│   ├── string.h    # String manipulation functions
│   ├── stdbool.h   # Boolean type support
│   ├── stdarg.h    # Variadic argument support
│   ├── stddef.h    # Common macros and typedefs
│   └── stdlib.h    # Environment variable and utility functions
├── so              # Directory for shared library files
│   ├── libio.so    # Shared library for I/O operations
│   ├── libfile.so  # Shared library for file operations
├── wcc.c           # Custom wrapper for GCC compilation
├── main.c          # Example usage of MyLibc
└── setup.sh        # Setup script for environment variables and tool installation
```

## Features

### Low-Level Assembly Functions (`asm`)
The `asm` directory contains assembly files for low-level functionalities:
- **`file.asm`**: Implements file operations like `open`, `read`, `write`, and `close`.
- **`io.asm`**: Provides basic input/output functions like `couts` and `cins`.
- **`malloc.asm`**: Implements memory allocation functions for efficient low-level memory management.
    - Provides assembly-level implementations of `malloc`, `free`, and `realloc`.
    - Achieves memory allocation by interacting with system calls like `brk` or `sbrk`.
- **`syscall.asm`**: Provides wrappers for Linux system calls to interact directly with the kernel.
    - Includes common system calls like `exit`, `write`, and `read`, allowing the library to interface directly with system-level operations.

...

### Memory Allocation (`malloc.asm` and `malloc.h`)
Implements low-level memory allocation using system calls like `sbrk`:
- **`malloc(size_t size)`**: Allocates memory dynamically.
- **`free(void *ptr)`**: Frees allocated memory.
- **`realloc(void *ptr, size_t size)`**: Resizes an existing block of memory.
- Implements block splitting and coalescing for efficient memory usage.

### System Calls (`syscall.asm`)
Provides wrappers for common Linux system calls:
- **`exit(int code)`**: Terminates the program.
- **`write(int fd, const void *buf, size_t count)`**: Writes to a file descriptor.
- **`read(int fd, void *buf, size_t count)`**: Reads from a file descriptor.
- **`open(const char *path, int flags, int mode)`**: Opens a file.
- **`close(int fd)`**: Closes a file.

...

## Example

Here's a simple example showcasing the usage of MyLibc:

```c
#include "include/stdio.h"

int main(int *argc, char **argv) {
    printf("Hello, MyLibc!");
    return 0;
}
```

### Output
`gcc main.c && ./a.out`
```
Hello, MyLibc!
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