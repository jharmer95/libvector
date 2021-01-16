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

#include "vector.h"

#ifdef VECTOR_ENABLE_CHAR
IMPL_VECTOR(char)
#endif

#ifdef VECTOR_ENABLE_UCHAR
IMPL_VECTOR(uchar)
#endif

#ifdef VECTOR_ENABLE_SHORT
IMPL_VECTOR(short)
#endif

#ifdef VECTOR_ENABLE_USHORT
IMPL_VECTOR(ushort)
#endif

#ifdef VECTOR_ENABLE_INT
IMPL_VECTOR(int)
#endif

#ifdef VECTOR_ENABLE_UINT
IMPL_VECTOR(uint)
#endif

#ifdef VECTOR_ENABLE_LONG
IMPL_VECTOR(long)
#endif

#ifdef VECTOR_ENABLE_ULONG
IMPL_VECTOR(ulong)
#endif

#ifdef VECTOR_ENABLE_LONGLONG
IMPL_VECTOR(longlong)
#endif

#ifdef VECTOR_ENABLE_ULONGLONG
IMPL_VECTOR(ulonglong)
#endif

#ifdef VECTOR_ENABLE_FLOAT
IMPL_VECTOR(float)
#endif

#ifdef VECTOR_ENABLE_DOUBLE
IMPL_VECTOR(double)
#endif

#ifdef VECTOR_ENABLE_LDOUBLE
IMPL_VECTOR(ldouble)
#endif

#ifdef VECTOR_ENABLE_STDDEF
IMPL_VECTOR(ptrdiff_t)
IMPL_VECTOR(size_t)
IMPL_VECTOR(wchar_t)
#endif

#ifdef VECTOR_ENABLE_STDINT
IMPL_VECTOR(int8_t)
IMPL_VECTOR(uint8_t)
IMPL_VECTOR(int16_t)
IMPL_VECTOR(uint16_t)
IMPL_VECTOR(int32_t)
IMPL_VECTOR(uint32_t)
IMPL_VECTOR(int64_t)
IMPL_VECTOR(uint64_t)
#endif
