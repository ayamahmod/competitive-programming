//http://codeforces.com/problemset/problem/133/A
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	char*ptr;
	ptr=&s[0];
	for(int i=0;i<strlen(ptr);i++)
	{
		if(ptr[i]=='H' || ptr[i]=='Q' || ptr[i]=='9')
			{cout<<"YES"<<endl;
		     return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
