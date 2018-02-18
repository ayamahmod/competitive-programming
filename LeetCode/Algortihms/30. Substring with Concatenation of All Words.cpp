class Solution {
public:

    vector<int> findSubstring(string s, vector<string>& words) {
      vector<int> result;
      if(s=="" || words.size()==0 || s.size()<words[0].size())
        return result;
      map<string, int> p;
      for(int i=0;i<words.size();i++)
        p[words[i]]++;

      int len=words[0].size();

      for(int i=0;i<len;i++){
        map<string,int> currP;
        int count=0, start=i;

        for(int j=i;j<=s.size()-len;j+=len){
          string str=s.substr(j,len);
          if(p.find(str)!=p.end()){
            currP[str]++;
            count++;
            while(currP[str]>p[str]){
              string left=s.substr(start,len);
              currP[left]--;
              count--;
              start+=len;
            }
            if(count==words.size()){
              result.push_back(start);
              string left=s.substr(start,len);
              currP[left]--;
              count--;
              start+=len;
            }
          }
          else{
            currP.clear();
            start=j+len;
            count=0;
          }
        }
      }
      return result;
    }
};
