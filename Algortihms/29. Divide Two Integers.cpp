class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0)  return INT_MAX;
        else if(dividend==INT_MIN && divisor==-1)   return INT_MAX;

        unsigned long long pdivisor=abs((long)divisor), pdividend=abs((long)dividend);
        int counter=0;

        while(pdividend>=pdivisor){
            int numShift=0;
            while(pdividend>=(pdivisor<<numShift)) numShift++;
            pdividend-=pdivisor<<(numShift-1);
            counter+=1<<(numShift-1);
        }
        if(divisor>=0 ^ dividend>0)    return -counter;
        return counter;
    }
};
