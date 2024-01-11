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

using namespace std;
inline int read(){
	int ans=0;bool op=0;char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')op=1;ch=getchar();}
	while('0'<=ch&&ch<='9'){ans=(ans<<1)+(ans<<3)+(ch^48);ch=getchar();}
	if(op)return -ans;
	return ans;
}
int n,k;
bool check(int x){
	int tmp=x;
	int tot=0;
	while(tmp)tot+=tmp%10,tmp/=10;
	if(tot%k)return 0;
	return cout<<x<<'\n',1;
}
signed main(){
	int t=read();
	while(t--){
		n=read(),k=read();
		for(int i=n;!check(i);i++);
	}
	return 0;
}
