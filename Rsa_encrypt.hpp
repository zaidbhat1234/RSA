//
//  Rsa_encrypt.hpp
//  RSA
//
//  Created by Zaid Bhat on 11/02/19.
//  Copyright © 2019 Zaid Bhat. All rights reserved.
//

#ifndef Rsa_encrypt_hpp
#define Rsa_encrypt_hpp

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
#include "Gen_prime_.hpp"
#include "Rsa_encrypt.hpp"
using namespace std;

using namespace CryptoPP;

mpz_class encrypt(mpz_class m , FILE *ptr);

#endif /* Rsa_encrypt_hpp */
