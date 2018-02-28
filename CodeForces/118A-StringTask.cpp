//http://codeforces.com/problemset/problem/118/A
#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <istream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.size();)
    {
        if(s[i]=='E'||s[i]=='O'||s[i]=='I'||s[i]=='U'||s[i]=='y'||s[i]=='Y'||s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='i'||s[i]=='u'||s[i]=='A')
        {
            s.erase(s.begin()+i);
        }
        else
        {
            if(isupper(s[i]))
            {
                s[i]=tolower(s[i]);
            }
            i++;
        }
        //cout<<'.'<<s[i];
    }
    for(int i=0;i<s.size();i++)
    {
        cout<<'.'<<s[i];
    }
    cout<<'\n';
}
