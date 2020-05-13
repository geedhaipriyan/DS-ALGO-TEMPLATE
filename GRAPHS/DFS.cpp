#include<bits/stdc++.h>
#define ll long long int 
#define f(min,max) for(ll i=min;i<=max;i++)
#define f1(min,max) for(ll j=min;j<=max;j++)
#define pair1 pair<ll,ll>
#define mk make_pair
#define m 1000000007
using namespace std;
void print(ll **edges,bool *visited,ll V,ll sv)
{
	cout<<sv<<" ";
	visited[sv]=true;
	for(int i=0;i<V;i++)
	{
		if(i==sv)
		{
			continue;
		}
		if(edges[sv][i]==1)
		{
			if(visited[i])
			{
				continue;
			}
			print(edges,visited,V,i);
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
	bool *visited = new bool[V]();
	print(edges,visited,V,0);
	delete [] visited;
	for(ll i=0;i<V;i++)
	{
		delete [] edges[i];
	}
	delete [] edges;
	return 0;
}
