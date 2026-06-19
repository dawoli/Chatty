#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,V,d[100009],v[100009],a[100009],p[100009];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    for(int q=0;q<T;q++){
        cin>>n>>m>>L>>V;
        int ans1=0,ans2=m-1;
        for(int i=0;i<n;i++)cin>>d[i]>>v[i]>>a[i];
		for(int i=0;i<m;i++)cin>>p[i];
		int mx=*max_element(p,p+m);
		for(int i=0;i<n;i++){
			if(v[i]>V&&d[i]<=mx)ans1++;
		}	
		if(ans1==0)ans2++;
		cout<<ans1<<" "<<ans2<<endl; 
    }
    return 0;
}
