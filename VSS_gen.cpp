//
//  VSS_gen.cpp
//  RSA
//
//  Created by Zaid Bhat on 12/02/19.
//  Copyright © 2019 Zaid Bhat. All rights reserved.
//

#include "VSS_gen.hpp"
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
#include "VSS_gen.hpp"
using namespace std;

using namespace CryptoPP;

void VSS( mpz_class d,int t,mpz_class *thresh, mpz_class *array, mpz_class *commit){
    
    
    
    
    int k,i,j,w;
    int temp; w=10;
    
    mpz_class x_t=0,y_t=0;
    //mpz_class commit[t];
    mpz_class g ;
    mpz_class test_commit;
    
    
    
    mpz_t m1 ;
    mpz_init_set(m1,d.get_mpz_t());
    
    
    //to generate primes following condition p divides q-1
    mpz_t r3;
    
    //gmp_randstate_t t3;
    //gmp_randinit_default (t3);
    //mpz_urandomb (r3, t3, 1);
    //int temp = rand();
    //mpz_t temp1;
    //mpz_init(temp1);
    //mpz_set_ui(temp1,temp);
    mpz_init_set(r3,m1);
    
    
    mpz_nextprime(r3,r3);
    //  cout<<"p is :"<<mpz_get_ui(r3)<<'\n';
    char *s1 = mpz_get_str(NULL,10,r3);
    string str1 = s1;
    mpz_class p(str1);
    mpz_t r4;
    mpz_init_set(r4,r3);
    
    char *s = mpz_get_str(NULL,10,r4);
    string str = s;
    // cout<<"P"<<p<<'\n';
    mpz_class q(str);
    i=1;
    mpz_t temp_r;
    mpz_init_set(temp_r,r4);
    mpz_t r5;
    mpz_init_set(r5,r4);
    
    // cout<<"NEXT PRIME"<<r4<<'\n';
    
    while((q-1)%p!=0){
        mpz_set(r4,r5);
        mpz_add(r4,r4,temp_r);
        mpz_set(r5,r4);
        
        mpz_nextprime(r4,r4); //takes too long to generate primes for big d,very slow function
        
        //
        char *s3 = mpz_get_str(NULL,10,r4);
        string str3 = s3;
        q=str3;
        //cout<<q<<'\n';
    }
    
    
    
    
    // cout<<"q is :"<<q<<'\n';
    
    
    g=power_1(3, (q-1)/p, q );//generates 0 and 1 and shows verified for all
    
    
    array[0]=p;
    array[1]=q;
    array[2]=g;
    
    
    // printf("ENTER THRESHOLD  :\n");
    // scanf("%d",&t);
    // printf("ENTER PARTICIPANTS:\n");
    // scanf("%d",&w);
    
    mpz_class a_t[t];
    for(i=1;i<t;i++){
        temp=rand();
        a_t[i]=temp%p;
        // cout<<"coeff is "<<a_t[i]<<'\n';
        
        
    }
    
    
    a_t[0]=d;
    
    for(i=0;i<t;i++){
        commit[i]= power_1(g, a_t[i],q);
        
        //cout<<"commitments are :"<<commit[i]<<'\n';
        // cout<<"coeff are:"<<a_t[i]<<'\n';
    }
    
    
    mpz_class s_t[w];
    mpz_class g_pi[w];
    
    
    for(i=0;i<w;i++)
    {
        for(j=1;j<t;j++)
        {
            y_t=(i+1);
            for(k=1;k<j;k++){
                y_t*=(i+1);
                
            }
            
            x_t+=(a_t[j]*y_t)%p;
            
            
        }
        x_t+=a_t[0];
        s_t[i]=x_t;
        s_t[i]%=p;
        array[i+3]=s_t[i];
        g_pi[i]=power_1(g, s_t[i],q);
        //cout<<"g^pi are :"<<g_pi[i]<<'\n';
        //cout<<"shares  :"<<s_t[i]<<'\n';
        x_t=0;
        
        
    }
    
    y_t=0;
    
    for(k=2;k<=t+1;k++){
        x_t=s_t[k-1];
        
        
        for(i=2;i<=t+1;i++){
            if(i!=k){
                
                x_t*=((float)i/(i-k))%p;
                
            }
            else
            {
                
            }
            
            
            
            
            x_t %= p;
            
            
        }
        
        y_t+=x_t;
        y_t%=p;
        if(y_t<0){
            y_t+=p;
        }
        
    }
    
    
    
    
    
    
    //cout<<'\n'<<"shamir key is :"<<y_t;
    thresh = s_t;
    mpz_class commit_temp[w];
    for(i=0;i<w;i++){
        test_commit=1;
        commit_temp[i]=1;
        for(j=0;j<t;j++){
            int ij= pow(i+1, j);
            test_commit= power_1(commit[j], ij,q);
            commit_temp[i] *=test_commit;
            
        }
        
        commit_temp[i]%=q;
        // cout<<'\n'<<"shares are :"<<commit_temp[i];
    }
    
    /*
     for(i=0;i<w;i++){
     
     if(g_pi[i]==commit_temp[i]){
     cout<<"VERIFIED"<<'\n';
     }
     else
     cout<<"NOT VERIFIED"<<'\n';
     
     }
     */
    //return commit;
    //cout<<"VSS"<<'\n';
}
