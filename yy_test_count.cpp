/*

  MIT License

  Copyright (c) 2024-2025 Yafiyogi

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

#include "yy_test_count.h"

namespace yafiyogi::yy_test {

TestCount::TestCount() noexcept
{
  m_value = g_construct_count;
  ++g_construct_count;
}

TestCount::TestCount(const TestCount &) noexcept
{
  m_value = g_construct_count;
  ++g_construct_count;
}

TestCount::TestCount(TestCount &&) noexcept
{
  m_value = g_construct_count;
  ++g_construct_count;
}

TestCount::~TestCount() noexcept
{
  ++g_destruct_count;
}

TestCount & TestCount::operator=(const TestCount & other) noexcept
{
  m_value = other.m_value;
  return *this;
}

TestCount & TestCount::operator=(TestCount && other) noexcept
{
  m_value = other.m_value;
  other.m_value = -m_value;
  return *this;
}

int TestCount::construct_count() noexcept
{
  return g_construct_count;
}

int TestCount::destruct_count() noexcept
{
  return g_destruct_count;
}

void TestCount::reset() noexcept
{
  g_construct_count = 0;
  g_destruct_count = 0;
}

int TestCount::value() const noexcept
{
  return m_value;
}

int TestCount::g_construct_count = 0;
int TestCount::g_destruct_count = 0;

} // namespace yafiyogi::yy_test
