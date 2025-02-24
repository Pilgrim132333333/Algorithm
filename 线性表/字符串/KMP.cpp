#include<iostream>
#include<vector>
#include<string>
using namespace std;



//关键为next数组的构造
//此处next数组的值表示当前位置前缀长度。

class KMP{
    public:
    //构造next数组
    vector<int> next_struct(string s)
    {
        int n=s.size();
        vector<int> next;
        next.resize(n,0);
        int j=0;
        for(int i=1;i<n;i++)
        {
            while(j>0&&s[i]!=s[j])
            {
                j=next[j-1];
            }
            if(s[i]==s[j])
            {
                j++;
            }
            next[i]=j;
        }
        return next;
    }

    int KMP_Soluation(string s,string t)
    {
        int n_s=s.size();
        int n_t=t.size();
        vector<int> next=next_struct(t);
        int j=0;
        int i=0;
        while(i<n_s)
        {
            while(j>0&&s[i]!=t[j])
            {
                j=next[j-1];
            }
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else{
                i++;
            }
            if(j==n_t)
            {
                return i-j;
            }
        }
        return -1;
    }

};


int main() {
    KMP kmp;
    string s = "ABABDABACDABABCABAB";
    string t = "ABABCABAB";
    int result = kmp.KMP_Soluation(s, t);
    if (result == -1) {
        cout << "Pattern not found in the text." << endl;
    } else {
        cout << "Pattern found at index " << result << endl;
    }
    return 0;
}


