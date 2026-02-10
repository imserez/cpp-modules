# C++ Modules: Object-Oriented Systems Programming

![Language](https://img.shields.io/badge/Language-C%2B%2B98-00599C.svg)
![Topic](https://img.shields.io/badge/Topic-OOP_%26_STL-orange.svg)

## 📖 Overview

The **C++ Modules** are a comprehensive series of projects designed to bridge the gap between imperative C programming and **Object-Oriented Programming (OOP)**.

This modules provides key understanding about how high-level abstractions map to system resources. It enforces strict adherence to the **C++98 standard**, requiring a deep understanding of memory management before modern "smart pointers" existed.

The journey covers everything from basic encapsulation to complex template metaprogramming and algorithmic efficiency using the Standard Template Library (STL).

## 🛠 Technical Concepts

The modules are structured to progressively introduce core architectural concepts:

* **RAII (Resource Acquisition Is Initialization):** Tying resource lifecycle (memory, file handles) to object scope, ensuring leak-free code without garbage collection.
* **Orthodox Canonical Form:** Strict adherence to the "Rule of Three" (Destructor, Copy Constructor, Copy Assignment Operator) to manage deep vs. shallow copying.
* **Polymorphism & V-Tables:** Implementing runtime polymorphism through virtual functions and understanding the underlying mechanism used by the compiler.
* **Templating:** Writing generic code that is type-safe and evaluated at compile-time.

## 📚 Modules Breakdown

| Module | Key Concepts | Systems Focus |
| :--- | :--- | :--- |
| **CPP 00** | Namespaces, Streams, Class Basics | Avoiding naming collisions, standard I/O redirection. |
| **CPP 01** | Memory Allocation, Pointers vs References | Heap (`new`/`delete`) vs Stack allocation, memory layout. |
| **CPP 02** | Ad-hoc Polymorphism, Operator Overloading | Fixed-point arithmetic implementation. |
| **CPP 03** | Inheritance | Code reuse and memory layout of derived classes. |
| **CPP 04** | Subtype Polymorphism, Abstract Classes | Virtual destructors, deep copies, Interface design. |
| **CPP 05** | Exceptions (Try/Catch) | Stack unwinding, error propagation, rigidity of implementation. |
| **CPP 06** | Serialization & Casting | `reinterpret_cast` (bit manipulation), `dynamic_cast` (RTTI). |
| **CPP 07** | Templates | Generic programming, separating interface from implementation in headers. |
| **CPP 08** | STL Containers & Iterators | Vector, List, Deque, Map efficiency and algorithmic complexity. |
| **CPP 09** | **Bitcoin, RPN, Ford-Johnson Algorithm** | Advanced STL usage, CSV parsing, and optimization algorithms. |

## 🚀 Usage

Each module is contained in its own directory and includes a standard `Makefile`.

### 1. Compilation
The projects adhere to the C++98 standard. To compile any exercise:

```bash
cd cpp0X/ex0Y
make
```

### 2. Execution Example 

```bash
./ex0Y "possible params"
> 42
```

## 📋 Coding Guidelines

Strict adherence to the **42 Norm** and C++98 limitations:
* No external libraries (Boost, C++11 features).
* Explicit memory management (No `std::unique_ptr` or `std::shared_ptr`).
* Heavy emphasis on `const` correctness and reference passing to minimize overhead.

## 👨‍💻 Author

**Sergi Juarez** *Systems Software Engineer | RISC-V & Kernel Enthusiast*

- **GitHub:** [imserez](https://github.com/imserez)
- **LinkedIn:** [sergijuarez](https://www.linkedin.com/in/sergijuarez)

---
*This project is part of the 42 Barcelona curriculum.*
