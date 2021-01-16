// A C library implementing a generic vector struct similar to that found in the C++ STL
// https://github.com/jharmer95/libvector
//
// Licensed under the MIT License <http://opensource.org/licenses/MIT>.
// SPDX-License-Identifier: MIT
// Copyright (c) 2021 Jackson Harmer <jharmer95@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include "OOP.h"

#define VECTOR(TYPE) Vector_ ## TYPE

#define DEFAULT_VECTOR_CAPACITY 5
#define VECTOR_CAP_INCREMENT 10

#define DECLARE_VECTOR(TYPE) \
typedef struct Vector_ ## TYPE\
{\
    CONSTRUCTOR(struct Vector_ ## TYPE);\
    DESTRUCTOR(struct Vector_ ## TYPE);\
    MEM_FN(struct Vector_ ## TYPE, reserve, void, size_t);\
    MEM_FN(struct Vector_ ## TYPE, clear, void);\
    MEM_FN(struct Vector_ ## TYPE, push_back, void, TYPE);\
    MEM_FN(struct Vector_ ## TYPE, at, TYPE*, size_t);\
    MEM_FN(struct Vector_ ## TYPE, c_at, const TYPE*, size_t);\
    MEM_FN(struct Vector_ ## TYPE, capacity, size_t);\
    MEM_FN(struct Vector_ ## TYPE, size, size_t);\
    MEM_FN(struct Vector_ ## TYPE, begin, TYPE*);\
    MEM_FN(struct Vector_ ## TYPE, end, TYPE*);\
    TYPE* _begin;\
    TYPE* _end;\
    TYPE* _data;\
    size_t _cap;\
    size_t _sz;\
} Vector_ ## TYPE;\
DECLARE_CONSTRUCTOR(Vector_ ## TYPE);\
DECLARE_DESTRUCTOR(Vector_ ## TYPE);\
DECLARE_MEM_FN(Vector_ ## TYPE, reserve, void, size_t);\
DECLARE_MEM_FN(Vector_ ## TYPE, clear, void);\
DECLARE_MEM_FN(Vector_ ## TYPE, push_back, void, TYPE);\
DECLARE_MEM_FN(Vector_ ## TYPE, at, TYPE*, size_t);\
DECLARE_MEM_FN(Vector_ ## TYPE, c_at, const TYPE*, size_t);\
DECLARE_MEM_FN(Vector_ ## TYPE, capacity, size_t);\
DECLARE_MEM_FN(Vector_ ## TYPE, size, size_t);\
DECLARE_MEM_FN(Vector_ ## TYPE, begin, TYPE*);\
DECLARE_MEM_FN(Vector_ ## TYPE, end, TYPE*)

#ifndef VECTOR_OPT_IN
#   define VECTOR_ENABLE_POD
#endif

#ifdef VECTOR_ENABLE_POD
#   define VECTOR_ENABLE_CHAR
#   define VECTOR_ENABLE_UCHAR
#   define VECTOR_ENABLE_SHORT
#   define VECTOR_ENABLE_USHORT
#   define VECTOR_ENABLE_INT
#   define VECTOR_ENABLE_UINT
#   define VECTOR_ENABLE_LONG
#   define VECTOR_ENABLE_ULONG
#   define VECTOR_ENABLE_LONGLONG
#   define VECTOR_ENABLE_ULONGLONG
#   define VECTOR_ENABLE_FLOAT
#   define VECTOR_ENABLE_DOUBLE
#   define VECTOR_ENABLE_LDOUBLE
#endif

#ifdef VECTOR_ENABLE_CHAR
DECLARE_VECTOR(char);
#endif

#ifdef VECTOR_ENABLE_UCHAR
typedef unsigned char uchar;
DECLARE_VECTOR(uchar);
#endif

#ifdef VECTOR_ENABLE_SHORT
DECLARE_VECTOR(short);
#endif

#ifdef VECTOR_ENABLE_USHORT
typedef unsigned short ushort;
DECLARE_VECTOR(ushort);
#endif

#ifdef VECTOR_ENABLE_INT
DECLARE_VECTOR(int);
#endif

#ifdef VECTOR_ENABLE_UINT
typedef unsigned int uint;
DECLARE_VECTOR(uint);
#endif

#ifdef VECTOR_ENABLE_LONG
DECLARE_VECTOR(long);
#endif

#ifdef VECTOR_ENABLE_ULONG
typedef unsigned long ulong;
DECLARE_VECTOR(ulong);
#endif

#ifdef VECTOR_ENABLE_LONGLONG
typedef long long longlong;
DECLARE_VECTOR(longlong);
#endif

#ifdef VECTOR_ENABLE_ULONGLONG
typedef unsigned long long ulonglong;
DECLARE_VECTOR(ulonglong);
#endif

#ifdef VECTOR_ENABLE_FLOAT
DECLARE_VECTOR(float);
#endif

#ifdef VECTOR_ENABLE_DOUBLE
DECLARE_VECTOR(double);
#endif

#ifdef VECTOR_ENABLE_LDOUBLE
typedef long double ldouble;
DECLARE_VECTOR(ldouble);
#endif

#ifdef VECTOR_ENABLE_STDDEF
#   include <stddef.h>
DECLARE_VECTOR(ptrdiff_t);
DECLARE_VECTOR(size_t);
DECLARE_VECTOR(wchar_t);
#endif

#ifdef VECTOR_ENABLE_STDINT
#   include <stdint.h>
DECLARE_VECTOR(int8_t);
DECLARE_VECTOR(uint8_t);
DECLARE_VECTOR(int16_t);
DECLARE_VECTOR(uint16_t);
DECLARE_VECTOR(int32_t);
DECLARE_VECTOR(uint32_t);
DECLARE_VECTOR(int64_t);
DECLARE_VECTOR(uint64_t);
#endif

#define IMPL_VECTOR(TYPE) \
IMPL_CONSTRUCTOR(Vector_ ## TYPE)\
{\
    CONNECT_MEM_FN(Vector_ ## TYPE, reserve);\
    CONNECT_MEM_FN(Vector_ ## TYPE, clear);\
    CONNECT_MEM_FN(Vector_ ## TYPE, push_back);\
    CONNECT_MEM_FN(Vector_ ## TYPE, at);\
    CONNECT_MEM_FN(Vector_ ## TYPE, c_at);\
    CONNECT_MEM_FN(Vector_ ## TYPE, capacity);\
    CONNECT_MEM_FN(Vector_ ## TYPE, size);\
    CONNECT_MEM_FN(Vector_ ## TYPE, begin);\
    CONNECT_MEM_FN(Vector_ ## TYPE, end);\
    this->_sz = 0;\
    this->_cap = DEFAULT_VECTOR_CAPACITY;\
    this->_data = (TYPE*)calloc(this->_cap, sizeof(TYPE));\
    this->_begin = this->_data;\
    this->_end = this->_data;\
}\
IMPL_DESTRUCTOR(Vector_ ## TYPE)\
{\
    free(this->_data);\
    this->_data = NULL;\
    this->_begin = NULL;\
    this->_end = NULL;\
    this->_sz = 0;\
    this->_cap = 0;\
}\
IMPL_MEM_FN(Vector_ ## TYPE, reserve, void, size_t cap)\
{\
    this->_cap = cap;\
    this->_data = (TYPE*)realloc(this->_data, this->_cap * sizeof(TYPE));\
}\
IMPL_MEM_FN(Vector_ ## TYPE, clear, void)\
{\
    this->_sz = 0;\
    this->_cap = DEFAULT_VECTOR_CAPACITY;\
    free(this->_data);\
    this->_data = (TYPE*)calloc(this->_cap, sizeof(TYPE));\
    this->_end = this->_data;\
}\
IMPL_MEM_FN(Vector_ ## TYPE, push_back, void, TYPE val)\
{\
    if (this->_sz == this->_cap)\
    {\
        this->_cap += VECTOR_CAP_INCREMENT;\
        this->_data = (TYPE*)realloc(this->_data, this->_cap * sizeof(TYPE));\
    }\
    this->_data[this->_sz] = val;\
    ++this->_sz;\
    this->_end = this->_begin + this->_sz;\
}\
IMPL_MEM_FN(Vector_ ## TYPE, at, TYPE*, size_t index)\
{\
    if (index >= this->_sz)\
    {\
        return NULL;\
    }\
    return &this->_data[index];\
}\
IMPL_MEM_FN(Vector_ ## TYPE, c_at, const TYPE*, size_t index)\
{\
    if (index >= this->_sz)\
    {\
        return NULL;\
    }\
    return &this->_data[index];\
}\
IMPL_MEM_FN(Vector_ ## TYPE, capacity, size_t)\
{\
    return this->_cap;\
}\
IMPL_MEM_FN(Vector_ ## TYPE, size, size_t)\
{\
    return this->_sz;\
}\
IMPL_MEM_FN(Vector_ ## TYPE, begin, TYPE*)\
{\
    return this->_begin;\
}\
IMPL_MEM_FN(Vector_ ## TYPE, end, TYPE*)\
{\
    return this->_end;\
}
