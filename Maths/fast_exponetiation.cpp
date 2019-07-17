#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll power(ll a,ll b)
{
	// base case
	if(b==0)	return 1;

	ll ans;
	// recurcive case if b is odd or even
	ans = power(a,b/2);

	ans  = ans*ans;

	//if b is odd

	if(b&1)
	{
		ans = ans*a;
	}

	return ans;



}


int main()
{

	ll a,b,ans;


	cin>>a>>b;

	ans = power(a,b);

	cout<<ans;


	cout<<"\n";
	return 0;
}