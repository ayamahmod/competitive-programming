//http://codeforces.com/problemset/problem/231/A
#include<iostream>
using namespace std;
int main()
{
	int n,x,y,z,num=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y>>z;
	if((x+y==2)||(y+z==2)||(x+z==2))
		num++;
	}
	cout<<num<<endl;
	return 0;
}
