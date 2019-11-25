//
//  PSS_sig.hpp
//  
//
//  Created by Zaid Bhat on 12/02/19.
//

#ifndef PSS_sig_hpp
#define PSS_sig_hpp

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
static inline unsigned int value(char c);
std::string str_xor(std::string const & s1, std::string const & s2);
void PSS_ver(FILE *ptr,mpz_class n);
void PSS( mpz_class n);

#endif /* PSS_sig_hpp */
