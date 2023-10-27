#include<bits/stdc++.h>
 
using namespace std;
 
void solve(){
	int n,m; cin>>n>>m;
	string s,t; cin>>s>>t;
	int ans=0;
	if(s==t){
		cout<<0<<endl;
		return;
	}
	if(s.find(t)!=string::npos){
		cout<<0<<endl;
		return;
	}
	if(n>=m){
		s+=s;
		if(s.find(t)!=string::npos){
			cout<<1<<endl;
			return;
		}
		else{
			cout<<-1<<endl;
			return;
		}
	}
 
	while(n<=m*4){
		if(s.find(t)!=string::npos){
			cout<<ans<<endl;
			return;
		}
		s+=s;
		ans++;
		n=s.size();
	}
 
	cout<<-1<<endl;
	return;
}
 
int main() {
    int t;
    cin >> t;
 
    while (t--) {
        solve();
    }
 
    return 0;
}
