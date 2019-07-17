// size of array is n
// find total number of possible sub array which is divisible by k


#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,i,k;
	cout<<"Enter size of array: ";
	cin>>n;

	cout<<"Enter k: ";
	cin>>k;

	int a[n],c[n+1],f[k]={0};// c is cumulative sum of a,..... f is frequency of element c[i]%k;

	cout<<"Enter element of array: ";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}

	c[0] = 0;
	for(i=0;i<n;i++)
	{
		c[i+1] = c[i] + a[i];
	}

	// calculate c[i]%n

	for(i=0;i<=n;i++)
	{
		c[i+1]%=k;
	}

	for(i=0;i<=n;i++)
	{
		f[c[i]]++;
	}


	int ans = 0,num;


	for(i=0;i<k;i++)
		cout<<f[i]<<" ";

	for(i=0;i<k;i++)
	{
		if(f[i])
		{
			num = (f[i]*(f[i]-1))/2;
			ans+=num;
		}

	}


	cout<<"........."<<ans;



	cout<<"\n";
	return 0;
}