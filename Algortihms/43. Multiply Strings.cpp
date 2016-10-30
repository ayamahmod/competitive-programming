class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")  return "0";
        string smaller=num1.size()>num2.size()? num2:num1;
        string bigger=num1.size()>num2.size()? num1:num2;
        string result="";
        int shift=0;
        for(int i=smaller.size()-1;i>=0;i--){
            string temp=Multiply_1digit(smaller[i], bigger);
            Add(result, temp, shift++);
        }
        return result;
    }

    string Multiply_1digit(char ch, const string& str){
        string result="";
        int c=0;
        int multip=ch-'0';
        for(int i=str.size()-1;i>=0;i--){
            int temp=multip*(str[i]-'0')+c;
            c=temp/10;
            result=(char)('0'+temp%10)+result;
        }
        if(c!=0)
            result=(char)('0'+c)+result;
        //cout<<multip<<' '<<str<<' '<<result<<endl;
        return result;
    }

    void Add(string& result, string& part_result, int shift){
        //cout<<"IN"<<endl;
        //cout<<result<<' '<<part_result<<' '<<shift<<endl;
        if(result=="")  result=part_result;
        else{
            int i=0, j=part_result.size()-1;
            int c=0;
            for(i=result.size()-1-shift; i>=0 && j>=0; i--,j--){
                int temp=(result[i]-'0')+(part_result[j]-'0')+c;
                result[i]=(temp%10) +'0';
                c=temp/10;
            }
            while(j>=0){
                int temp=(part_result[j]-'0')+c;
                c=temp/10;
                result=(char)('0'+temp%10)+result;
                j--;
            }
            while(c!=0 && i>=0){
                int temp=(result[i]-'0')+c;
                c=temp/10;
                result[i]=(temp%10) +'0';
                i--;
            }
            if(c!=0)
                result=(char)(c+'0')+result;
        }
        //cout<<result<<' '<<part_result<<' '<<shift<<endl;
        //cout<<"OUT"<<endl;
    }
};
