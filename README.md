*This project has been created as part of the 42 curriculum by demane.*

# Fract'ol

A graphical fractal explorer written in C, using MiniLibX.

## Description

**Fract'ol** is a 42 project whose goal is to discover complex numbers, iterative algorithms, and graphical programming through the rendering of fractal sets.

The program opens a window and draws one of the supported fractals pixel by pixel. Each pixel is mapped to a point in the complex plane; the color depends on how quickly the associated sequence escapes a given bound (or whether it remains bounded).

Supported fractals:

| Fractal | Description |
| --- | --- |
| **Mandelbrot** | Classic set defined by \(z_{n+1} = z_n^2 + c\), with \(z_0 = 0\) |
| **Julia** | Same formula, but with a fixed complex constant \(c\) given as program arguments |
| **Burning Ship** | Variant using absolute values on the real and imaginary parts at each iteration |

The project also covers event handling (keyboard / mouse), view navigation (zoom, move, reset), and color palettes with smooth interpolation.

## Features

- Rendering of Mandelbrot, Julia, and Burning Ship
- Zoom centered on the mouse cursor (scroll wheel)
- Dynamic iteration depth while zooming
- Keyboard navigation (arrow keys) and view reset
- Several switchable color palettes
- Double-buffering via MiniLibX images
- Argument validation with a clear usage message

## Instructions

### Requirements

- A Unix-like environment (Linux recommended; developed for 42 clusters)
- `gcc` / `cc` and `make`
- X11 development libraries (`libx11`, `libxext`)
- Math library (`libm`)

On Debian/Ubuntu-like systems, you may need:

```bash
sudo apt update
sudo apt install build-essential xorg libxext-dev libbsd-dev
```

### Compilation

From the project root:

```bash
make
```

This builds:

1. `libft/libft.a` — personal C library
2. `mlx_lib/libmlx_Linux.a` — MiniLibX
3. the `fractol` executable

Other Makefile rules:

| Rule | Action |
| --- | --- |
| `make` / `make all` | Compile the project |
| `make clean` | Remove object files |
| `make fclean` | Remove objects and the executable |
| `make re` | Full rebuild (`fclean` then `all`) |

### Execution

```bash
./fractol mandelbrot
./fractol burning_ship
./fractol julia <re> <im>
```

Examples for Julia:

```bash
./fractol julia -0.8 0.156
./fractol julia -0.4 0.6
./fractol julia 0.285 0.01
```

If arguments are missing or invalid, the program prints the accepted parameters and exits.

### Controls

| Input | Action |
| --- | --- |
| Mouse scroll up | Zoom in (at cursor) |
| Mouse scroll down | Zoom out (at cursor) |
| Arrow keys | Move the view |
| `n` / `k` / `l` / `m` | Switch color palette |
| `r` | Reset the view |
| `ESC` / window close | Quit |

## Library — Libft

This project embeds a custom static library: **libft** (`libft/libft.a`).

Libft is a personal reimplementation of common C standard-library helpers, extended over the curriculum (including `ft_printf` and `get_next_line`). In Fract'ol it is used for string comparison, length helpers, formatted output, and related utilities.

### What it provides

- **Character checks / case**: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`
- **Memory**: `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
- **Strings**: `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, …
- **Conversions / I/O**: `ft_atoi`, `ft_atol`, `ft_itoa`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`, …
- **Linked lists (bonus-style API)**: `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstsize`, `ft_lstlast`, `ft_lstclear`, …
- **Extensions used by this project**:
  - `ft_printf` — formatted printing (usage / help messages)
  - `get_next_line` — line reading from a file descriptor
  - helpers such as `ft_free`, `ft_intlen`, `ft_maxint`, `ft_minint`

### Build

Libft is built automatically by the root Makefile via:

```bash
make --directory=libft
```

You can also build it alone from `libft/`.

## Project structure

```text
fractol/
├── main.c                 # Entry point and argument parsing
├── includes/fractol.h     # Structures and prototypes
├── fractals/              # Mandelbrot, Julia, Burning Ship
├── math/                  # Complex numbers, mapping, math helpers
├── render/                # Rendering, colors, zoom, move, reset
├── events/                # Keyboard and mouse hooks
├── mlx/                   # MiniLibX init / draw / destroy wrappers
├── utils/                 # Parsing helpers, free, exit, usage
├── libft/                 # Custom C library
└── mlx_lib/               # MiniLibX (Linux)
```

## Technical notes

- Window size: **1000 × 800**
- Each pixel is converted from screen coordinates to a complex number in the current view
- Escape radius is based on the modulus of the iterated complex value
- Colors are interpolated across palette stops according to the normalized iteration count
- Zoom updates the view bounds around the mouse position and adjusts `max_iteration`

## Resources

### Documentation & tutorials

- [MiniLibX documentation (42 / wiki style)](https://harm-smits.github.io/42docs/libs/minilibx)
- [Mandelbrot set — Wikipedia](https://en.wikipedia.org/wiki/Mandelbrot_set)
- [Julia set — Wikipedia](https://en.wikipedia.org/wiki/Julia_set)
- [Burning Ship fractal — Wikipedia](https://en.wikipedia.org/wiki/Burning_Ship_fractal)
- [Complex numbers refresher](https://betterexplained.com/articles/a-visual-intuitive-guide-to-imaginary-numbers/)
- Classic references on escape-time fractals and coloring techniques (smooth coloring / palette interpolation)

### How AI was used

AI assistance (Cursor) was used to:

- Draft and structure this `README.md` according to the Chapter V requirements
- Clarify wording for description, instructions, library overview, and resource links

AI was **not** used as a substitute for understanding the mathematical core of the fractals or for blindly generating the whole codebase. Project code, algorithms, and design choices remain under the author’s responsibility. Adjust this paragraph if you used AI for additional tasks (debugging, refactoring, etc.).

## Author

**demane** — 42 Paris
