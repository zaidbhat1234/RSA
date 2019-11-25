//
//  VSS_ver.cpp
//  RSA
//
//  Created by Zaid Bhat on 12/02/19.
//  Copyright © 2019 Zaid Bhat. All rights reserved.
//

#include "VSS_ver.hpp"
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
#include "FDH_ver_sig.hpp"
using namespace std;

using namespace CryptoPP;





void VSS_verify(mpz_class *commit, mpz_class p,mpz_class q,mpz_class g,int t, mpz_class *s_t, int *index){
    
    
    int i ;   int j,w;
    w=10;
    // cout<<"p is:"<<p<<'\n';
    // cout<<"q is:"<<q<<'\n';
    mpz_class g_pi[w];
    for (i=0; i<w; i++) {
        g_pi[i]=power_1(g, s_t[i+3],q);
        //  cout<<"g^pi are :"<<g_pi[i]<<'\n';
    }
    
    
    mpz_class test_commit;
    mpz_class commit_temp[w];
    
    
    
    for(i=0;i<w;i++){
        test_commit=1;
        commit_temp[i]=1;
        for(j=0;j<t;j++){
            int ij= pow(index[i]+1, j);
            test_commit= power_1(commit[j], ij,q);
            commit_temp[i] *=test_commit;
            
        }
        
        commit_temp[i]%=q;
        // cout<<'\n'<<"shares are :"<<commit_temp[i];
        //cout<<'\n'<<"shares are :"<<commit_temp[i];
    }
    
    int count =0; // to count and stop when we have t verified shares
    int t_recons[t];// to store index of verified sub d
    // cout<<"VERIFIED"<<'\n';
    
    for(i=4;i<w;i++){    // the recomstruction in VSS_ver only works for specific i values and not all values , precision problem ask tabish
        
        
        if(g_pi[i]==commit_temp[i]){
            cout<<"VERIFIED VSS"<<'\n';
            
            
            if(count<t){
                t_recons[count]=i;
                //  cout<<"index is "<<t_recons[count]<<'\n';
            }
            count++;
            
        }
        else
            cout<<"NOT VERIFIED VSS"<<'\n';
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //if a di is not verified using signature verification then we have to reconstruct it using VSS shamir
    
    
    
    int k;
    mpz_class x_t=0;
    mpz_class y_t=0;
    j = 0;
    int l=0;
    mpz_class x1,x2;
    
    
    for (i=0; i<t; i++) {
        x1 = t_recons[i];
        l= t_recons[i];
        x_t = s_t[l+2];
        for (j=0; j<t; j++) {
            x2= t_recons[j];
            if(x1!=x2){
                x_t*=(x2/(x2-x1))%p;
            }
            x_t %= p;
            
        }
        y_t+=x_t;
        y_t%=p;
        if(y_t<0){
            y_t+=p;
            j++;
            l=0;
        }
    }
    
    
    // cout<<"reconstructed d is :"<<y_t<<'\n'; // actual correct d obtained after reconstruction
    
    
    /*
     for(k=t_recons[j];j<t;k++){
     x_t=s_t[k+2]; // because shares are stored from index 3 , but we start from 2nd share so start index is 4
     cout<<"share taken:"<<x_t<<'\n';
     cout<<"k is :"<<k<<'\n';
     for(i=t_recons[l];l<t;i++){
     if(i!=k){
     x_t*=((float)i/(i-k))%p;
     cout<<"i is :"<<i<<'\n';
     cout<<"x_t is :"<<x_t<<'\n';
     
     }
     else
     {
     }
     x_t %= p;
     l++;
     }
     
     
     y_t+=x_t;
     y_t%=p;
     if(y_t<0){
     y_t+=p;
     j++;
     l=0;
     }
     
     }
     
     */
    
}
