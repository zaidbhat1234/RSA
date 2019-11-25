//
//  Sig_ver_hashFDH.cpp
//  RSA
//
//  Created by Zaid Bhat on 08/02/19.
//  Copyright © 2019 Zaid Bhat. All rights reserved.
//

#include <stdio.h>
//
//  Rsa_key.cpp
//  RSA
//
//  Created by Zaid Bhat on 08/02/19.
//  Copyright © 2019 Zaid Bhat. All rights reserved.
//


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

string FDH(string message){
    
    string c[8]={"1","2","3","4","5","6","7","8"};
    string final="";
    std::stringstream stream;
    string output;
    int h;
    for (h=0; h<8; h++) {
        
        message.append(c[h]);
        //cout<<message;
        
        
        CryptoPP::SHA256 hash;
        CryptoPP::byte digest[ CryptoPP::SHA256::DIGESTSIZE ];
        // string message = "abcdefgh";         //the message that needs to be hashed to 256 bits.
        
        hash.CalculateDigest( digest, reinterpret_cast< CryptoPP::byte*>(&message[0]), message.length() );
        
        CryptoPP::HexEncoder encoder;
        output="";
        encoder.Attach( new CryptoPP::StringSink( output ) );
        encoder.Put( digest, sizeof(digest) );
        encoder.MessageEnd();
        //cout<<"FINAL:"<<final<<'\n';
        final.append(output);
        //cout<<"FINAL:"<<final<<'\n';
        message.erase(message.length()-1,1);
        
        
        //cout<<message;
    }
    return final;
}


mpz_class power1(mpz_class x, mpz_class y, mpz_class p)
{
    mpz_class res = 1;      // Initialize result
    
    x = x % p;  // Update x if it is more than or
    // equal to p
    
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y%2!=0)
            res = (res*x) % p;
        
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}


void FDH_ver_signature(mpz_class sig_hash,mpz_class b,mpz_class n,string message){
    
    
    string final = "";
    std::stringstream stream;
    final = FDH(message);   //function for full domain hash
    final.erase(final.length()-1,1);
    mpz_class hash_int;
    stream<<final;
    stream>>std::hex>>hash_int; //used to store the string of hex as int into gmp class
    // cout<<"hash int:"<<hash_int<<'\n';
    
    
    mpz_class sig_hash_ver = power1(sig_hash, b, n);
    //sig_hash_ver= sig_hash_ver^r_h;
    if(sig_hash_ver==hash_int){
        cout<<"VERIFIED THE SIGNED MESSAGE PRODUCED WITH HASH"<<'\n';
    }
    else
        cout<<"not verified hash"<<'\n';
    
}
