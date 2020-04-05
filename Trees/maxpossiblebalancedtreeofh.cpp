
	// MAXIMUM POSSIBLE BALANCED BINARY TREE OF HEIGHT (H).

#define m 1000000007
#define ll long long int
#include<bits/stdc++.h>
#define ll long long int 
#define f(min,max) for(ll i=min;i<=max;i++)
#define f1(min,max) for(ll j=min;j<=max;j++)
#define pair1 pair<ll,ll>
using namespace std;

int balancedBTs(int h) {
  
    if(h==1 || h==0)
    {
        return 1%m;
    }
    ll x = balancedBTs(h-1);
    ll y = balancedBTs(h-2);
    return ((ll)x*(ll)x+(2*(ll)y*(ll)x))%m;
 }

int main()
{
  ll n;
  return 0;
}
