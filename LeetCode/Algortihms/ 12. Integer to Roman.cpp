class Solution {
public:
    Solution(): arr{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}, chars{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}
    {}
    string intToRoman(int num) {
        int div=1;
        string s="";
        while(num){
            int x=(num%10)*div;
            string temp="";
            Roman(temp, x);
            temp.append(s);
            s=temp;
            num/=10;
            div*=10;
        }
        return s;
    }

    void Roman(string& temp, int x){
        if(x==0) return;
        for(int i=0;i<13;i++){
          if(x>=arr[i]){
            temp.append(chars[i]);
            x-=arr[i];
            break;
          }
        }
        Roman(temp,x);
    }
  private:
    int arr[13];
    string chars[13];
};
