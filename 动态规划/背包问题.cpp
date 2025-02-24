class Solutioon{
    public:
    //n件物品，背包最多承受w重量的物品
    int maxProfit(vector<int>& price,vector<int>& weight,int w,int n)
    {
        vector<vector<int>> dp(n);
        for(int i=0;i<n;i++)
        {
            dp[i].resize(w=1,0);
        }
        //dp[i][j]表示前i件物品，假如背包最大重量为j，那么dp[i][j]就是其最大价值
        for(int i=0;i<w+1;i++)
        {
            if(i>=weight[0])
            {
                dp[0][i]=price[0];

            }
        }
        //完成初始化

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<w+1;j++)
            {
                if(j<weight[i])
                {
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=max(d[i-1][j],dp[i-1][j-weight[i]+price[i]]);
                }
            }
        }
        return dp[i-1][w];
    }
    
    int maxProfit2(vector<int>& price,vector<int>& weight,int w,int n)
    {
        vector<int> dp(w+1,0);
        for(int i=0;i<w+1;i++)
        {
            if(i>=weight[0])
            {
                dp[i]=price[0];
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=w;j>=0;j--)
            {
                if(j>=weight[i])
                {
                    dp[j]=max[dp[j],dp[j-weight[i]]+price[i]]
                }
            }
        }
        return dp[w];
    }
    
}