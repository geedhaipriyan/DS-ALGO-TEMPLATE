#include<bits/stdc++.h>
#define ll long long int 
#define f(min,max) for(ll i=min;i<=max;i++)
#define f1(min,max) for(ll j=min;j<=max;j++)
#define pair1 pair<ll,ll>
#define mk make_pair
using namespace std;
#define N 9

bool findLoc(int matrix[N][N],int *row,int *col)
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
				if(matrix[i][j]==0)
				{
					*row=i;*col=j;
					return true;
				}
		}
	}
	return false;
}
bool issafeRow(int matrix[N][N],int row,int val)
{
	for(int i=0;i<N;i++)
	{
		if(matrix[row][i]==val)
		{
			return false;
		}
	}
	return true;
}
bool issafeCol(int matrix[N][N],int col,int val)
{
	for(int i=0;i<N;i++)
	{
		if(matrix[i][col]==val)
		{
			return false;
		}
	}
	return true;
}
bool issafegrid(int matrix[N][N],int row,int col,int val)
{
	int Rowfactor = row - (row%3);
	int Colfactor = col - (col%3);
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(matrix[i+Rowfactor][j+Colfactor]==val)
			{
				return false;
			}
		}
	}
	return true;
}
bool issafe(int matrix[N][N],int row,int col,int val)
{
	return (issafeRow(matrix,row,val) && issafeCol(matrix,col,val) && issafegrid(matrix,row,col,val));
}
bool solvesudoku(int matrix[N][N])
{
	int row,col;
	if(!findLoc(matrix,&row,&col))
	{
		return true;
	}
	for(int i=1;i<=N;i++)
	{
		if(issafe(matrix,row,col,i))
		{
			matrix[row][col]=i;
			if(solvesudoku(matrix))
			{
				return true;
			}
			matrix[row][col]=0;
		}
	}
	return false;
}
int main()
{
	int matrix[N][N];
	for(int i=0;i<N;i++)
	{
		string s;
		cin>>s;
		for(int j=0;j<N;j++)
		{
			matrix[i][j] = s[j]-'0';
		}
	}
	solvesudoku(matrix);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<matrix[i][j];
		}
		cout<<"\n";
	}
	return 0;
}


