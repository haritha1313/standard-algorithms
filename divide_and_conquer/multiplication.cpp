#include <iostream>
#include <string>
using namespace std;

int equaliselen(string &str1, string &str2)
{
    int l1, l2, i;
    l1 = str1.length();
    l2 = str2.length();
    if(l1>l2)
    {
        for(i=0;i<l1-l2;i++)
        {
            str2 = '0'+str2;
        }
        return l1;
    }
    else
    {
        for(i=0;i< l2-l1;i++)
        {
            str1 = '0'+str1;
        }
        return l2;
    }
}

string findsum(string a, string b)
{
    string ans;
    int len = equaliselen(a, b);
    int c = 0;
    
    for(int i = len-1; i>=0; i--)
    {
        int bit1 = a.at(i) - '0';
        int bit2 = b.at(i) - '0';
        
        int sum = (bit1 ^ bit2 ^ c) + '0';
        ans = (char)sum + ans;
        c = (bit1&bit2)|(bit1&c)|(bit2&c);
    }
    if(c)
        ans = '1'+ans;
    
    return ans;
}

long int multiply(string op1, string op2)
{
    int len = equaliselen(op1, op2);
    
    if(len==0) 
        return 0;
    else 
        if(len==1)
            return ((op1[0]-'0')*(op2[0]-'0'));
    
    int left = len/2;
    int right = len - left;
    
    string lsub1 = op1.substr(0, left);
    string rsub1 = op1.substr(right, len);
    
    string lsub2 = op2.substr(0, left);
    string rsub2 = op2.substr(right, len);
    
    long int v = multiply(lsub1, lsub2);
    long int w = multiply(rsub1, rsub2);
    long int u = multiply(findsum(lsub1, rsub1), findsum(lsub2, rsub2));
    
    return (v*(1<<(2*right))+((u-v-w)*(1<<right))+w);
}

int main()
{
    string operand1, operand2;
    cout<<"Enter input number 1 as bit string\n";
    cin>>operand1;
    cout<<"Enter input number 2 as bit string\n";
    cin>>operand2;
    cout<<"Product: "<<multiply(operand1, operand2)<<"\n";
    return 0;
}