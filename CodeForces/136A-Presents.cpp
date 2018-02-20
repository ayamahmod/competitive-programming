//http://codeforces.com/problemset/problem/136/A
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int*ptr=new int[n];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		ptr[k-1]=i;
	}
	for(int i=0;i<n;i++)
		cout<<ptr[i]<<" ";
	cout<<endl;
	return 0;
}
//http://codeforces.com/contest/136/submission/3200997
