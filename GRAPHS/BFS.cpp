#include<bits/stdc++.h>
#define ll long long int 
#define f(min,max) for(ll i=min;i<=max;i++)
#define f1(min,max) for(ll j=min;j<=max;j++)
#define pair1 pair<ll,ll>
#define mk make_pair
#define m 1000000007
using namespace std;
void printBFS(ll **edges,ll V,ll sv)
{
	queue<ll> bfsqueue;
	bool *visited = new bool[V]();
	bfsqueue.push(sv);
	visited[sv]=true;
	while(!bfsqueue.empty())
	{
		ll currentvertex = bfsqueue.front();
		bfsqueue.pop();
		for(ll i=0;i<V;i++)
		{
			if(i==currentvertex)
			{
				continue;
			}
			if(edges[currentvertex][i]==1 && !visited[i])
			{
				bfsqueue.push(i);
			}
			cout<<currentvertex<<" ";
		}
	}
}
int main()
{
	ll V,E;
	cin>>V>>E;
	ll **edges = new ll*[V];
	for(ll i=0;i<V;i++)
	{
		edges[i] = new ll[V]();
	}
	ll start,finish;
	for(ll i=0;i<E;i++)
	{
		cin>>start>>finish;
		edges[start][finish]=1;
		edges[finish][start]=1;
	}
	printBFS(edges,V,0);
	for(ll i=0;i<V;i++)
	{
		delete [] edges[i];
	}
	delete [] edges;
	return 0;
}
