#include<bits/stdc++.h>
using namespace std;
const int Maxn=1e5+10;
int t,n,a[Maxn][5],cnt[5],b[Maxn],c[Maxn],d[Maxn],i,j;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0;
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		for(i=1;i<=n;i++){
	    	for(j=1;j<=3;j++) cin>>a[i][j];
	    	int p=1;
	    	for(j=2;j<=3;j++)
	    	if(a[i][j]>a[i][p]) p=j;
	    	cnt[p]++; ans+=a[i][p];
	    	int mi=-200000;
	    	for(j=1;j<=3;j++) 
	    	if(j!=p) mi=max(mi,a[i][j]-a[i][p]);
	    	if(p==1) b[cnt[p]]=mi;
	    	if(p==2) c[cnt[p]]=mi;
	    	if(p==3) d[cnt[p]]=mi;
		}
		int mx=0,p=1;
		for(i=1;i<=3;i++)
		if(cnt[i]>mx){
			mx=cnt[i]; p=i;
		}
		if(2*mx<=n) cout<<ans<<endl;
		else{
			if(p==1){
				sort(b+1,b+cnt[p]+1);
				for(i=cnt[p];i>=cnt[p]-(mx-n/2)+1;i--) ans+=b[i];
			}
			if(p==2){
				sort(c+1,c+cnt[p]+1);
				for(i=cnt[p];i>=cnt[p]-(mx-n/2)+1;i--) ans+=c[i];
			}
			if(p==3){
				sort(d+1,d+cnt[p]+1);
				for(i=cnt[p];i>=cnt[p]-(mx-n/2)+1;i--) ans+=d[i];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
