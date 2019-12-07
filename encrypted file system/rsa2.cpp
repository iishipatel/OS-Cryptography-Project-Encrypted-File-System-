#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
// find gcd
int gcd(int a, int b) {
   int t;
   while(1) {
      t= a%b;
      if(t==0)
      return b;
      a = b;
      b= t;
   }
}
bool encryptText(string msg) {
   //2 random prime numbers
   double p = 23;
   double q = 97;
   double n=p*q;//calculate n
   double track;
   double phi= (p-1)*(q-1);//calculate phi
   //public key
   //e stands for encrypt
   double e=7;
   //for checking that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.
   while(e<phi) {
      track = gcd(e,phi);
      if(track==1)
         break;
      else
         e++;
   }
   //private key
   //d stands for decrypt
   //choosing d such that it satisfies d*e = 1 mod phi
   double d1=1/e;
   double d=fmod(d1,phi);
   long int m[100],en[100],temp[100];
   int i,len,pt,ct,c,z;

	int l = msg.length();
	char msg1[l + 1]; 
	strcpy(msg1, msg.c_str());
	
	
   for (i = 0; msg1[i] != '\0'; i++)
        m[i] = msg1[i];
   
    i = 0;
    len = strlen(msg.c_str());
    while (i != len)
    {
        pt = m[i];
        pt = pt - 96;
        double c = pow(pt,e); //encrypt the message
   		c=fmod(c,n);
   		temp[i] = c;
        ct = c + 96;
        en[i] = ct;
        i++;
    }
    en[i] = -1;
    for (i = 0; en[i] != -1; i++)
        printf("%c", en[i]);
        
//   	for (i = 0; en[i] != -1; i++)
//	{			
//        ct = temp[i];
//        double z = pow(c,d);
//        z=fmod(z,n);
//        pt = z + 96;
//        m[i] = pt;
//    }
//    m[i] = -1;
    cout << "\nTHE DECRYPTED MESSAGE IS\n";
    for (i = 0; i < l ; i++)
        printf("%c", m[i]);
        
    return true;
    
}

