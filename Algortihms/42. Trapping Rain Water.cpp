class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0)    return 0;
        vector<int> left(height.size(),0);
        vector<int> right(height.size(),0);
        left[0]=height[0];
        for(int i=1;i<left.size();i++)
            left[i]=max(left[i-1], height[i]);
        right[height.size()-1]=height[height.size()-1];
        for(int i=height.size()-2; i>=0; i--)
            right[i]=max(right[i+1], height[i]);

        int water=0;
        for(int i=0;i<height.size();i++){
            water+=min(left[i],right[i])-height[i];
        }
        return water;
    }
};
