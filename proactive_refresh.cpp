//
//  proactive_refresh.cpp
//  RSA
//
//  Created by Zaid Bhat on 12/02/19.
//  Copyright © 2019 Zaid Bhat. All rights reserved.
//

#include "proactive_refresh.hpp"
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
#include "VSS_gen.hpp"
#include "Distribute_d.hpp"
using namespace std;

using namespace CryptoPP;


void proactive_refresh(mpz_class *d, int n,mpz_class p_phi,mpz_class *d_ref){
    
    mpz_class d_temp[n];
    
    int i;
    
    for(i=0;i<n;i++){
        if(i==0){
            d_ref[i]=0;
        }
        Distribute_d(d[i], n, d_temp,p_phi);
        for(i=0;i<n;i++){
            d_ref[i]+=d_temp[i];
        }
        
    }
    cout<<"REFRESHED shares (proactivisation)"<<'\n';
    
    
    /* to verify if the proactive refresh in the background works add mod and enc in the proactive and timer function
     
     cout<<"REFRESHED"<<'\n';
     mpz_class dnew=add_d(d,n);
     enc = power1(enc, dnew, mod);
     cout<<"DECRYPTED :"<<enc<<'\n';
     */
    // return d_ref;
}
