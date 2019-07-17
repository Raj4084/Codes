/*Sequence (ai) of natural numbers is defined as follows:

   ai = bi (for i <= k)
   ai = c1ai-1 + c2ai-2 + ... + ckai-k (for i > k)

where bj and cj are given natural numbers for 1<=j<=k. Your task is to compute an for given n and output it modulo 10^9.

*/
/*
Input
On the first row there is the number C of test cases (equal to about 1000).
Each test contains four lines:

k - number of elements of (c) and (b) (1 <= k <= 10)
b1,...,bk - k natural numbers where 0 <= bj <= 109 separated by spaces
c1,...,ck - k natural numbers where 0 <= cj <= 109 separated by spaces
n - natural number (1 <= n <= 109)
*/

#include<bits/stdc++.h>
using namespace std;

#define Mod 1000000000
#define ll long long

ll k;
vector<ll>a,b,c;



// multiply two matrices

vector< vector<ll> > multiply( vector< vector<ll> > A, vector< vector<ll> > B )
{
	vector< vector<ll> > C( k+1,vector<ll>(k+1,0) ); // for store the result

	int i,j,x;
	for(i=1;i<=k;i++)
	{
		for(j=1;j<=k;j++)
		{
			for(x=1;i<=k;x++)
			{
				C[i][j] = (C[i][j] + (A[i][x]*B[x][i])%Mod)%Mod;
			}
		}
	}

	return C;

}


vector< vector<ll> > power( vector< vector<ll> > a, ll b )
{

	//base case
	if(b==1)	return a;

	// rec case
	if(b&1)
	{
		return multiply( a,power(a,b-1) );
	}
	else
	{
		vector< vector<ll> > x = power(a,b/2);
		return multiply(x,x);
	}

}


ll compute(ll n)
{
	int i,j;
	//base case
	if(n==0)	return 0;

	// n<=k
	if(n<=k)	return b[n-1];

	// otherwie use matrix exponentiation ....... index start from 1;
	vector<ll> F1(k+1);
	for(i=1;i<=k;i++)
	{
		F1[i] = b[i-1];
	}

	// transformation matrix
	vector< vector<ll> > T( k+1,vector<ll>(k+1,0) ) ; // 2d vector of size (k+1)*(k+1)

	for(i=1;i<=k;i++)
	{
		for(j=1;j<=k;j++)
		{
			if(i<k)
			{
				if(i==j+1)
					T[i][j]=1;
				else
					T[i][j]=0;

				continue;
			}
			// for last row store coeficient in reverse order
			T[i][j] = b[k-j];


		}
	}

	// compute T^(n-1);

	T = power(T,n-1);

	// multiply T by F1(only get the top value) 

	ll res = 0; 
	for(i=1;i<=k;i++)
	{
		res = (res + (T[1][i]*F1[i])%Mod)%Mod;
	}

	return res;

}

int main()
{

	ll t,i,j,num,n;
	cin>>t;

	while(t--)
	{
		cin>>k;

		// b , initial vector F1
		for(i=0;i<k;i++)
		{
			cin>>num;
			b.push_back(num);
		}

		// coeficient vector
		for(i=0;i<k;i++)
		{
			cin>>num;
			c.push_back(num);

		}

		// value of n;
		cin>>n;
		cout<<compute(n)<<"\n";

		b.clear();
		c.clear();



	}



	return 0;
}




















