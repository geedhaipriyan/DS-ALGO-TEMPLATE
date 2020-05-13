
#include<bits/stdc++.h>
#define ll long long int 
#define f(min,max) for(ll i=min;i<=max;i++)
#define f1(min,max) for(ll j=min;j<=max;j++)
#define pair1 pair<ll,ll>
#define mk make_pair
#define m 1000000007
using namespace std;
void constructTree(ll *arr,ll *segmentTree,ll start,ll end,ll pos)
{
	if(start==end)
	{
		segmentTree[pos]=arr[start];
		return;
	}
	ll mid = (start+end)/2;
	constructTree(arr,segmentTree,start,mid,2*pos);
	constructTree(arr,segmentTree,mid+1,end,2*pos+1);
	segmentTree[pos] =  segmentTree[2*pos]+segmentTree[2*pos+1];
	//segmentTree[pos] =  min(segmentTree[2*pos],segmentTree[2*pos+1]);//min array
	//segmentTree[pos] =  max(segmentTree[2*pos],segmentTree[2*pos+1]);//max array
	
}

ll Query(ll *segmentTree,ll l,ll r,ll start,ll end,ll pos)
{
	if(l<=start && r>=end)
	{
		return segmentTree[pos];
	}
	if(l>end || r<start)
	{
		//return LLONG_MAX;
		//return LLONG_MIN;
		return 0;
	}
	ll mid = (start+end)/2;
	ll left = Query(segmentTree,l,r,start,mid,2*pos);
	ll right = Query(segmentTree,l,r,mid+1,end,2*pos+1);
	return left+right;
}
void updateTree(ll *arr,ll *segmentTree,ll start,ll end,ll pos,ll index,ll value)
{
	if(start == end)
	{
		arr[index] = value;
		segmentTree[pos]=value;
		return;
	}
	ll mid = (start+end)/2;
	if(mid>index)
	{
		updateTree(arr,segmentTree,start,mid,2*pos,index,value);	
	}else
	{
		updateTree(arr,segmentTree,mid+1,end,2*pos+1,index,value);
	}
	segmentTree[pos] =  segmentTree[2*pos]+segmentTree[2*pos+1];
	//segmentTree[pos] =  min(segmentTree[2*pos],segmentTree[2*pos+1]);//min array
	//segmentTree[pos] =  max(segmentTree[2*pos],segmentTree[2*pos+1]);//max array
}
int main()
{
	ll n;
	cin>>n;
	ll *arr = new ll[n];
	ll *segmentTree = new ll[4*n];
	for(int i=0;i<4*n;i++)
	{
		segmentTree[i]=0;
	}
	f(0,n-1)
	{
		cin>>arr[i];	
	}
	constructTree(arr,segmentTree,0,n-1,1);
	for(int i=0;i<4*n;i++)
	{
		cout<<segmentTree[i]<<" ";
	}
	cout<<"\n";
	updateTree(arr,segmentTree,0,n-1,1,2,7);
	for(int i=0;i<4*n;i++)
	{
		cout<<segmentTree[i]<<" ";
	}
	ll l,r;
	cin>>l>>r;
	cout<<Query(segmentTree,l-1,r-1,0,n-1,1);
	delete [] arr;
	delete [] segmentTree;
	return 0;
}

