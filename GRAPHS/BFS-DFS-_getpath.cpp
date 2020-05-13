#include<bits/stdc++.h>
#define ll long long int 
#define f(min,max) for(ll i=min;i<=max;i++)
#define f1(min,max) for(ll j=min;j<=max;j++)
#define pair1 pair<ll,ll>
#define mk make_pair
#define pb push_back
#define m 1000000007
using namespace std;
vector<ll>* getpathHelperDFS(ll **edges,bool *visited,ll V,ll sv,ll ev)
{
	if(sv==ev)
	{
		vector<ll> *output = new vector<ll>();
		output->pb(ev);
		return output;
	}
	visited[sv]=true;
	for(ll i=0;i<V;i++)
	{
		if(edges[sv][i] && !visited[i])
		{
			vector<ll> *soutput = getpathHelperDFS(edges,visited,V,i,ev);
			if(soutput!=NULL)
			{
				soutput->pb(sv);
				return soutput;
			}
		}
	}
	return NULL;
}
vector<ll>* getpathDFS(ll **edges,ll V,ll sv,ll ev)
{
	bool *visited = new bool[V]();
	vector<ll> *output = getpathHelperDFS(edges,visited,V,sv,ev);
	delete [] visited;
	return output;
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
	ll sv,ev;
	cin>>sv>>ev;
	vector<ll> *output = getpathDFS(edges,V,sv,ev);
	if(output!=NULL)
	{
		for(int i=0;i<output->size();i++)
		{
			cout<<output->at(i)<<" ";
		}
	}
	for(ll i=0;i<V;i++)
	{
		delete [] edges[i];
	}
	delete [] edges;
	return 0;
}
