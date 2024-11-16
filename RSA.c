#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int eulers_totient(int p, int q);
int encryption_exponent(int toitent);
int decryption_exponent(int exponent, int toitent);
int gcd(int x, int y);
long long int encryption_using_public_key(int m,int e,int n);
void decryption_using_private_key(int c,int d,int n);

void main()
{
	char a[] = "a";
	printf("%s", a);
	int finalVal = 0;
	int length = strlen(a);
	for (int i = 0; i < length; i++)
	{
		finalVal += a[i];
	}
	printf("\n string in int is: %d", finalVal);
	int p = 11;
	int q = 17;
	int totient = eulers_totient(p, q);
	printf("%d", totient);
	int exponenet = encryption_exponent(totient);
	printf("\n Public key= (%d,%d)", exponenet, totient);
	int decryption = decryption_exponent(exponenet, totient);
	printf("\n Private key= (%d,%d)", decryption, totient);
	long long int c=encryption_using_public_key(2,exponenet,totient);
	decryption_using_private_key(c,decryption,totient);
}

int eulers_totient(int p, int q)
{
	int ans = 0;
	ans = (p - 1) * (q - 1);
	return ans;
}

int encryption_exponent(int toitent)
{
	// finding a coprime value with the toitent
	// coprime is when the greatest common factor of 2 numbers is 1. We have the toitent has one of the number, we need to find the other which is our encryption_exponent
	int max = 0;
	for (int i = 0; i < toitent / 1024; i++)
	{
		int ans = gcd(toitent, i);
		// printf("\ncurrent gcd(%d,%d)= %d", toitent, i, ans);
		if (ans == 1)
		{
			if (i > max)
			{
				max = i;
			}
		}
	}
	printf("\nFINAL GCD = %d", max);
	return 7;
	return max;
}

int gcd(int x, int y)
{
	// this is to find the GCD of the two numbers

	// previous diviser/ previous remainder
	//  divide the x,y  and get remainder. (1786/546)=> remainder=147
	//  divide the y with the remainder  (546/147)=>remainder=105
	//  (147/105)=> remainder=42
	//  (105/42)=>remainde=21
	//  (42/21)=>remainder=0 (STOP). so last remainder is GCD so here, it is 21
	if (y == 0)
	{
		return x;
	}
	return gcd(y, x % y);
}

int mod_inverse(int e, int totient)
{
	// extended euclian algorithm
	int t1 = 0, t2 = 1, r1 = totient, r2 = e, q, t, r;

	while (r2 > 0)
	{
		q = r1 / r2;
		r = r1 - q * r2;
		t = t1 - q * t2;
		r1 = r2;
		r2 = r;
		t1 = t2;
		t2 = t;
	}

	if (r1 > 1)
	{
		printf("no modular inverse");
		return -1;
	}

	if (t1 < 0)
	{
		t1 += totient;
	}

	return t1;
}
int decryption_exponent(int encryption_exponent, int eulers_totient)
{
	// d=e^-1 mod(totient)
	return mod_inverse(encryption_exponent, eulers_totient);
}

//Note: Encryption and decryption functionality is still incomplete. Work is pending on these parts.


long long int encryption_using_public_key(int m,int e,int n){
	//c=m^e mod n
	// printf("Hello world");
	// int ans=2;
	// int final=1;
	// for (int i=0;i<4;i++){
	// 	// final=final*ans;
	// 	printf("%d",ans);
	// }
	// printf("\n ANS ANS ANS %d\n",ans);
	int ans=m;
	long long int final=1;
	for(int i=0;i<e;i++){
		final=final*ans;
	}
	long long int final_final=final%n;
	printf("This is the module value: %lld",final_final);
	return final_final;
}

void decryption_using_private_key(int c,int d,int n){
	int ans=c;
	printf("c:%d d:%d n:%d",c,d,n);
	long long int final=1;
	for (int i=0;i<d;i++){
		final=final*ans;
		printf("\n%lld",final);
	}
	long long int final_final=final%n;
	printf("\nThis is the decrypted value: %lld",final_final);
}
