//
//  GCD.cpp
//  RSA
//
//  Created by Zaid Bhat on 12/02/19.
//  Copyright © 2019 Zaid Bhat. All rights reserved.
//

#include "GCD.hpp"
#include <iostream>
#include <math.h>
#include <gmpxx.h>
#include <primesieve.hpp>
#include <math.h>
#include <time.h>
#include <string.h>
#include <chrono>
#include <thread>
#include <functional>
#include <cryptlib.h>
#include <iomanip>

#include <fstream>

#include <sha.h>
#include "filters.h"
#include "base64.h"
#include <hex.h>

#include "integer.h"
#include "osrng.h"
#include "nbtheory.h"
#include "hrtimer.h"
using namespace std;

using namespace CryptoPP;

mpz_class gcdExtended(mpz_class a, mpz_class b, mpz_class *x, mpz_class *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
    
    mpz_class x1, y1; // To store results of recursive call
    mpz_class gcd = gcdExtended(b%a, a, &x1, &y1);
    
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
    
    return gcd;
}
