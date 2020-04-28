#include <bits/stdc++.h>
using namespace std;
bool subsetSum(int* val,int n,int sum){

	bool** dp = new bool*[2];
	for(int i=0;i<=1;i++){
		dp[i] = new bool[sum+1];
	}

	for(int i=0;i<=sum;i++){
		dp[0][i] = false;
	}
	dp[0][0] = true;

	int flag = 1;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){

			dp[flag][j] = dp[flag^1][j];

			if(j>=val[i-1]){
				dp[flag][j] = dp[flag][j] || dp[flag^1][j-val[i-1]];
			}
		}
		flag = flag ^ 1;
	}
	bool ans = dp[flag^1][sum];
	delete [] dp;
	return ans;
}
bool subsetsum(int a[],int n,int sum)
{
    bool dp[n+1][sum+1];
    for(int i=0;i<=sum;i++)
    {
        dp[0][i]=false;
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=true;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
    		
                dp[i][j] = dp[i-1][j];
                if(j>=a[i-1])
                {
                    dp[i][j] = dp[i][j] || dp[i-1][j-a[i-1]];
                }
            
        }
    }
    return dp[n][sum];
}
int main()
{
    int n,sum;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>sum;
    cout<<(subsetSum(a,n,sum)?"Yes":"No");
    return 0;
}
