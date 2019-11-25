//
//  Gen_sig_addtiveShare.cpp
//  RSA
//
//  Created by Zaid Bhat on 11/02/19.
//  Copyright © 2019 Zaid Bhat. All rights reserved.
//

#include "Gen_sig_addtiveShare.hpp"
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



void signature_gen(mpz_class *p1, int n , mpz_class m , mpz_class mod,mpz_class *temp_){
    mpz_class temp=1;
    int i;
    mpz_class d=1;
    mpz_class d1;
    // mpz_class temp_[n];
    //cout<<"signatures are:";
    for (i=0; i<n; i++) {
        d1=p1[i];
        
        //while(d1!=0){
        //   d*=m;
        //    d1--;
        //}
        //d=d%mod;
        temp_[i] = power_1(m, d1, mod);
        
        temp*= temp_[i];
        
    }
    // for(i=0;i<n;i++){
    
    //    cout<<temp_[i]<<'\n';
    //}
    temp = temp%mod;
    
    //cout<<"signatures generated "<<'\n';
    
    
}
