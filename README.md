# CPP-Modules

A collection of all C++ modules from the 42 curriculum (Modules 00–09).

Each module is self-contained and focuses on a specific set of C++ concepts, from basic syntax to advanced OOP, templates, and STL.

## Project Structure

- `CPP00` – Basics of C++: I/O, strings, simple classes
  - `ex00` – Megaphone (simple command-line I/O)
  - `ex01` – PhoneBook (basic class, arrays, simple REPL)
  - `ex02` – Bank Account (static members, logging)

- `CPP01` – Memory allocation & references
  - `ex00` – Zombies on the stack/heap
  - `ex01` – Zombies horde (arrays & dynamic allocation)
  - `ex02` – Pointers, references, and memory
  - `ex03` – Weapons & Humans (aggregation, references)
  - `ex04` – File replacer (basic file I/O, strings)
  - `ex05` / `ex06` – Harl (switch-like behavior, function pointers)

- `CPP02` – Fixed-point numbers & operator overloading
  - `ex00` – Basic `Fixed` class
  - `ex01` – Arithmetic operators
  - `ex02` – Comparison, increment/decrement, min/max
  - `ex03` – BSP (point-in-triangle algorithm)

- `CPP03` – Inheritance & canonical form
  - `ex00` – `ClapTrap`
  - `ex01` – `ScavTrap` (simple inheritance)
  - `ex02` – `FragTrap` + multiple derived classes
  - `ex03` – `DiamondTrap` (diamond inheritance)

- `CPP04` – Sub-typing, abstract classes, deep copies
  - `ex00` – Animals vs WrongAnimals (virtual vs non-virtual)
  - `ex01` – Brain (deep copy, Rule of Three)
  - `ex02` – Abstract `Animal`
  - `ex03` – Materia system (interfaces, polymorphism)

- `CPP05` – Exceptions & bureaucrats
  - `ex00` – `Bureaucrat` (grades, exceptions)
  - `ex01` – `Form` signed by `Bureaucrat`
  - `ex02` – Various `AForm` derivatives
  - `ex03` – `Intern` that creates forms

- `CPP06` – Casting
  - `ex00` – Scalar converter (string to char/int/float/double)
  - `ex01` – Serialization of a simple `Data` struct
  - `ex02` – RTTI & `dynamic_cast` with `Base` / `A` / `B` / `C`

- `CPP07` – Templates
  - `ex00` – `whatever.hpp` (`swap`, `min`, `max` templates)
  - `ex01` – `iter` template
  - `ex02` – `Array` template class

- `CPP08` – STL & algorithms
  - `ex00` – `easyfind` (generic search in containers)
  - `ex01` – `Span` (range of integers, shortest/longest span)
  - `ex02` – `MutantStack` (stack with iterators)

- `CPP09` – Containers, algorithms, and parsing
  - `ex00` – `BitcoinExchange` (map-like storage, file parsing)
  - `ex01` – `RPN` (Reverse Polish Notation calculator)
  - `ex02` – `PmergeMe` (performance comparison of merge-insert sort on `std::vector` and `std::deque` using Jacobsthal sequence and binary insertion)

## Requirements

- Compiler: `c++` (or `clang++`/`g++`) with C++98 standard
- `make`
- Standard C++ library; no external dependencies.

## Building

Each exercise has its own `Makefile`. To build a specific exercise:

```sh
cd CPP0X/exYY
make        # builds the default target (usually the exercise binary)
```

Common clean targets (if provided):

```sh
make clean      # remove object files
make fclean     # remove objects and binaries
make re         # full rebuild
```

## Running

After building, run the produced binary from the exercise directory. For example:

```sh
cd CPP00/ex00
make
./megaphone "hello world"
```

Or for the last module:

```sh
cd CPP09/ex02
make
./PmergeMe 3 5 9 7 4 2 8
```

Refer to each exercise's `main.cpp` or subject PDF for detailed usage and expected behavior.
