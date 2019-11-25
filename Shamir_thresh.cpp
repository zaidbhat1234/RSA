//
//  Shamir_thresh.cpp
//  RSA
//
//  Created by Zaid Bhat on 12/02/19.
//  Copyright © 2019 Zaid Bhat. All rights reserved.
//

#include "Shamir_thresh.hpp"
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
using namespace std;

using namespace CryptoPP;



void Shamir_threshold( mpz_class d,int t,mpz_class *thresh){
    
    
    
    
    int k,i,j,w;
    int temp;
    mpz_class x_t=0,y_t=0;
    
    
    mpz_class q = 1000000000000;
    
    
    
    /*for generating q
     int rand1=rand();
     mpz_class q;
     
     
     mpz_t r3;
     mpz_t temp1;
     mpz_init(temp1);
     mpz_set_ui(temp1,rand1);
     while(r3<d){
     mpz_nextprime(r3,r3);
     }
     
     
     
     //get p from gmp lib function above to generate very large prime
     char *s = mpz_get_str(NULL,10,r3);
     string str = s;
     
     mpz_class q(str);
     */
    
    
    w=4;
    // printf("ENTER THRESHOLD  :\n");
    // scanf("%d",&t);
    // printf("ENTER PARTICIPANTS:\n");
    // scanf("%d",&w);
    mpz_class a_t[t];
    for(i=1;i<t;i++){
        temp=rand();
        a_t[i]=temp%q;
        
        
        
    }
    a_t[0]=d;
    
    
    
    
    mpz_class s_t[w];
    
    
    
    for(i=0;i<w;i++)
    {
        for(j=1;j<t;j++)
        {
            y_t=(i+1);
            for(k=1;k<j;k++){
                y_t*=(i+1);
                
            }
            
            x_t+=(a_t[j]*y_t)%q;
            
            
        }
        x_t+=a_t[0];
        s_t[i]=x_t;
        s_t[i]%=q;
        
        x_t=0;
        
        
    }
    
    y_t=0;
    
    for(k=2;k<=t+1;k++){
        x_t=s_t[k-1];
        
        
        for(i=2;i<=t+1;i++){
            if(i!=k){
                
                x_t*=((float)i/(i-k))%q;
                
            }
            else
            {
                
            }
            
            
            
            
            x_t %= q;
            
            
        }
        
        y_t+=x_t;
        y_t%=q;
        
    }
    // cout<<'\n'<<"shamir key is :"<<y_t;
    thresh = s_t;
    
    
}





