*This project has been created as part of the 42 curriculum by seraydin.*

# Get Next Line

## Description

Get Next Line is a C function that reads one line at a time from a file descriptor. Each returned line includes its terminating newline when one is present. The project focuses on file-descriptor I/O, dynamic memory management, and preserving unread data between function calls with a static variable.

The bonus implementation supports interleaved reading from multiple file descriptors.

## Instructions

Compile the mandatory files with a test program containing a `main` function:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c test.c
```

For the bonus implementation:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c test.c
```

`BUFFER_SIZE` may be changed or omitted; the header provides a default value. The caller owns every returned line and must free it. Repeated calls return successive lines until `NULL` indicates EOF or an error.

## Algorithm

A static pointer stores text that has been read but not yet returned. On each call, chunks of `BUFFER_SIZE` bytes are appended until a newline is found or `read` reaches EOF. The function then allocates the next line, keeps any characters after the newline for the following call, and frees buffers that are no longer needed.

This approach was chosen because it stops reading once enough data for one line is available while still handling lines larger than `BUFFER_SIZE`. The bonus uses one static array indexed by file descriptor so each descriptor keeps an independent remainder.

## Resources

- `read(2)` and `malloc(3)` manual pages
- The C documentation for pointers, static storage duration, and dynamic allocation
- The official 42 Get Next Line subject

AI was used to explain the buffer/stash design, suggest parts of the reading and bonus adaptations, review memory ownership and subject compliance, and design tests. The author integrated, revised, and verified the implementation.
