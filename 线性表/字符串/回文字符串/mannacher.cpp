#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

class mananacher{
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

    string Mananacher(string &str)
    {
        vector<int> p;
        unordered_set<int> set;
        string s=add_char(str);
        int n=s.size();
        p.resize(n,-1);
        p[0]=0;
        for(int i=1;i<n;i++)
        {
            if(p[i]==-1)
            {
                int left=i-1;
                int right=i+1;
                int count=0;
                while(left>=0&&right<n&&s[left]==s[right])
                {
                    left--;
                    right++;
                }
                p[i]=(right-left)/2-1;  //回文半径
                //更新对称数据
                for(int j=1;j<=p[i];j++)
                {
                   if(p[i+j]==-1)
                   {
                       p[i+j]=p[i-j];
                   }
                }
            }
        }
        int max_index=-1;
        int max_len=-1;
        for(int i=0;i<n;i++)
        {
            if(p[i]>max_len)
            {
                max_len=p[i];
                max_index=i;
            }

        }
        string res="";
        printf("%s %d %d\n",s.c_str(),max_index,max_len);
        for(int i=max_index-max_len+1;i<=max_index+max_len;i+=2)
        {
            res+=s[i];
        }
        return res;


    }
};

int main() {
    mananacher manacher;
    string s = "babad";
    string result = manacher.Mananacher(s);
    cout << "Longest palindromic substring: " << result << endl;
    return 0;
}
