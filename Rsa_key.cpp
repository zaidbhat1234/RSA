//
//  Rsa_key.cpp
//  RSA
//
//  Created by Zaid Bhat on 08/02/19.
//  Copyright © 2019 Zaid Bhat. All rights reserved.
//



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

void generateprime(mpz_class *p,mpz_class *q){
    
    mpz_class x,y;
    mpz_t r3;
    gmp_randstate_t t3;
    gmp_randinit_default (t3);
    mpz_urandomb (r3, t3, 1024);
    srand(time(0));
    int temp = rand();
    mpz_t temp1;
    mpz_init(temp1);
    mpz_set_ui(temp1,temp);
    // mpz_mul(r3,r3,temp1);
    mpz_nextprime(r3,r3);
    //get p from gmp lib function above to generate very large prime
    char *s = mpz_get_str(NULL,10,r3);
    string str = s;
    mpz_class p1(str);
    *p=p1;
    cout<<p<<'\n';
    
    
    
    
    
    
    //generate n bit 2nd prime
    srand(time(0)*191991);
    temp = rand();
    mpz_set_ui(temp1,temp);
    //mpz_mul(r3,r3,temp1);
    mpz_nextprime(r3,r3);
    //get p from gmp lib function above to generate very large prime
    char *s1 = mpz_get_str(NULL,10,r3);
    string str1 = s1;
    mpz_class q1(str1);
    *q=q1;
    cout<<q<<'\n';
}

