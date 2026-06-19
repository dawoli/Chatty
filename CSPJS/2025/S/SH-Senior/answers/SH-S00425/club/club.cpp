#include<bits/stdc++.h>
using namespace std;
#define N 100005
int n,T,a[N][5],k[N],k2[N],ct[5],ans,d[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	while(T--){
		ans=0;
		memset(ct,0,sizeof(ct));
		cin>>n;
		for(int i=1;i<=n;i++){
			k[i]=0,k2[i]=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>a[i][k[i]]){
					k2[i]=k[i],k[i]=j;}
				else if(a[i][j]>a[i][k2[i]]){
					k2[i]=j;}
			}
			d[i]=a[i][k[i]]-a[i][k2[i]];
			ct[k[i]]++;
			ans+=a[i][k[i]];
		}
		int t=0;
		for(int i=1;i<=3;i++){
			if(ct[i]>n/2){t=i;break;}
		}
		if(t==0){
			cout<<ans<<'\n';continue;}
		vector<int> cg;
		for(int i=1;i<=n;i++){
			if(k[i]==t){
				cg.push_back(d[i]);}}
		sort(cg.begin(),cg.end());
		for(int i=0;i<ct[t]-n/2;i++){
			ans-=cg[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
