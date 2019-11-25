//
//  Gen_prime_.cpp
//  RSA
//
//  Created by Zaid Bhat on 10/02/19.
//  Copyright © 2019 Zaid Bhat. All rights reserved.
//

#include "Gen_prime_.hpp"
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


void GenPrime(FILE *ptr1,FILE *ptr2){
    
    //generate n bit first prime
    mpz_t r3;
    gmp_randstate_t t3;
    gmp_randinit_default (t3);
    mpz_urandomb (r3, t3, 300);
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
    
    
    
    char temp_p[str.length()];
    strcpy(temp_p, str.c_str());
    fprintf(ptr1, "%ld %s ",str.length(),temp_p);
    
    
    
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
   
    
    char temp_q[str.length()];
    strcpy(temp_q, str1.c_str());
    fprintf(ptr2, "%ld %s ",str1.length(),temp_q);
    fclose(ptr1);
    fclose(ptr2);
     gmp_randclear(t3);
    mpz_clear(r3);

}
