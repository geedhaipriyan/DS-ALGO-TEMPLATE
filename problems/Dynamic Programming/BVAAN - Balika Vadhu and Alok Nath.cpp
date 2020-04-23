#include <bits/stdc++.h>
using namespace std;
int dp[101][101][101];
int kcshelper(char *s1,char *s2,int n,int m,int k)
{
    if(k==0)
    {
        return 0;
    }
    if(m==0 || n==0)
    {
        return INT_MIN;
    }
    if(dp[n][m][k]!=-1)
    {
        return dp[n][m][k];
    }
    
    if(s1[0]==s2[0])
    {
        return dp[n][m][k] = max((int(s1[0])+kcshelper(s1+1,s2+1,n-1,m-1,k-1)),max(kcshelper(s1,s2+1,n,m-1,k),kcshelper(s1+1,s2,n-1,m,k)));
	}
    return dp[n][m][k] = max(kcshelper(s1,s2+1,n,m-1,k),kcshelper(s1+1,s2,n-1,m,k));
}
int kcs(string s1,string s2,int k)
{
    int n=s1.length(),m=s2.length();
    char a[n+1],b[m+1];
    strcpy(a,s1.c_str());
    strcpy(b,s2.c_str());
    int count = kcshelper(a,b,n,m,k);
    return count;
}
int main()
{
    int t,k;
    cin>>t;
	string s1,s2; 

    while(t--)
    {
        memset(dp,-1,sizeof dp);

        cin>>s1>>s2>>k;
        int cal = kcs(s1,s2,k);
 		if(cal<0)
        {
            cal=0;
        }
        cout<<cal<<"\n";
    }
	return 0;
}

