//http://codeforces.com/problemset/problem/219/A
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	int k;
	string s;
	cin>>k>>s;
	if(k==1)
	{cout<<s<<endl;		return 0;}
	else if(s.size()%k!=0)
	{cout<<-1<<endl;	return 0;}

	int arr[26];
	memset(arr,0,sizeof(arr));
	for(int i=0;i<s.size();i++)
		arr[s[i]-'a']++;

	bool cond=true;
	string newS="";
	for(int i=0;i<26 && cond;i++)
	{
		if(arr[i]%k)
			cond=false;
		for(int counter=0;counter<arr[i]/k;counter++)
			newS+='a'+i;
	}
	if(!cond)
		cout<<-1<<endl;
	else
	{
		string ToPrint="";
		for(int counter=0;counter<k;counter++)
			ToPrint+=newS;
		cout<<ToPrint<<endl;
	}

	return 0;
}
