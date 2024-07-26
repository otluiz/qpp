# Contributions to Quantum++

## Description

This contribution fixes several type-related issues and adjusts exception handling in the Quantum++ library. The following changes were made to ensure compatibility and proper functionality:

## Changes Made

1. **Exception Handling**:
   - Added constructors to exceptions in `exception.hpp` to accept two arguments (`std::string` and `std::string`).
   - Corrected the exception calls in various files to pass appropriate argument types.

2. **Type Adjustments**:
   - Updated function definitions and calls in `noise.hpp` to use `std::optional<std::string>` where necessary.
   - Corrected lambda functions in `semantic.hpp` to ensure proper type handling.

## Files Modified

- `include/qpp/classes/exception.hpp`
- `include/qpp/classes/noise.hpp`
- `include/qpp/qasmtools/include/qasmtools/ast/semantic.hpp`

## Testing

The changes were tested locally to ensure that the library compiles and functions as expected. Further testing and review are encouraged to validate these changes in different environments and use cases.

## Contribution

These fixes aim to improve the robustness and maintainability of the Quantum++ library, addressing issues that other users might encounter. This contribution also serves as part of my Ph.D. research in Artificial Intelligence, enhancing the practical applications of quantum computing.

## Structure working actual
~/Workspace/Quantum_original/qpp
├── include
│   └── qpp
│       ├── classes
│       │   ├── exception.hpp
│       │   └── noise.hpp
│       └── qasmtools
│           └── include
│               └── qasmtools
│                   └── ast
│                       └── semantic.hpp
└── CONTRIBUTING.md
