//
//  Rsa_encrypt.cpp
//  RSA
//
//  Created by Zaid Bhat on 11/02/19.
//  Copyright © 2019 Zaid Bhat. All rights reserved.
//

#include "Rsa_encrypt.hpp"
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

using namespace std;

using namespace CryptoPP;


mpz_class encrypt(mpz_class m , FILE *ptr){
    
    
    int length;
    fscanf(ptr,"%d",&length);
    //cout<<"LENGTH"<<length;
    char temp__[length];
    fscanf(ptr,"%s",temp__);
    fscanf(ptr,"%d",&length);
    //cout<<"LENGTH"<<length;
    char temp_b[length];
    fscanf(ptr,"%s",temp_b);

    mpz_class b;
    b =temp_b;
    
    fscanf(ptr,"%d",&length);
    //cout<<"LENGTH"<<length;
    char temp_n[length];
    fscanf(ptr,"%s",temp_n);
    
    mpz_class n;
    n =temp_n;
    
    mpz_class enc= power_1(m,b,n);
    return enc;
    
}
