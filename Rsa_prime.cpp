//
//  Rsa_prime.cpp
//  RSA
//
//  Created by Zaid Bhat on 09/02/19.
//  Copyright © 2019 Zaid Bhat. All rights reserved.
//

#include "Rsa_prime.hpp"
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
using namespace std;

using namespace CryptoPP;

void Gen_prime(){
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
    mpz_class p(str);
    //cout<<p<<'\n';
    
    
    
    
    
    
    //generate n bit 2nd prime
    srand(time(0)*191991);
    temp = rand();
    mpz_set_ui(temp1,temp);
    //mpz_mul(r3,r3,temp1);
    mpz_nextprime(r3,r3);
    //get p from gmp lib function above to generate very large prime
    char *s1 = mpz_get_str(NULL,10,r3);
    string str1 = s1;
    mpz_class q(str1);
    cout<<"yes";
}
