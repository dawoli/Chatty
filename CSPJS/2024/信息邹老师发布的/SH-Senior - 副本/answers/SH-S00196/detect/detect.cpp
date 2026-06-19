#include<bits/stdc++.h>
using namespace std;
int t,n,m,L,V,a[100009][3],ca[100009],pd[4000];
int ans;
vector<int> lo[100009];

void work(){
	bool A=0,B=0,C=0;
	cin>>n>>m>>L>>V;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2]; 
		if(a[i][2]<0) A=1,B=1;
		if(a[i][2]==0) B=1,C=1;
		if(a[i][2]>0) A=1,C=1;
	}
	for(int i=1;i<=m;i++) cin>>ca[i];
	if(n<=20){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(ca[j]<a[i][0]) continue;
				double lu=sqrt(1.00*(ca[j]-a[i][0])*2*a[i][2]+1.00*a[i][1]*a[i][1]);
				if(lu>V){
					lo[j].push_back(i);
					pd[i]=1;
					//cout<<i<<' '<<j<<'\n';
				}
			}
		}
		for(int i=1;i<=n;i++) ans+=pd[i],pd[i]=0;
		cout<<ans<<' ';
		int jo=ans;
		ans=5000000;
		long long turns=pow(2,m+1);
		for(long long i=0;i<turns;i+=2){
			int man=0;
			for(long long j=1;j<=m;j++){
				long long mp=pow(2,j);
				if(i & mp ){
					//cout<<j<<"----";
					man++;
					for(int k=0;k<lo[j].size();k++){
						pd[lo[j][k]]=1;
						//cout<<lo[j][k]<<' ';
					}
					//cout<<'\n';
				}
			}
			//cout<<'\n';
			int now=0;
			for(int i=1;i<=n;i++){
				//cout<<pd[i]<<' ';
				now+=pd[i];
				pd[i]=0;
			}
			//cout<<now<<'\n';
			if(now==jo) ans=min(ans,man);
		}
		cout<<m-ans<<'\n';
		ans=0;
		for(int i=1;i<=m;i++){
			lo[i].clear();
		}
	}else if(!A){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i][0]<=ca[m]&&a[i][1]>V) ans++;
		}
		if(ans==0) cout<<0<<' '<<m<<'\n';
		else cout<<ans<<' '<<m-1<<'\n';
	}else if(!B){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(ca[m]<a[i][0]) continue;
			double lu=sqrt(1.00*(ca[m]-a[i][0])*2*a[i][2]+1.00*a[i][1]*a[i][1]);
			if(lu>V){
				ans++;
			}
		}
		if(ans==0) cout<<0<<' '<<m<<'\n';
		else cout<<ans<<' '<<m-1<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--) work(); 
	return 0;
} 
