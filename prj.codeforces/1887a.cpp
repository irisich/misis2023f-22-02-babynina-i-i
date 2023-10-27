#include<iostream>
#include<algorithm> 
using namespace std;
int a[100005];
int b[100005];
int t;
int n,m;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		a[0]=1;
		for(int i=1;i<n;i++)cin>>a[i];
		for(int i=0;i<n;i++)cin>>b[i];
		sort(a,a+n);
		sort(b,b+n);
		int num=0;
		int ra=n-1,rb=n-1;
		while(ra>=0&&rb>=0){
			if(a[ra]>=b[rb])ra--;
			else{
				ra--;
				rb--;
				num++;
			}
		}
		cout<<n-num<<endl;
	}
} 
