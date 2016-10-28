class Solution {
public:
    void KmpPreprocess(const string& P, vector<int>& v){
        int i = 0, j = -1; v[0] = -1;
        while (i < P.size()) {
            while (j >= 0 && P[i] != P[j]) j = v[j];
            i++; j++;
            v[i] = j;
        }
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<' ';
        cout<<endl;
    }

    int KmpSearch(const string& T, const string& P, vector<int>& v){
        int i=0,j=0;
        while(i<T.size()){
            cout<<i<<' '<<j<<endl;
            while(j>=0 && T[i]!=P[j])   j=v[j];
            i++;    j++;
            if(j==P.size())
                return i-j;
        }
        return -1;
    }
    int strStr(string haystack, string needle) {
        if(needle=="")  return 0;
        vector<int> v(needle.size()+1,0);
        KmpPreprocess(needle, v);
        return KmpSearch(haystack, needle, v);
    }
};
