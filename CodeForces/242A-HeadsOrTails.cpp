//http://codeforces.com/problemset/problem/242/A
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int x,y,a,b,sum=0;
	vector<int> myvector;
	cin>>x>>y>>a>>b;
	for(int i=a;i<=x;i++)
	{
		for(int k=b;k<=y;k++)
			if(i>k)
			{
				sum++;
				myvector.push_back(i);
				myvector.push_back(k);
			}
	}
	cout<<sum<<endl;
	int i=0;
	for(int k=0;k<sum;k++)
	{
		cout<<myvector[i]<<" "<<myvector[i+1]<<endl;
		i+=2;
	}

	return 0;
}
