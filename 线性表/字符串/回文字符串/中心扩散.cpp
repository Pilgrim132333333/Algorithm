#include<iostream>
#include<string>
using namespace std;
class Solution{
    public:
    string add_char(string &str)
    {
        string s="#";
        for(int i=0;i<str.size();i++)
        {
            s+=str[i];
            s+='#';
        }
        return s;
    }
    string Solutiona(string s)
    {
        string str=add_char(s);
        int max_len=0;
        int middle_index=-1;
        for(int i=1;i<str.size();i++)
        {
            int left=i-1;
            int right=i+1;
            while(left>=0&&right<str.size()&&str[left]==str[right])
            {
                left--;
                right++;
                if(right-left>max_len)
                {
                    max_len=max(max_len,right-left);
                    middle_index=i;
                }
            }
        }
        string res="";
        printf("%s\n",str.c_str());
        for(int i=middle_index-(max_len-1)/2+1;i<=middle_index+(max_len-1)/2;i+=2)
        {
            res+=str[i];
        }
        return res;
    }
};

int main() {
    Solution solution;
    string s = "bb";
    string result = solution.Solutiona(s);
    cout << "Longest palindromic substring: " << result << endl;
    return 0;
}
