//
//  Distribute_d.cpp
//  RSA
//
//  Created by Zaid Bhat on 12/02/19.
//  Copyright © 2019 Zaid Bhat. All rights reserved.
//

#include "Distribute_d.hpp"
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
#include "GCD.hpp"
using namespace std;

using namespace CryptoPP;

void Distribute_d(mpz_class a, int n, mpz_class *p1,mpz_class p_phi){
    
    mpz_class p;
    
    mpz_class temp;
    mpz_class temp_d;
    mpz_class gcd;
    mpz_class x,y;
    
    // mpz_t r4;
    //gmp_randstate_t t3;
    //gmp_randinit_default (t3);
    //mpz_urandomb (r4, t3, 64);
    //mpz_t temp1;
    //mpz_init(temp1);
    int i;
    for (i=0; i<n-1; i++) {
        
        temp= rand();
        temp %= ((p_phi/2)-1);
        temp_d = 2*temp+1;
        gcd = gcdExtended(temp_d, p_phi, &x, &y);
        
        while (gcd!=1) {
            
            temp= rand();
            temp %= ((p_phi/2)-1);
            temp_d = 2*temp+1;
            gcd = gcdExtended(temp_d, p_phi, &x, &y);
            
            // cout<<"di is "<<temp_d<<'\n';
            
        }
        
        
        //Generate d's such that their gcd with p-1 is 1. even if we do it by hit and trial for n-1 d's we will still not be sure if the last subtracted d will be co prime to p-1
        
        
        /*
         while(temp<0||temp>a/n){
         temp = rand();
         gcd = gcdExtended(temp, p_phi, &x, &y);
         }
         */
        
        
        
        
        // mpz_set_ui(temp1,temp);
        //mpz_mul(r4,r4,temp1);
        //char *s = mpz_get_str(NULL,10,r4);
        //string str = s;
        
        mpz_class p = temp_d;
        p1[i]=p;
        //cout<<"di is "<<p<<'\n';
        a= a-p;
        
    }
    mpz_class gcd1;
    
    gcd1 = gcdExtended(a, p_phi, &x, &y);
    //cout<<"GCD 1 is "<<gcd1<<'\n';
    i = 3;
    gcd = gcdExtended(p1[i], p_phi, &x, &y);
    //cout<<"GCD i is "<<gcd<<'\n';
    
    //BELOW LOOP WORKS WHEN N_D IS ODD , FOR EVEN , THE SUM OF EVEN NUMBER OF N_D-2 IS EVEN , BECAUSE EACH DI IS INDIVIDUALLY ODD , SUM OF EVEN NUMBER OF ODD NUMBERS IS EVEN , SO IT DOESNT WORK WHEN N_D IS EVEN, in n_d as even, the n-1 shares are odd and thus nth share is even to make the final d which is odd, so it wont work for n_d as even but only when n_d is odd
    while (gcd1!=1) {
        gcd =rand();
        while (gcd!=1) {
            
            temp= rand();
            temp %= ((p_phi/2)-1);
            temp_d = 2*temp+1;
            gcd = gcdExtended(temp_d, p_phi, &x, &y);
            
            //cout<<"di is "<<temp_d<<'\n';
            
        }
        //cout<<"P is "<<a<<'\n';
        a=a+p1[i];
        //cout<<"P is "<<a<<'\n';
        p1[i]=temp_d;
        //cout<<"P is "<<a<<'\n';
        a=a-temp_d;
        //cout<<"P is "<<a<<'\n';
        //cout<<"P_phi is "<<p_phi<<'\n';
        gcd1 = gcdExtended(a, p_phi, &x, &y);
        // cout<<"GCD 1 is "<<gcd1<<'\n';
        // cout<<"GCD i is "<<gcd1<<'\n';
    }
    
    
    
    
    
    p1[n-1]=a;
    
    
}
