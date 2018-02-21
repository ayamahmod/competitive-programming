//http://codeforces.com/problemset/problem/155/A
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int sum=0;
	int biggest;
	int smallest;
	int*ptr=new int[n];
	cin>>ptr[0];
	biggest=ptr[0];
	smallest=ptr[0];
	for(int i=1;i<n;i++)
	{
		cin>>ptr[i];
		if(ptr[i]>biggest)
			{
				biggest=ptr[i];
				sum++;
		}
		else if(ptr[i]<smallest)
		{
			smallest=ptr[i];
			sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
}
