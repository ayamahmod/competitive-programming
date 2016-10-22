class Solution {
public:
    Solution(): arr{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}, chars{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}
    {
      for(int i=0;i<13;i++)
        m[chars[i]]=arr[i];
    }
    int romanToInt(string s) {
        int prev=4000;
        int y=0;
        for(int i=0;i<s.size();i++){
          int temp=m[s.substr(i,1)];
          if(temp>prev)
              {temp=m[s.substr(i-1,2)];   y-=prev;}
          //cout<<temp<<endl;
          y+=temp;
          prev=temp;
        }
        return y;
    }
  private:
    int arr[13];
    string chars[13];
    unordered_map<string,int> m;
};
