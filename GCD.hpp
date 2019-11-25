//
//  GCD.hpp
//  RSA
//
//  Created by Zaid Bhat on 12/02/19.
//  Copyright © 2019 Zaid Bhat. All rights reserved.
//

#ifndef GCD_hpp
#define GCD_hpp

#include <stdio.h>
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
mpz_class gcdExtended(mpz_class a, mpz_class b, mpz_class *x, mpz_class *y);
#endif /* GCD_hpp */
