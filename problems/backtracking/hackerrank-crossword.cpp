#include<bits/stdc++.h>
#define ll long long int 
#define f(min,max) for(ll i=min;i<=max;i++)
#define f1(min,max) for(ll j=min;j<=max;j++)
#define pair1 pair<ll,ll>
#define mk make_pair
using namespace std;
#define N 10

bool isvalidVerticle(char grid[N][N],string s,int n,int row,int col)
{
    int count=1;
    for(int i=row+1;i<N;i++)
    {
        if(grid[i][col]=='+')
        {
            break;
        }
        if(grid[i][col]=='-' || grid[i][col]==s[count])
        {
            count+=1;
        }
        if(count==n)
        {
            return true;
        }
    }
    
    return false;
}
bool isvalidHorizontal(char grid[N][N],string s,int n,int row,int col)
{
    int count=1;
    for(int i=col+1;i<N;i++)
    {
        if(grid[row][i]=='+')
        {
            break;
        }
        if(grid[row][i]=='-' || grid[row][i]==s[count])
        {
            count+=1;
        }
        if(count==n)
        {
            return true;
        }
    }
    
    return false;
}
void setVerticle(char grid[N][N],string s,int n,bool track[],int row,int col)
{
    int j=0;
    for(int i=row;i<row+n;i++)
    {
        if(grid[i][col]=='-')
        {
            grid[i][col] = s[j];
            track[j] = true;
            j+=1;
            continue;
        }
        if(grid[i][col]==s[j])
        {
            track[j]=false;
            j+=1;
        }
    }
}
void setHorizontal(char grid[N][N],string s,int n,bool track[],int row,int col)
{
    int j=0;
    for(int i=col;i<col+n;i++)
    {
        if(grid[row][i]=='-')
        {
            grid[row][i] = s[j];
            track[j] = true;
            j+=1;
            continue;
        }
        if(grid[row][i]==s[j])
        {
            track[j]=false;
            j+=1;
        }
    }
}
void resetVerticle(char grid[N][N],string s,int n,bool track[],int row,int col)
{
    int j=0;
    for(int i=row;i<row+n;i++)
    {
        if(track[j]==true)
        {
            grid[i][col] = '-';
        }
        j+=1;
    }
}
void resetHorizontal(char grid[N][N],string s,int n,bool track[],int row,int col)
{
    int j=0;
    for(int i=col;i<col+n;i++)
    {
        if(track[j]==true)
        {
            grid[row][i] = '-';
        }
        j+=1;
    }
}
bool crossword(char grid[N][N],vector<string> wlist,int n,int index)
{
    if(n == index)
    {
        return true;
    }
    string s=wlist[index];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(grid[i][j]=='-' || grid[i][j]==s[0])
            {
                if(isvalidVerticle(grid,s,s.length(),i,j))
                {
                    bool track[s.length()]={false};
                    setVerticle(grid,s,s.length(),track,i,j);
                    if(crossword(grid,wlist,n,index+1))
                    {
                        return true;
                    }
                    resetVerticle(grid,s,s.length(),track,i,j);
                }else 
                if(isvalidHorizontal(grid,s,s.length(),i,j))
                {
                    bool track1[s.length()]={false};
                    setHorizontal(grid,s,s.length(),track1,i,j);
                    if(crossword(grid,wlist,n,index+1))
                    {
                        return true;
                    }
                    resetHorizontal(grid,s,s.length(),track1,i,j);
                }
            }
        }
    }
    return false;
}
int main() {
    char grid[N][N];
    for(int i=0;i<N;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<N;j++)
        {
             grid[i][j] = s[j];   
        }
    }
    string words;
    cin>>words;
    vector<string> wlist;
    string s1="";
    for(int i=0;words[i]!='\0';i++)
    {
        if(words[i]!=';')
        {
            s1+=words[i];
        }else
        {
            wlist.push_back(s1);
            s1="";
        }
    }
    wlist.push_back(s1);
    crossword(grid,wlist,wlist.size(),0);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<grid[i][j];
        }
        cout<<"\n";
    }
    return 0;
}
