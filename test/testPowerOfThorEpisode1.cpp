/*
 * Copyright (c) 2019 Ben Lechlitner (otherland@gmail.com)
 * Distributed under the MIT License.
 * See accompanying file LICENSE.md or copy at http://opensource.org/licenses/MIT
 */

#ifdef USE_CATCH2

#include <catch2/catch.hpp>

#elif USE_GTEST

#include <gtest/gtest.h>

#endif // USE_CATCH2

#include "cg-practice-cpp/power-of-thor-episode-1.hpp"

namespace cg_practice_cpp
{
namespace tests
{

#ifdef USE_CATCH2

/* TEST_CASE( "Test power of thor function", "[factorial]" )
{
    
}
*/

#elif USE_GTEST

TEST(Input, Position)
{
    
}

#endif // USE_CATCH2

} // namespace tests
} // namespace cg_practice_cpp
