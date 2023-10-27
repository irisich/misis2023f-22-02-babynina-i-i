#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N],b[N],c[N];
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        sort(a,a+n);
        sort(b,b+n);
        int flag=0;
        for(int i=0;i<n;i++){
            if(a[i]<=b[i]){
                flag=1;
                break;
            }
        }
        if(flag){
            cout<<0<<endl;
            continue;
        }
        int idx=0;
        for(int i=0;i<n;i++){
            if(b[i]>=a[idx]){
                c[idx]=i;
                idx++;
                i--;
            }
        }
        for(int i=idx;i<n;i++) c[i]=n;
        for(int i=0;i<n;i++) c[i]-=i;
        int ans=1;
        for(int i=0;i<n;i++) ans=ans*c[i]%1000000007;
        cout<<ans<<endl;
    }
    return 0;
}
