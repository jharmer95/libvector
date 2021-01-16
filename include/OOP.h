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

#include <stdlib.h>

#define MEM_FN_INNER(TYPE, FNAME) TYPE ## _impl_ ## FNAME

#define STATIC_FN(RET, FNAME, ...) RET (*FNAME)(__VA_ARGS__)
#define MEM_FN(TYPE, FNAME, RET, ...) RET (*FNAME)(TYPE*, ##__VA_ARGS__)
#define CONSTRUCTOR(TYPE, ...) MEM_FN(TYPE, construct, void, ##__VA_ARGS__)
#define DESTRUCTOR(TYPE) MEM_FN(TYPE, destruct, void)

#define DECLARE_STATIC_FN(TYPE, RET, FNAME, ...) extern RET MEM_FN_INNER(TYPE, FNAME)(__VA_ARGS__)
#define DECLARE_MEM_FN(TYPE, FNAME, RET, ...) extern RET MEM_FN_INNER(TYPE, FNAME)(TYPE*, ##__VA_ARGS__)
#define DECLARE_CONSTRUCTOR(TYPE, ...) DECLARE_MEM_FN(TYPE, construct, void, ##__VA_ARGS__)
#define DECLARE_DESTRUCTOR(TYPE) DECLARE_MEM_FN(TYPE, destruct, void)

#define IMPL_STATIC_FN(TYPE, FNAME, RET, ...) RET MEM_FN_INNER(TYPE, FNAME)(__VA_ARGS__)
#define IMPL_MEM_FN(TYPE, FNAME, RET, ...) RET MEM_FN_INNER(TYPE, FNAME)(TYPE* this, ##__VA_ARGS__)
#define IMPL_CONSTRUCTOR(TYPE, ...) IMPL_MEM_FN(TYPE, construct, void, ##__VA_ARGS__)
#define IMPL_DESTRUCTOR(TYPE) IMPL_MEM_FN(TYPE, destruct, void)

#define CONNECT_MEM_FN(TYPE, FNAME) this->FNAME = TYPE ## _impl_ ## FNAME

#define CALL(OBJ, FNAME, ...) OBJ.FNAME(&OBJ, ##__VA_ARGS__)
#define CALL_PTR(PTR, FNAME, ...) PTR->FNAME(PTR, ##__VA_ARGS__)
#define DELETE_STACK(OBJ) OBJ.destruct(&OBJ)
#define DELETE_HEAP(PTR) PTR->destruct(PTR); free(PTR)
#define DELETE(OBJ) DELETE_HEAP(OBJ)
#define STATIC_CALL(TYPE, FNAME, ...) MEM_FN_INNER(TYPE, FNAME)(__VA_ARGS__)
#define CREATE_STACK(TYPE, VAR, ...) TYPE VAR; VAR.construct = MEM_FN_INNER(TYPE, construct); VAR.destruct = MEM_FN_INNER(TYPE, destruct); VAR.construct(&VAR, ##__VA_ARGS__)
#define CREATE_HEAP(TYPE, VAR, ...) TYPE* VAR = (TYPE*)malloc(sizeof(TYPE)); VAR->construct = MEM_FN_INNER(TYPE, construct); VAR->destruct = MEM_FN_INNER(TYPE, destruct); VAR->construct(VAR, ##__VA_ARGS__)
#define CREATE(TYPE, ...) CREATE_STACK(TYPE, __VA_ARGS__)
