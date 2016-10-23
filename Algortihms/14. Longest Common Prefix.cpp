struct Trie{
    Trie* arr[26];
    int ctr;
    Trie(){
        for(int i=0;i<26;i++)
            arr[i]=NULL;
        ctr=0;
    }
    void IncCtr()
    {ctr++;}
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* root= new Trie();
        for(int i=0;i<strs.size();i++)
            insertInTrie(root,strs[i]);

        return LCP(root,"");
    }

    void insertInTrie(Trie* root,string str){
        Trie* ptr=root;
        ptr->IncCtr();
        for(int i=0;i<str.size();i++){
            int idx=str[i]-'a';
            if(!ptr->arr[idx])
                ptr->arr[idx]=new Trie();
            ptr->arr[idx]->IncCtr();
            ptr=ptr->arr[idx];
        }
    }

    string LCP(Trie* ptr, string str){
        for(int i=0;i<26;i++){
            if(ptr->arr[i] && ptr->arr[i]->ctr==ptr->ctr){
                char b= 'a'+i;
                return LCP(ptr->arr[i], str+b);
              }
        }
        return str;
    }
};
