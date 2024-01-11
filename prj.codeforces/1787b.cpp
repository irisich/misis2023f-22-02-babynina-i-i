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

#define ll long long
using namespace std;
 
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll x=n;
        ll i=2;
        map<ll,ll> m;
        ll mx=0;
        while(!(x==1) && i<=sqrt(n)){
            if(x%i==0){
                while(x%i==0){
                    x=x/i;
                    m[i]++;
                    mx=max(mx,m[i]);
                }
            }
            i++;
        }
        ll sum=x;
        for(auto it:m){
            sum=sum*(it.first);
            m[it.first]--;
        }
        ll p=1;
        for(ll i=0; i<mx-1; i++){
            p=1;
            for(auto it:m){
                if(m[it.first]!=0){
                    p=p*(it.first);
                    m[it.first]--;
                }
            }
            sum+=p;
        }
        cout<<sum<<endl;
    }
    return 0;
}
