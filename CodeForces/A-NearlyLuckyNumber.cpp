//http://codeforces.com/problemset/problem/110/A
#include<iostream>
using namespace std;
bool check_lucky(int num);
int main()
{
	unsigned long long int n=0,temp,factor=1;
	int yes=0,x;
	bool condition;
	cin>>n;
	temp=n;
	while(temp)
	{
		temp=temp/10;
		factor=factor*10;
	}
	while(factor>1)
	{
		factor=factor/10;
		x=n/factor;
		if(x==4 || x==7)
			yes++;
		n=n%factor;
	}
	if(check_lucky(yes))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
bool check_lucky(int num)
{
	if(num==0)
		return false;
	int temp=num,factor=1,x;
	while(temp)
	{
		temp=temp/10;
		factor=factor*10;
	}
	while(factor>1)
	{
		factor=factor/10;
		x=num/factor;
		if(x!=4 && x!=7)
		{
			return false;
		}
		num=num%factor;
	}
	return true;
}
//http://www.codeforces.com/contest/110/submission/3201208
