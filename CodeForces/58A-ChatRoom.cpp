//http://codeforces.com/problemset/problem/58/A
#include<iostream>
#include<string>
using namespace std;
int main()
{
string hello="hello";
string temp;
cin>>temp;
int it=0;
int counter=0;
for(int i=0;i<temp.length()&&counter!=5;i++)
	if(temp[i]==hello[it])
		{it++;		counter++;}
if(counter==5)
	cout<<"YES"<<endl;
else
	cout<<"NO"<<endl;
return 0;
}
