/*

  MIT License

  Copyright (c) 2024 Yafiyogi

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

#pragma once

#include "fmt/format.h"

namespace yafiyogi::yy_test {

class TestCount final
{
  public:
    TestCount() noexcept;
    TestCount(const TestCount &) noexcept;
    TestCount(TestCount &&) noexcept;
    ~TestCount() noexcept;
    TestCount & operator=(const TestCount &) noexcept;
    TestCount & operator=(TestCount &&) noexcept;
    static int construct_count() noexcept;
    static int destruct_count() noexcept;
    static void reset() noexcept;
    int value() const noexcept;

  private:
    int m_value = 0;
    static int g_construct_count;
    static int g_destruct_count;
};

} // namespace yafiyogi::yy_test

namespace fmt {

template <>
struct formatter<yafiyogi::yy_test::TestCount>
{
    template <typename ParseContext>
    constexpr auto parse(ParseContext & ctx)
    {
      return ctx.begin();
    }

    template <typename FormatContext>
    auto format(const yafiyogi::yy_test::TestCount & v,
                FormatContext & ctx)
    {
      return format_to(ctx.out(), "{}", v.value());
    }
};


} // namespace fmt
