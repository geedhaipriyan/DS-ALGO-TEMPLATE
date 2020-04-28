
//input format
// 6 -> N
// S F
// 1 2
// 3 4
// 0 6
// 5 7
// 8 9
// 5 9

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct activity{
    ll start,finish;
};
bool compare(activity a1,activity a2)
{
    return (a1.finish<a2.finish);
}
int main()
{
    //Write your code here
    ll n;
    cin>>n;
    
    activity a[n];
    string h;
    getline(cin,h);
    for(ll i=0;i<n;i++)
    {
        string s;
        getline(cin,s);
        stringstream ss(s);
        ll num;
        ss>>num;
        a[i].start=num;ss>>num;
        a[i].finish=num;
    }
    sort(a,a+n,compare);
    ll total=1;
    ll end = a[0].finish;
    for(ll i=1;i<n;i++)
    {
        if(a[i].start>=end)
        {
            total+=1;
        	end = a[i].finish;
        }
        
    }
    cout<<total;
    return 0;
}
