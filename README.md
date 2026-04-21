_This project has been created as part of the 42 curriculum by mbuchet._

## Description
**ft_printf** is a simplified reimplementation of the C function **printf**.  
Its goal is to better understand:
- format string parsing,
- variadic arguments (`stdarg.h`),
- formatted output in C.

Reference:
- https://man7.org/linux/man-pages/man3/printf.3.html

## Instructions

### Build
From the root of the repository, run:
- `make`

This generates:
- `libftprintf.a`

### Clean / Rebuild
- `make fclean` (remove generated files)
- `make re` (rebuild from scratch)

Tested on **Ubuntu** (42 Brussels environment).

## Algorithm and data structure (explanation + justification)

### Algorithm (parsing / dispatch)
The format string is processed in a **single pass** from left to right:
- regular characters are printed as-is,
- when a `%` is encountered (and the next character exists), the next character is treated as a specifier and handled by a dispatcher.

**Why this approach?**
- It is simple, efficient (linear complexity), and easy to debug.
- It makes it easy to extend the project by adding new specifiers in one place (the dispatcher).

### Data structures
This project does not rely on complex data structures.
The implementation mainly uses:
- an index to iterate through the format string,
- a `va_list` to access variadic arguments,
- a `size_t` counter (`size_t *str_length`) shared across helper functions to track the number of printed characters.

**Why `size_t *str_length`?**
- It matches the purpose of counting bytes/characters printed.
- Passing it by pointer allows every helper to update the total without additional return values, keeping function responsibilities clear.

## How it works (overview)

### Supported specifiers (dispatch + internal functions)
Based on `handle_specifier`, these specifiers are handled:

- `%c` → `print_char(int c, size_t *str_length)`
- `%s` → `print_string(char *str, size_t *str_length)`
- `%d` / `%i` → `print_number(int number, size_t *str_length)`
- `%u` → `print_number_unsigned(unsigned int number, size_t *str_length)`
- `%x` → `print_hexadecimal(unsigned int number, int is_upper, size_t *str_length)` with `is_upper = 0`
- `%X` → `print_hexadecimal(unsigned int number, int is_upper, size_t *str_length)` with `is_upper = 1`
- `%p` → `print_pointer(uintptr_t pointer, size_t *str_length)`
- any other character after `%` → prints a literal `%` using `print_char('%', str_length)`

### Helper files (short summary)
- `print_digits`: integer / unsigned / hexadecimal helpers
- `print_pointer`: pointer printing helper
- `print_str`: character and string helpers

### Counting printed characters
Most helper functions receive a `size_t *str_length` pointer to keep track of how many characters were written, so `ft_printf` can return the total (like the real `printf`).

## Resources (references + AI usage)

### References
- 42 subject PDF (ft_printf, version 12.1, 42 Brussels)
- `printf(3)` manual: https://man7.org/linux/man-pages/man3/printf.3.html
- `uintptr_t` explanation: https://stackoverflow.com/questions/1845482/what-is-the-uintptr-t-data-type
- Parts of my old Libft codebase (as references)

### AI usage
AI was used only for debugging help, specifically on the **hexadecimal printing** part of the project (e.g. edge cases and letter casing for `%x`/`%X`).  
I requested explanations and hints **without requesting code**, and then implemented the fixes myself.
This README was translated from French to English.