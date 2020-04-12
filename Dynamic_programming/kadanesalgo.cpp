#include<bits/stdc++.h>
#define ll long long int 
#define f(min,max) for(ll i=min;i<=max;i++)
#define f1(min,max) for(ll j=min;j<=max;j++)
#define pair1 pair<ll,ll>
#define mk make_pair
using namespace std;

	// recursive implementation
void maxcontigioussum(ll a[],ll n,ll maxm,ll curr,ll start,ll s,ll end,ll n1)
{
	if(n==0)
	{
		cout<<"max sum :"<<maxm<<" start :"<<start<<" end :"<<end<<"\n";
		return;
	}
	curr +=a[0];
	curr = max(curr,a[0]);
	if(curr<0)
	{
		s = n1 - (n-1);
	}
	if(curr>maxm)
	{
		cout<<n<<"\n";
		maxm=curr;
		start =s+1;
		end = n1-(n-1);
	}
	maxcontigioussum(a+1,n-1,maxm,curr,start,s,end,n1);
}
int main()
{
  ll n;
  cin>>n;
  ll a[n],curr=0,maxm=LLONG_MIN,start,start1,end=0;;
  f(0,n-1)
  {
	  cin>>a[i];
  }
  start =1;
			// iterative implementation
  f(0,n-1)
  {
	  curr += a[i];
	  curr = (curr>a[i])?curr:a[i];
	  if(curr<0)
	  {
		  start=i+1;
	  }
	  if(curr>maxm)
	  {
		  maxm = curr;
		  start1=start+1;
		  end =i+1;
	  } 
  }
  cout<< maxm <<" " <<start1 << " "<<end;
  maxcontigioussum(a,n,LLONG_MIN,0,1,1,1,n);
  return 0;   
}
