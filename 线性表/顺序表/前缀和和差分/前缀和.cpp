//前缀和用于快速求解线性表中第m项和第n项之间所有数字和
//创建数组存储，第i位为前i个数总和
//代码为二维前缀和
#include<iostream>

int main()
{
    int m=5,n=5;
    int s[m][n]={{0}};
    for (int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            s[i][j]=0;
        }
    }

    
    for(int i=1;i<5;i++)
    {
        for(int j=1;j<5;j++)
        {
            scanf("%d",&s[i][j]);
        }
    }

    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
                s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }

    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",s[i][j]);
        }
        printf("\n");
    }

    
}