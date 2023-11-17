/*
MIT License

Copyright (c) 2023 jackkyyang

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef __BACKEND_H_
    #define __BACKEND_H_

#include <stdint.h>
#include "cpu_config.h"
#include "front_end.h"

typedef struct exe_param
{
    uint64_t iid;           //当前执行到第几条指令
    uint64_t pc;            //当前的PC值
    InstSet  inst_set;       //指令集：16，32，64
    FetchStatus fetch_status;
    uint32_t* fetch_data_buf;
}ExeParam;


typedef struct execute_status
{
    uint8_t  redirect;
    // 0: No redirect
    // 1: normal redirect
    // 2: exit virtual machine
    uint64_t next_pc;
    uint64_t curr_pc;
    uint64_t exception_id;
    uint64_t address;
    uint64_t cause;
} ExeStatus;

ExeStatus instruction_execute(ExeParam* exe_param);

#endif //__BACKEND_H_