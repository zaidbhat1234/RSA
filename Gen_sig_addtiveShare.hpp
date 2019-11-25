//
//  Gen_sig_addtiveShare.hpp
//  RSA
//
//  Created by Zaid Bhat on 11/02/19.
//  Copyright © 2019 Zaid Bhat. All rights reserved.
//

#ifndef Gen_sig_addtiveShare_hpp
#define Gen_sig_addtiveShare_hpp

#include <stdio.h>
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
#include "FDH_ver_sig.hpp"
using namespace std;

using namespace CryptoPP;



void signature_gen(mpz_class *p1, int n , mpz_class m , mpz_class mod,mpz_class *temp_);

#endif /* Gen_sig_addtiveShare_hpp */
