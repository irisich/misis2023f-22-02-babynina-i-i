#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int v[n];
        int sl=INT_MAX,tl=INT_MAX,i,count=0;
        for(i=0;i<n;i++)
        {
            cin>>v[i];
            if(sl>tl)
            swap(sl,tl);
            if(v[i]<=sl)
            sl=v[i];
            else if(v[i]<=tl)
            tl=v[i];
            else 
            {
                sl=v[i];
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
