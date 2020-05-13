#include<bits/stdc++.h>
#define ll long long int 
#define f(min,max) for(ll i=min;i<=max;i++)
#define f1(min,max) for(ll j=min;j<=max;j++)
#define pair1 pair<ll,ll>
#define mk make_pair
#define m 1000000007
using namespace std;
struct node
{
	ll segmentSum,segmentprefix,segmentsuffix,maxsumans;
};
node compose(node left,node right)
{
	node result;
	result.segmentSum = left.segmentSum+right.segmentSum;
	result.segmentprefix = max(left.segmentprefix, left.segmentSum+right.segmentprefix);
	result.segmentsuffix = max(right.segmentsuffix, right.segmentSum+left.segmentsuffix);
	result.maxsumans = max(max(left.maxsumans,right.maxsumans),left.segmentsuffix+right.segmentprefix);
	return result;
}
node make_data(ll val)
{
	node res;
	res.segmentSum=val;
	res.segmentprefix = res.segmentsuffix = res.maxsumans = ((val>0)?val:0);
	return res;
}
void constructTree(ll *arr,node *tree,ll start,ll end,ll pos)
{
	if(start == end)
	{
		tree[pos] = make_data(arr[start]);
		return;
	}
	
	ll mid = (start+end)/2;
	constructTree(arr,tree,start,mid,2*pos);
	constructTree(arr,tree,mid+1,end,2*pos+1);
	tree[pos] = compose(tree[2*pos],tree[2*pos+1]);
}
node Query(node *tree,ll start,ll end,ll l,ll r,ll pos)
{
	if(l>r)
	{
		return make_data(0);
	}
	if(l==start && r==end)
	{
		return tree[pos];
	}
	ll mid = (start+end)/2;
	if(l>mid)
	{
		return Query(tree,mid+1,end,l,r,2*pos+1);
	}
	if(r<=mid)
	{
		return Query(tree,start,mid,l,r,2*pos);
	}
	return compose(Query(tree,start,mid,l,mid,2*pos),
					Query(tree,mid+1,end,mid+1,r,2*pos+1));
}
int main()
{
	ll n;
	cin>>n;
	ll *arr = new ll[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	node *tree = new node[4*n];
	constructTree(arr,tree,0,n-1,1);
	ll q,l,r;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>l>>r;
		node ans = Query(tree,0,n-1,l-1,r-1,1);
		cout<<ans.maxsumans<<"\n";
	}
	delete [] arr;
	delete [] tree;
	return 0;
}
