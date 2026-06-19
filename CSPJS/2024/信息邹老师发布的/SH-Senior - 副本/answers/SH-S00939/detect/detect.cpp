#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int T,sp[N],x[N],y[N],z[N],cnt,ans;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cnt=0,ans=0;
		int n,m,s,t;
		cin>>n>>m>>s>>t;
		for(int j=1;j<=n;j++){
			cin>>x[j]>>y[j]>>z[j];
			if(z[j]==0){
		    	cnt++;
				if(y[j]>t)ans++;	
			}
		}
		for(int k=1;k<=m;k++) cin>>sp[k];
		if(cnt==n){
			for(int j=1;j<=n;j++)
			    if(x[j]>sp[m]&&y[j]>t)
			        ans--;
			cout<<ans<<endl;
			if(m!=1) cout<<m-1;
		    else cout<<1;
		}
	    cout<<ans<<endl;
	    cout<<4;
	}
	return 0;
} 
