#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    double median2(int x, int y){
      return ((double)(x+y))/2.0;
    }
    double median3(int x,int y, int z){
      return x+y+z-min(x,min(y,z))-max(x,max(y,z));
    }
    double median4(int x, int y, int z, int w){
      return ((double)(x+y+z+w-min(min(x,y),min(z,w))-max(max(x,y),max(z,w))))/2.0;
    }
    double findMedian_1arr(vector<int>& arr, int s, int n){
      if(arr.size()%2==0)
        return ((double)(arr[s+n/2]+arr[s+n/2-1]))/2.0;
      return arr[s+n/2];
    }
    double findMedian_2arr(int s1, int N, int s2, int M){
      if(N==0)
        return findMedian_1arr(nums2, s2, M);
      if(N==1){
        if(M==1)
          return median2(nums1[s1], nums2[s2]);
        if(M&1)
          return median2(nums2[s2+M/2], median3(nums2[s2+M/2-1], nums2[s2+M/2+1], nums1[s1]));
        return median3(nums2[s2+M/2], nums2[s2+M/2-1], nums1[s1]);
      }
      else if(N==2){
        if(M==2)
          return median4(nums1[s1], nums1[s1+1], nums2[s2], nums2[s2+1]);
        if(M&1)
          return median3(nums2[s2+M/2], max(nums1[s1], nums2[s2+M/2-1]), min(nums1[s1+1], nums2[s2+M/2+1]));
        return median4(nums2[s2+M/2], nums2[s2+M/2-1], min(nums1[s1+1], nums2[s2+M/2+1]), max(nums1[s1], nums2[s2+M/2-2]));
      }
      int idx1=(N-1)/2;
      int idx2=(M-1)/2;
      if(nums1[s1+idx1] <= nums2[s2+idx2])
        return findMedian_2arr(s1+idx1, N/2+1, s2, M-idx1);

      return findMedian_2arr(s1, N/2+1, s2+idx1, M-idx1);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1.size() < nums2.size() ? nums1:nums2;
        this->nums2 = nums1.size() < nums2.size() ? nums2:nums1;
        return findMedian_2arr(0, this->nums1.size(), 0, this->nums2.size());
    }
  private:
    vector<int> nums1;
    vector<int> nums2;
};


int main(){
  Solution C;
  vector<int> v1(0);
  vector<int> v2(1);
  v2[0]=1;
  cout<<C.findMedianSortedArrays(v1,v2)<<endl;
}
