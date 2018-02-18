class Solution {
public:
    string countAndSay(int n) {
        if(n==0 || n==1)
            return "1";
        string str="1";
        for(int i=2;i<=n;i++){
            string s="";
            string LastChar="";
            int LastCount=0;
            for(int j=0;j<str.size();j++){
                string portion=str.substr(j,1);
                if(LastChar=="")   {  LastChar=portion;    LastCount=1; }
                else if(portion==LastChar)    LastCount++;
                else{
                    s.append(to_string(LastCount));
                    s.append(LastChar);
                    LastChar=portion;   LastCount=1;
                }
            }
            s.append(to_string(LastCount));     s.append(LastChar);
            str=s;
            //cout<<str<<endl;
        }
        return str;
    }
};
