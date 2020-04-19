
			// LONGEST COMMON SUBSEQUENCE    O(m*n)
#include <bits/stdc++.h>
using namespace std;

int lcshelper(char *s1,char *s2,int m,int n,int** dp)
{
    if(m==0 || n==0)
    {
        return 0;
    }
    if(dp[m][n]>-1)
    {
        return dp[m][n];
    }
    int ans;
    if(s1[0]==s2[0])
    {
        ans = 1+lcshelper(s1+1,s2+1,m-1,n-1,dp);
    }else
    {
        int op1 = lcshelper(s1,s2+1,m,n-1,dp);
        int op2 = lcshelper(s1+1,s2,m-1,n,dp);
        ans = max(op1,op2);
    }
    dp[m][n] = ans;
    return ans;
}
int lcsiterative(string s1,string s2)
{
    int m=s1.length();
    int n= s2.length();
    int **dp = new int *[m+1];
    for(int i=0;i<=m;i++)
    {
        dp[i] = new int [n+1];
    }
    for(int i=0;i<=m;i++)
    {
        dp[i][0]=0;
    }
    for(int i=0;i<=n;i++)
    {
        dp[0][i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if (s1[m - i] == s2[n - j]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}	else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
        }
    }
    int ans = dp[m][n];
    for(int i=0;i<=m;i++)
    {
        delete [] dp[i];
    }
    delete[] dp;
    return ans;
}
int lcs(string s1, string s2){

    int m = s1.length();
    int n = s2.length();
    char a[m+1],b[n+1];
    strcpy(a,s1.c_str());
    strcpy(b,s2.c_str());
    int **dp = new int *[m+1];
    for(int i=0;i<=m;i++)
    {
        dp[i] = new int[n+1];
        for(int j=0;j<=n;j++)
        {
            dp[i][j]=-1;
        }
    }
    int ans = lcshelper(a,b,m,n,dp);
	for(int i=0;i<=m;i++)
    {
        delete [] dp[i];
    }
    delete[] dp;
    return ans;

}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<lcs(s1,s2)<<"\n";
	cout<<lcsiterative(s1,s2)<<"\n";
	return 0;
}
