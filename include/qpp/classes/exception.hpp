/*
 * This file is part of Quantum++.
 *
 * Copyright (c) 2017 - 2024 softwareQ Inc. All rights reserved.
 *
 * MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * \file classes/exception.hpp
 * \brief Exceptions
 */

#ifndef QPP_CLASSES_EXCEPTION_HPP_
#define QPP_CLASSES_EXCEPTION_HPP_

#include <exception>
#include <optional>
#include <string>
#include <utility>

namespace qpp {
namespace exception {
    class Exception : public std::exception {
    protected:
        std::string where_;
        mutable std::string msg_;
        std::optional<std::string> context_;

    public:
        explicit Exception(std::string where,
                           std::optional<std::string> context = std::nullopt)
            : where_{std::move(where)}, msg_{}, context_{std::move(context)} {}

        const char* what() const noexcept override {
            msg_.clear();
            msg_ += "[WHERE: " + where_ + ']';
            msg_ += " " + description() + '!';

            if (context_.has_value()) {
                msg_ += " [CONTEXT: " + context_.value() + ']';
            }

            return msg_.c_str();
        }

        virtual std::string description() const = 0;
    };

    inline std::string Exception::description() const {
        return "qpp::exception::Exception";
    }

    class Unknown : public Exception {
    public:
        std::string description() const override { return "UNKNOWN EXCEPTION"; }
        using Exception::Exception;
    };

    class ZeroSize : public Exception {
    public:
        std::string description() const override { return "Object has zero size"; }
        ZeroSize(std::string where, std::string context)
            : Exception(std::move(where), std::move(context)) {}
        using Exception::Exception;
    };

    class MatrixNotSquare : public Exception {
    public:
        std::string description() const override { return "Matrix is not square"; }
        MatrixNotSquare(std::string where, std::string context)
            : Exception(std::move(where), std::move(context)) {}
        using Exception::Exception;
    };

    class MatrixNotSquareNorCvector : public Exception {
    public:
        std::string description() const override { return "Matrix is not square nor column vector"; }
        MatrixNotSquareNorCvector(std::string where, std::string context)
            : Exception(std::move(where), std::move(context)) {}
        using Exception::Exception;
    };

    class MatrixMismatchSubsys : public Exception {
    public:
        std::string description() const override { return "Matrix mismatch subsystems"; }
        MatrixMismatchSubsys(std::string where, std::string context)
            : Exception(std::move(where), std::move(context)) {}
        using Exception::Exception;
    };

    class DimsInvalid : public Exception {
    public:
        std::string description() const override { return "Invalid dimension(s)"; }
        DimsInvalid(std::string where, std::string context)
            : Exception(std::move(where), std::move(context)) {}
        using Exception::Exception;
    };

    // Continue adicionando outras exceções conforme necessário
} // namespace exception
} // namespace qpp

#endif /* QPP_CLASSES_EXCEPTION_HPP_ */
