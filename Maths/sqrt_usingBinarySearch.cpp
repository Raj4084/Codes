#include<bits/stdc++.h>
using namespace std;

int main()
{

	int n,low,high,mid,ans=1;

	cout<<"Enter number: ";
	cin>>n;

	// search space  1 to n
	low =1;
	high=n;

	while(low!=high)
	{
		ans = (low + high)/2;
		if((ans*ans)==n || low == (low + high)/2)
		{
			break;
		}
		else
		{
			if((ans*ans)<n)
			{
				low = ans;
			}
			else
			{
				high = ans;
			}
		}
	}


	cout<<ans;






	cout<<"\n";
	return 0;
}