#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<deque>

#define ll long long int
#define pb push_back
#define gcd(a, b) __gcd(a,b)
#define ff first
#define ss second
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    map<ll,ll>mp;
    while(tc--)
    {
        ll n,c=0,i,j;
        cin>>n;
        string s,p;
        cin>>s;
        p=s;
        sort(p.begin(),p.end());
        if(s==p){
            cout<<0<<endl;
            continue;
        }
        char cc=s[n-1],l;
        vector<ll>v;
        string ss;
        for(i=n-1; i>=0; i--)
        {
            if(s[i]>=cc)
            {
                v.pb(i);
                ss+=s[i];
                cc=s[i];
            }
        }
        ll cnt=0;
        for(i=ss.size()-1;i>=0;i--){
                if(ss[i]==ss.back())cnt++;
                else break;
        }
        reverse(ss.begin(),ss.end());
        for(i=0; i<ss.size(); i++)
        {
            s[v[i]]=ss[i];
        }
        if(is_sorted(s.begin(),s.end()))
            cout<<ss.size()-cnt<<endl;
        else cout<<-1<<endl;
    }
}
