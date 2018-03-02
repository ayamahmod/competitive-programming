#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    int n,temp;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr.begin(),arr.end());
    
    long long moves=0;
    for(int i=0;i<n;i++)
        moves+=abs(i+1-arr[i]);
    
    cout<<moves<<endl;
    return 0;
}