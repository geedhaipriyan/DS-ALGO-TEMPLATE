
		// constraints N (1 to 10)
		
#include<bits/stdc++.h>
#define ll long long int 
#define f(min,max) for(ll i=min;i<=max;i++)
#define f1(min,max) for(ll j=min;j<=max;j++)
#define pair1 pair<ll,ll>
#define mk make_pair
using namespace std;
int positions[11][11];
bool ispossible(int n,int row,int col)
{
    for(int i=row-1;i>=0;i--)
    {
        if(positions[i][col]==1)
        {
            return false;
        }
    }
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
    {
        if(positions[i][j]==1)
        {
            return false;
        }
    }
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++)
    {
        if(positions[i][j]==1)
        {
            return false;
        }
    }
    return true;
}
void SolveNqueens(int n,int row)
{
    if(row == n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<positions[i][j]<<" ";
            }
        }
        cout<<"\n";
    }
    for(int i=0;i<n;i++)
    {
    if(ispossible(n,row,i))
    {
        positions[row][i]=1;
        SolveNqueens(n,row+1);
        positions[row][i]=0;
    }
    }
    return;
}
void placeNQueens(int n){

    memset(positions,0,11*11*sizeof(int));
    SolveNqueens(n,0);

}
int main()
{
  ll n;
  cin>>n;
  Solve(n,0);
  return 0;   
}
