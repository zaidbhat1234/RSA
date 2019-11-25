//
//  Gen_prime_.hpp
//  RSA
//
//  Created by Zaid Bhat on 10/02/19.
//  Copyright © 2019 Zaid Bhat. All rights reserved.
//

#ifndef Gen_prime__hpp
#define Gen_prime__hpp

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
#include "FDH_sig.hpp"
#include "FDH_ver_sig.hpp"
#include "Gen_prime.hpp"
#include "Gen_dec_key.hpp"

using namespace std;

using namespace CryptoPP;



void GenPrime(FILE *ptr1,FILE *ptr2);
#endif /* Gen_prime__hpp */
