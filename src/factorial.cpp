/*
 * Copyright (c) 2019 Ben Lechlitner (otherland@gmail.com)
 * Distributed under the MIT License.
 * See accompanying file LICENSE.md or copy at http://opensource.org/licenses/MIT
 */

#include <sstream>
#include <stdexcept>

#include "cg-practice-cpp/factorial.hpp"

namespace cg_practice_cpp
{

//! Compute factorial.
const int computeFactorial( const int integerNumber )
{
	if ( integerNumber < 0 )
	{
		std::ostringstream errorMessage;
		errorMessage << "ERROR: (" << integerNumber << "!) is undefined!" << std::endl;
		throw std::runtime_error( errorMessage.str( ) );
	}

	return ( integerNumber == 0 ) ? 1 : integerNumber * computeFactorial( integerNumber  - 1 );
}

} // namespace cg_practice_cpp
