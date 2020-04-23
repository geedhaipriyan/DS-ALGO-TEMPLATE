#include<bits/stdc++.h>
#define ll long long int 
#define f(min,max) for(ll i=min;i<=max;i++)
#define f1(min,max) for(ll j=min;j<=max;j++)
#define pair1 pair<ll,ll>
#define mk make_pair
using namespace std;
void maxfun(int *fee,int *funval,int budg,int n)
{
    int dp[n+1][budg+1];
    f(0,n)
    {
        f1(0,budg)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }else
            if(fee[i-1]>j)
            {
            	dp[i][j] = dp[i-1][j];    
            }else
            {
            	dp[i][j] = max((funval[i-1]+dp[i-1][j-fee[i-1]]),dp[i-1][j]);
            }
        }
    }
    int maximum_fun=dp[n][budg];
	int ans = maximum_fun,partycostUtill=0;    
    f(0,budg)
    {
        if(dp[n][i]==maximum_fun)
        {
            partycostUtill=i;
            break;
        }
    }
    cout<<partycostUtill<<" "<<maximum_fun<<"\n";
}
int main()
{
    int partybudg,fun;
    while((cin>>partybudg) && (cin>>fun))
    {
        if(partybudg==0 && fun==0)
        {
            break;
        }
        int *fee = new int[fun];
        int *funval = new int[fun];
        for(int i=0;i<fun;i++)
        {
            cin>>fee[i]>>funval[i];            
        }
        maxfun(fee,funval,partybudg,fun);
        delete [] fee;
        delete [] funval;
    }
    return 0;
}
