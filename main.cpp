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
#include<stdlib.h>
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
#include "FDH_sig.hpp"
#include "FDH_ver_sig.hpp"
#include "Gen_prime.hpp"
#include "Gen_dec_key.hpp"
#include "Gen_prime_.hpp"
#include "Rsa_encrypt.hpp"
#include "Gen_sig_addtiveShare.hpp"
#include "Gen_wit_additiveShare.hpp"
#include "Ver_addShare.hpp"
#include "PSS_gen.hpp"
#include "PSS_ver.hpp"
#include "VSS_gen.hpp"
#include "Distribute_d.hpp"
#include "proactive_refresh.hpp"
#include "Shamir_thresh.hpp"
#include "VSS_ver.hpp"

 #include "pch.h"
 #include "sha3.h"
 #include "keccakc.h"































mpz_class power(mpz_class x, mpz_class y)
{
    mpz_class t;
    t=x;
    if(y==0){
        t=1;
    }
    else{
        while(y!=1)
        {
            t=t*x;
            y=y-1;
        }
    }
   
    return t;
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




mpz_class add_d(mpz_class *p1, int n){
    
    int i ;
    mpz_class p=0;
    for(i=0;i<n;i++){
        
        p=p+p1[i];
        
    }
   
    return p;
}



//proactivisation

void timer_new(void func(mpz_class *d, int n,mpz_class p_phi,mpz_class *d_ref),mpz_class *d1, int n1,mpz_class p_phi1,mpz_class *d_ref1, int interval){
    
    thread t1([func,d1,n1,p_phi1,d_ref1,interval]{ while (true) {
        func(d1,n1,p_phi1,d_ref1);
      
        this_thread::sleep_for(std::chrono::microseconds(interval));
    }});
    
    t1.detach();
    
}













//implement shamir to enable threshold scheme to deconstruct d's



 //attempt to include VSS in refresh










 


int main (void) {
    
   
   
    
    
    
    FILE *ptrP = fopen("Primep.txt", "w");
    FILE *ptrQ = fopen("Primeq.txt", "w");
    
 
    

    int length;
   mpz_class p =   Gen_prime(1024,1,ptrP);
    
   mpz_class q = Gen_prime(1024,2,ptrQ);
    fclose(ptrP);
    fclose(ptrQ);
 
    //cout<<"P"<<p<<'\n'<<"Q"<<q;
    /*
    
    FILE *ptrP = fopen("Primep.txt", "w");
    FILE *ptrQ = fopen("Primeq.txt", "w");
    
   GenPrime(ptrP,ptrQ);
    
    ptrP = fopen("Primep.txt", "r");
    int length;
    fscanf(ptrP,"%d",&length);
    //cout<<"LENGTH"<<length;
    char temp__p[length];
    fscanf(ptrP,"%s",temp__p);
    mpz_class p;
    p =temp__p;
    
    fclose(ptrP);
    ptrP = fopen("Primeq.txt", "r");
   
    fscanf(ptrP,"%d",&length);
    //cout<<"LENGTH"<<length;
    char temp__q[length];
    fscanf(ptrP,"%s",temp__q);
    mpz_class q;
    q =temp__q;
     */
    // cout<<"P is:"<<p<<'\n'<<"Q is "<<q;
  
 
  //
    std::ifstream ifs("SampleTextFile_10kb.txt");
    std::string message( (std::istreambuf_iterator<char>(ifs) ),
                        (std::istreambuf_iterator<char>()    ) );
  //cout<<"CONTENT :"<<'\n'<<message.c_str();
    
    
   
  
  
    
    
   
    
    
   
     
    
    mpz_class x,y;
    

    
   //find b
    mpz_class n,phi;
    n=p*q;
  // cout<<"n is "<<n<<'\n';
    
    
    
    
   // FILE *ptrP,*ptrQ;
    
    ptrP = fopen("pub_key.txt", "w");
    ptrQ = fopen("pri_key.txt", "w");
    
  
    
   
                                                                  
    
    Gen_dec_key(ptrP, ptrQ);
  
   
    
    ptrP = fopen("pub_key.txt", "r");
    ptrQ = fopen("pri_key.txt", "r");
    fscanf(ptrP,"%d",&length);
    //cout<<"LENGTH"<<length;
    char temp_bb[length];
    fscanf(ptrP,"%s",temp_bb);
    mpz_class b;
    b =temp_bb;
    fscanf(ptrQ,"%d",&length);
    //cout<<"LENGTH"<<length;
    char temp_aa[length];
    fscanf(ptrQ,"%s",temp_aa);
    mpz_class a;
    a =temp_aa;
    
    fclose(ptrP);
    fclose(ptrQ);
    
    
    FILE *ptrrsa = fopen("rsapub.txt", "w"); //to store public values of RSA in order n , enc message, public key.
    
    
    
    string tem_f;
    char tem_n[tem_f.length()];
    tem_f = n.get_str();
    fprintf(ptrrsa, "%ld %s ",tem_f.length(),tem_n);
 
    fclose(ptrrsa);
    
    PSS(n);
    
    
    ptrP =fopen("PSS.txt", "r");
    PSS_ver(ptrP,n);
   
    
   
  
    fclose(ptrP);
    
    
    mpz_class m ;  // stores message to be sent using RSA
    
    
    
    
    
    
    //storing values in a file
    
    FILE *ptr = fopen("public.txt", "w");
    //to generate signed hash message and verify that. WRITE SEPERATE FUNCTION FOR THIS.
    
    FILE *ptr1= fopen("pub_fdh_gen_sig.txt", "w");
    
    
    string temp_f = a.get_str();
    char temp_a[temp_f.length()];
    strcpy(temp_a, temp_f.c_str());
    fprintf(ptr1, "%ld %s ",temp_f.length(),temp_a);
    
    
    temp_f = n.get_str();
    char temp_n[temp_f.length()];
    strcpy(temp_n, temp_f.c_str());
    fprintf(ptr1, "%ld %s ",temp_f.length(),temp_n);
    
   
    fclose(ptr1);
    ptr1 =fopen("pub_fdh_gen_sig.txt", "r");
    
    
    
    
    
    
    
    mpz_class sig_hash;
 

    
      ptr1 =fopen("pub_fdh_gen_sig.txt", "r");
    sig_hash =  FDH_sig_gen(message, ptr1);// generating hash signature
    
    fclose(ptr1);
    //cout<<"HDH"<<sig_hash;
     temp_f = sig_hash.get_str();
    char temp__[temp_f.length()];
    strcpy(temp__, temp_f.c_str());
    fprintf(ptr, "%ld %s ",temp_f.length(),temp__);
    
     temp_f = b.get_str();
    char temp_b[temp_f.length()];
    strcpy(temp_b, temp_f.c_str());
    fprintf(ptr, "%ld %s ",temp_f.length(),temp_b);
    
    temp_f = n.get_str();
    fprintf(ptr, "%ld %s ",temp_f.length(),temp_n);
    fprintf(ptr, "%ld %s ",message.length(),message.c_str());
    
    
    
      fclose(ptr);
    
    
    ptr = fopen("public.txt", "r");
    
    
  
   
    FDH_ver_signature_(ptr);  // function to verify hash signature
  
    
    
    fclose(ptr);
    
    
   
    
    
    //initialize the message with number with greater than 20 digits
    string my_number ;
    cout<<"ENTER MESSAGE";
    getline(cin,my_number);
    mpz_class n1(my_number); // done!
    m=n1;
    
   
    
  
    
    
 
    
   // fprintf(ptrrsa, "%ld %s ",my_number.length(),my_number.c_str());
    
    
    
    
    //Encryption. self constructed power function used
    
    ptr = fopen("public.txt", "r");
    
    
    mpz_class enc= encrypt(m, ptr);
   
    cout<<"THE ENCRYPTED MESSAGE IS: "<<enc<<'\n';
    
    
    
    temp_f = enc.get_str();
    char temp_enc[temp_f.length()];
    strcpy(temp_enc, temp_f.c_str());
    fprintf(ptrrsa, "%ld %s ",temp_f.length(),temp_enc);
    
    temp_f = b.get_str();
    strcpy(temp_b, temp_f.c_str());
    fprintf(ptrrsa, "%ld %s ",temp_f.length(),temp_b);
    
    fclose(ptrrsa);
    
    
    
    
    
  
    

    
   
    
     mpz_class p_phi = p-1;
    
    //to distribute d into n parties
    int n_d ;  // stores the value of number of additive shares that are to be generated
    cout<<"Enter n:(odd)"<<'\n';
    cin>>n_d;
    mpz_class p1[n_d]; // stores the values of additive shares created
    Distribute_d(a, n_d ,p1,p_phi);  // creates n additive shares for key d
    //the last share is a very large number
    
    
    //to combine the shares back to obtain decryption key
    mpz_class dnew= add_d(p1,n_d);
    
    
    
    //to achieve refreshed shares for proactivisation, time is to be added for time period of refreshing
    mpz_class d_ref[n_d];
    proactive_refresh(p1, n_d,p_phi,d_ref);
    dnew= add_d(p1,n_d);
    //function to execute the proactive function in background
    
    timer_new(proactive_refresh, p1, n_d, p_phi, d_ref, 10);
    
    // timer_start(do_something(), 1000);
    
    
    
    
    //Decryption
    mpz_class dec = power1(enc, dnew, n);
    cout<<"THE DECRYPTED MESSAGE IS: "<<dec;
    
    
    
    ptrrsa =fopen("rsapri.txt", "w");
    

    
    
    temp_f = a.get_str();
    strcpy(temp_a, temp_f.c_str());
    fprintf(ptrrsa, "%ld %s ",temp_f.length(),temp_a);
    fclose(ptrrsa);
    
    
    
   
    
    
    mpz_class temp_[n_d];      //stores the witnesses generated
    //creates witnesses for d's generated by dealer
    signature_gen(p1,n_d,enc,n,temp_);
    
    mpz_class temp_w[n_d];     //stores witnesses for our di's
    mpz_class g;
    
    g = witness_gen(p1, n_d, enc, n, temp_w);
    
   
     signature_ver(p1, n_d, enc, p, temp_w,temp_,g,p_phi);
    
    //what is the aim of loop and temp array here , check
    mpz_class temp_d[n_d] ;
    int i;
    dec=1;
    for(i=0;i<n_d;i++){
        
       dec *=temp_d[i];
        
    }
    
    
    
    
     /* tabish's method of verifying signature by using c = d +d'
    //write a function for this;
    //tabish's method where we dont send inverse of d but use c= di + di'. send g^di' and c to dealer who verifies by multiplying g^di' with g^di if equal to g^c then correct
    mpz_class C;
    C = a * rand();
    while(C<(2*a/n_d)){
        C= a*rand();
    }
    
    
    
    
   
    mpz_class temp_d_c[n_d];   // holds g^di'
    mpz_class d_temp[n_d];     //holds di'=C-di
    for (i=0; i<n_d; i++) {
        d_temp[i] = C - p1[i];
       g = witness_gen(d_temp, n_d, g, n, temp_d_c);
    }
    mpz_class tempo=1;
     mpz_class tempo1=1;
    for (i=0; i<n_d; i++) {
        tempo= temp_w[i]*temp_d_c[i]%n;
        tempo1 = power1(g, C, n);
        if (tempo==tempo1) {
            cout<<"VERIFIED T"<<'\n';
        }
        else
            cout<<"NOT VERIFIED T"<<'\n';
            
    }
    
    
    */
    
    
    
    mpz_class d_ver[n_d];   //new array to take values from user for additive shares di to check for correctness
    
    //replace this loop by cin for taking d shares from parties directly
    for(i=0;i<n_d;i++){
        
        d_ver[i]=p1[i];
    }
    
    //function to verify the additive shares by signatures already generated above
   
    
    
    
    
    /*
    //signature generation without function
    mpz_class sig_temp[n_d],temp_sig=1;
    for(i=0; i<n_d; i ++)
    {
        sig_temp[i]= power1(m, p1[i], n);
        cout<<"sig is :"<<sig_temp[i]<<'\n';
        temp_sig*= sig_temp[i];
        
    }
   
    cout<<"signature gen final:"<<temp_sig;
    */
    
    
    
    
   
    
    //Shamir threshold to distribute n_d d's to n_m new parties where any n_t can reconstruct d's
    int n_t = 3;
    int n_m = 5;
    int w = 10;
    mpz_class temp2;
    mpz_class thresh[n_m];
    mpz_class commit_pt[n_d][n_t];
    mpz_class array[n_d][w+3];
  
    /*
    int **xo;
    
    //obtain values for rows & cols
    // allocate the array
    xo = malloc(n_d * sizeof *xo);
    for (i=0; i<n_d; i++)
    {
        xo[i] = malloc(n_t * sizeof *xo[i]);
    }
    
    */

   
   
  /* proactive refresh including vss
    timer_new2(proactive_refresh, p1, n_d, p_phi, d_ref, n_t, thresh, array, commit_pt, 10);
    
   
    timer_new2(proactive_refresh1, p1, n_d, p_phi, d_ref, n_t, thresh, array, commit_pt, 10);
    
    */
    
  //  timer_final(proactive_refresh1, p1, n_d, p_phi, d_ref, n_t, thresh, array, commit_pt, 10);
    
   // p1[0]=10;
    for(i=0;i<n_d-1;i++){
        
        temp2 = p1[i]; //generate small shares for time being because prime generation in very slow for large numbers.
        
        //cout<<"share is :"<<temp2<<'\n';
       
    
        
        
       
        
        
        VSS(temp2,n_t,&thresh[i],&array[i][0], &commit_pt[i][0]);
    }
    //mpz_class *array_test = commit_pt[0];
    
    
    /*check if commitments were actually stored in 2d array
    for (i=0; i<n_d; i++) {
        for (j=0; j<n_t; j++) {
            cout<<"COMMITMENTS ARE : "<<commit_pt[i][j]<<'\n';
        }
    }
    */
    
    //using index array to take values of i from user corresponding to values of shares for the i that have been input
    
    int index[w];
    for (i=0; i<w; i++) {
        index[i]=i;
        
    }
    
    
    for (i=0; i<n_d-1; i++) {
        VSS_verify(&commit_pt[i][0], array[i][0], array[i][1], array[i][2], n_t, &array[i][0],index);
        
    }
    
    
//first we need to create additive shares, then create signatures for additive shares , then for each additive share use VSS to generate backup , then use signature verification to verify signature and for incorrect di we need to reconstruct that di using vss_verify
   // timer_start(do_something, 100);
    
    
    return 0;
    
    
    
}











    


