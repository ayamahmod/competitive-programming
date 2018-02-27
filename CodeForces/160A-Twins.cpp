//http://codeforces.com/problemset/problem/160/A
#include<iostream>
using namespace std;
void insertionSort (int list[],int last);
int main()
{
	int n,sum=0,c=0,t=0;
	cin>>n;
	int*ptr= new int[n];
	for(int i=0;i<n;i++)
	{
			cin>>ptr[i];
			sum+=ptr[i];
	}
	insertionSort(ptr,n-1);
	for(int i=n-1;i>=0;i--)
	{
		t+=ptr[i];
		c++;
		if(t>(sum/2))
			break;
	}
	cout<<c<<endl;
	return 0;
}
void insertionSort(int list[],int last)
{
	int current;
	int hold;
	int walker;
	for (current=1;current<=last;current++)
	{
		hold=list[current];
		for(walker=current-1;walker>=0&&hold<list[walker];walker--)
			list[walker+1]=list[walker];
		list[walker+1]=hold;
	}
	return;
}
