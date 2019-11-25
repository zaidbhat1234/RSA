//
//  Ver_addShare.cpp
//  RSA
//
//  Created by Zaid Bhat on 11/02/19.
//  Copyright © 2019 Zaid Bhat. All rights reserved.
//

#include "Ver_addShare.hpp"

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
#include "Gen_dec_key.hpp"
using namespace std;

using namespace CryptoPP;








void signature_ver(mpz_class *p1, int n , mpz_class m , mpz_class mod,mpz_class *temp_w, mpz_class *temp_, mpz_class g, mpz_class phi)
{
    
    int i;
    
    
    
    mpz_class inverse[n];
    
    mpz_class gcd;
    mpz_class x,y;
    
    
    //cout<<"mod is :"<<mod<<'\n';
    
    // the for loop below finds the inverse of p1[i]'s, but inverse of all p1[i]'s doesnt exist because gcd is not always 1 so we hav to generate the di's such that gcd(di,n)==1
    
    for (i=0; i<n; i++) {
        gcd = gcdExtended1(p1[i],phi,&x,&y);
        mpz_class a = x;
        if(a<0){
            a=a+ phi;}
        inverse[i]=a;
        //cout<<"gcd is :"<<gcd<<'\n';
        //cout<<"inverse is"<<inverse[i]<<'\n';
        //cout<<"of:"<<p1[i]<<'\n';
        
        
    }
    
    
    
    mpz_class a = rand();
    a%=mod;
    mpz_class b = rand();
    b%=mod;
    
    // cout<<"a is :"<<a<<'\n'; cout<<"b is :"<<b<<'\n';
    mpz_class challenge[n];
    mpz_class response[n];
    for (i=0; i<n; i++) {
        challenge[i] = (power_1(temp_w[i], b,mod) * power_1(temp_[i], a,mod))%mod;
        response[i] = power_1(challenge[i], inverse[i],mod);
        //cout<<"Challenge is "<<challenge[i]<<'\n';
        
    }
    
    mpz_class ver = (power_1(m, a,mod)*power_1(g, b,mod))%mod;
    
    for (i=0; i<n; i++) {
        //cout<<"ver is "<<ver<<'\n';
        //cout<<"response is :"<<response[i]<<'\n';
        if (ver == response[i]) {
            
            //cout<<"verified"<<'\n';
            
        }
        else
            cout<<"not verified"<<'\n';
        
    }
    
    
    
    
    
    
    // for(i=0;i<n;i++){
    
    //    cout<<temp_[i]<<'\n';
    //}
    
}
