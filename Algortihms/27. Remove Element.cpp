class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int counter=0;
        bool isEqual=false;
        for(int i=0,j=0; i<nums.size(); i++){
            if(val==nums[i]){counter++;  isEqual=true;}
            else    isEqual=false;
            if(!isEqual)
                nums[j++]=nums[i];
        }
        return nums.size()-counter;
    }
};
