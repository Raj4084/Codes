#include<bits/stdc++.h>
using namespace std;

//int n =1;

int multiply(int a[],int &n,int no)
{
	int carry = 0,i,p;

	for(i=0;i<n;i++)
	{
		p = no*a[i] + carry;
		a[i] = p%10;
		carry = p/10;
	}

	while(carry)
	{
		a[n] = carry % 10;
		carry /= 10;
		n++;
	}

	return n;

}

int main()
{

	int num,i,n;
	int a[1000] = {0};

	cout<<"Enter the number:	";
	cin>>num;

	a[0] = 1; // 0! = 1,   1! = 1
	n=1;     //  n is number of digit

	// 5! = 1*2*3*4*5
	for(i=2;i<=num;i++)
	{
		 multiply(a,n,i);
	}


	// print in reverse order
	for(i=n-1;i>=0;i--)
	{
		cout<<a[i];
	}
	cout<<"\n";

	cout<<n;

	return 0;
}