//
//  Gen_wit_additiveShare.cpp
//  RSA
//
//  Created by Zaid Bhat on 11/02/19.
//  Copyright © 2019 Zaid Bhat. All rights reserved.
//

#include "Gen_wit_additiveShare.hpp"
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





mpz_class witness_gen(mpz_class *p1, int n , mpz_class m , mpz_class mod,mpz_class *temp_w){
    
    mpz_class g = rand() % mod ;
    //cout<<"g is :"<<g<<'\n';
    g=3;
    
    int i;
    
    mpz_class d1;
    // mpz_class temp_[n];
    //cout<<"witnesses are:";
    for (i=0; i<n; i++) {
        d1=p1[i];
        
        //while(d1!=0){
        //   d*=m;
        //    d1--;
        //}
        //d=d%mod;
        temp_w[i] = power_1(g, d1, mod);
        // cout<<"w is :"<<temp_w[i]<<'\n';
        
        
    }
    //cout<<"witnesses generated"<<'\n';
    return g;
}
