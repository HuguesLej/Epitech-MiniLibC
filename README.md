# MinilibC - Going deeper into the rabbit hole

MinilibC is an {Epitech} 2nd year projet. It's part of the *x86-64 Assembly* module.

**⚠️ If you're an Epitech student, be aware that copying any part of this code is considered cheating and would cause an -42!**

## Purpose

The purpose of this project is to create a dynamic library to replace some functions of the standard C library. The functions must be recreated with the exact behavior described in the respective man pages of the original functions.

Here are the functions that must be implemented in the library:
- strlen
- strchr
- strrchr
- memset
- memcpy
- strcmp
- memmove
- strncmp
- strcasecmp
- strstr
- strpbrk
- strcspn

In addition to the required functions, the following functions can be implemented as a bonus:
- ffs
- syscall
- strfry
- index
- rindex
- strtok
- memfrob
- etc

## Tests results

<table>
    <thead>
        <tr>
            <th>Name</th>
            <th>Percentage</th>
            <th>Tests</th>
            <th>Crash ?</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>Preliminaries</td>
            <td>100%</td>
            <td>2/2</td>
            <td>No</td>
        </tr>
        <tr>
            <td>Base functions - strlen</td>
            <td>100%</td>
            <td>3/3</td>
            <td>No</td>
        </tr>
        <tr>
            <td>Base functions - strchr</td>
            <td>100%</td>
            <td>6/6</td>
            <td>No</td>
        </tr>
        <tr>
            <td>Base functions - memset</td>
            <td>100%</td>
            <td>3/3</td>
            <td>No</td>
        </tr>
        <tr>
            <td>Base functions - memcpy</td>
            <td>100%</td>
            <td>5/5</td>
            <td>No</td>
        </tr>
        <tr>
            <td>Base functions - strcmp</td>
            <td>100%</td>
            <td>10/10</td>
            <td>No</td>
        </tr>
        <tr>
            <td>Base functions - memmove</td>
            <td>100%</td>
            <td>7/7</td>
            <td>No</td>
        </tr>
        <tr>
            <td>Comparison functions - strncmp</td>
            <td>100%</td>
            <td>10/10</td>
            <td>No</td>
        </tr>
        <tr>
            <td>Comparison functions - strcasecmp</td>
            <td>100%</td>
            <td>16/16</td>
            <td>No</td>
        </tr>
        <tr>
            <td>Comparison functions - strrchr</td>
            <td>100%</td>
            <td>9/9</td>
            <td>No</td>
        </tr>
        <tr>
            <td>Search functions - strstr</td>
            <td>100%</td>
            <td>10/10</td>
            <td>No</td>
        </tr>
        <tr>
            <td>Search functions - strpbrk</td>
            <td>100%</td>
            <td>8/8</td>
            <td>No</td>
        </tr>
        <tr>
            <td>Search functions - strcspn</td>
            <td>100%</td>
            <td>8/8</td>
            <td>No</td>
        </tr>
        <tr>
            <th>Total (without bonus)</th>
            <th>100%</th>
            <th>97/97</th>
            <th>No</th>
        </tr>
        <tr>
            <td>Boni Functions - ffs</td>
            <td>100%</td>
            <td>5/5</td>
            <td>No</th>
        </tr>
        <tr>
            <td>Boni Functions - index/rindex</td>
            <td>0%</td>
            <td>0/2</td>
            <td>No</th>
        </tr>
        <tr>
            <td>Boni Functions - strfry</td>
            <td>0%</td>
            <td>0/3</td>
            <td>No</th>
        </tr>
        <tr>
            <td>Boni Functions - memfrob</td>
            <td>0%</td>
            <td>0/3</td>
            <td>No</th>
        </tr>
        <tr>
            <td>Boni Functions - syscall</td>
            <td>0%</td>
            <td>0/1</td>
            <td>No</th>
        </tr>
    </tbody>
    <tfoot>
        <tr>
            <th>Total</th>
            <th>92%</th>
            <th>102/111</th>
            <th>No</th>
        </tr>
    </tfoot>
</table>

## How to use

### Requirements

To use this program, you need to install some tools:
- [nasm](https://www.nasm.us/)
- [GNU Binutils](https://www.gnu.org/software/binutils/)
- [GCC](https://gcc.gnu.org/)
- [GNU Make](https://www.gnu.org/software/make/)
- [Criterion](https://criterion.readthedocs.io/en/master/setup.html) (only if you want to run the unit tests)

### Usage

To compile the library, run:
```sh
make
```

To clean the build files, run:
```sh
make clean
```

To run the unit tests, run:
```sh
make tests_run
```

There are several ways to use the library in your own projects. Here is one of them:

1. Set the `LD_LIBRARY_PATH` environment variable to include the directory where the compiled library is located. This allows the dynamic linker to find the library at runtime.

```sh
export LD_LIBRARY_PATH=/path/to/library:$LD_LIBRARY_PATH
```

2. Specify the library at compilation time when compiling your project. Use the `-L` option to specify the directory containing the library and the `-l` option to specify the library name (without the `lib` prefix and `.so` suffix).

```sh
gcc -L/path/to/library -llibrary -o yourprogram yourprogram.c
```

Replace `/path/to/library` with the actual path to the directory containing the compiled library, `library` with the name of the library, and `yourprogram.c` with the source file of your project.
