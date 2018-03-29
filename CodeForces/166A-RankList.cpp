// http://codeforces.com/problemset/problem/166/A
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
	int n,k,p,t,sum=0;
	cin>>n>>k;
	int*ptr=new int [n+1];
	for(int i=0;i<n;i++)
	{
		cin>>p>>t;
		ptr[i]=100*p+100-t;
	}
	sort(&ptr[0],&ptr[n]);
	for(int i=0;i<n;i++)
		if(ptr[i]==ptr[n-k])
			sum++;
	cout<<sum<<endl;
	return 0;
}
