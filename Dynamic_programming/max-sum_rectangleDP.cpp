#include<bits/stdc++.h>
#define ll long long int 
#define f(min,max) for(ll i=min;i<=max;i++)
#define f1(min,max) for(ll j=min;j<=max;j++)
#define pair1 pair<ll,ll>
#define mk make_pair
using namespace std;
ll maxleft,maxright,maxup,maxdown;
ll maxcontigioussum(ll a[],ll n,ll maxm,ll curr,ll s,ll n1)
{
	if(n==0)
	{
		return maxm;
	}
	curr +=a[0];
	curr = max(curr,a[0]);
	if(curr<0)
	{
        curr=0;
		s = n1+1;
	}
	if(curr>maxm)
	{
		maxm=curr;
		maxup =s;
		maxdown = n1+1;
	}
	ll f =maxcontigioussum(a+1,n-1,maxm,curr,s,n);
	return f;
}
ll maxsumrec(ll **a,ll row,ll col)
{
	ll maxsum=LLONG_MIN,curr_sum,maxRup,maxRdown;
	f(0,col-1)
	{
		ll track[row]={0};
		f1(i,col-1)
		{
			for(int k=0;k<row;k++)
			{
				track[k]+=a[k][j];
			}
			curr_sum =	maxcontigioussum(track,row,LLONG_MIN,0,1,1);
			if(curr_sum>maxsum)
			{
				maxsum = curr_sum; 
				maxleft = i+1;
				maxright = j+1;
				maxRup = maxup;
				maxRdown = maxdown;
			}
		}
	}
	return maxsum;
}
int main()
{
  ll row,col;
  cin>>row>>col;
  ll **a = new ll *[row];
  f(0,row-1)
  {
	  a[i] = new ll[col];
	  f1(0,col-1)
	  {
		  cin>>a[i][j];
	  }
  }
  ll maxsum = maxsumrec(a,row,col);
  cout<<maxsum<<"\n";
  cout<<maxleft<<" "<<maxright<<" "<<maxup<<" "<<maxdown<<"\n";
  f(0,row-1)
  {
	  delete [] a[i];
  }
  delete [] a;
  return 0;   
}
