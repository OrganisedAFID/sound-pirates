//  (C) Copyright Gennadiy Rozental 2002-2006.
//  (C) Copyright Gennadiy Rozental & Ullrich Koethe 2001.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at 
//  http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/test for the library home page.



#define BOOST_TEST_MODULE SplashTests
#include <boost/test/unit_test.hpp>

#include <stdio.h>      /* printf */
#include <math.h>       /* sin */

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <complex>     
#include <string>
#include <algorithm>
#include "defineNote.h"
using namespace std;

/**
 * Unit test to check that the input frequency tone matches up to its correpsonding note
 * 
 */


BOOST_AUTO_TEST_SUITE( test_suite2 )

BOOST_AUTO_TEST_CASE(mytest_2)
{
BOOST_CHECK_EQUAL('F', define_note(345));
}
BOOST_AUTO_TEST_SUITE_END()