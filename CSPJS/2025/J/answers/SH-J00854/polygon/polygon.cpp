#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int fenduan[5005];
int maxn[5005];
int qianzhui[5005];
int duanwei[5005];
int duantou[5005];
int ans=0;
void dfs(int id,int maxxam,int cnt,int alla){
	if(id>n){
		if(maxxam*2<cnt&&alla>=3){
			ans++;
		}
		return;
	}
	dfs(id+1,maxxam,cnt,alla);
	dfs(id+1,max(maxxam,a[id]),cnt+a[id],alla+1);
}
void solve(){
	dfs(1,0,0,0);
	cout<<ans<<endl;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=1;
	for(int i=1;i<=n;i++){
		fenduan[i]=i/sqrt(n)+1;
		duanwei[fenduan[i]]=i;
		if(duantou[fenduan[i]]==0){
			duantou[fenduan[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn[fenduan[i]]=max(maxn[fenduan[i]],a[i]);
		qianzhui[i]=qianzhui[i-1]+a[i];
		if(a[i]!=1){
			flag=0;
		}
	}
	if(n<=3){
		if(n<3){
			cout<<0<<endl;
			return 0;
		}
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
			cout<<1<<endl;
		}
		else{
			cout<<0<<endl;
		}
		return 0;
	}
	if(flag){
		int t=n*(n-1)*(n-2);
		int k=6;
		for(int i=3;i<=n;i++){
			ans+=t/k;
			k*=(i+1);
			t*=(n-i);
		}
		cout<<ans<<endl;
		return 0;
	}
	if(n<=20){
		solve();
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			int zonghe=qianzhui[j]-qianzhui[i-1];
			if(fenduan[i]==fenduan[j]){
				int maxxn=0;
				for(int k=i;k<=j;k++){
					maxxn=max(maxxn,a[k]);
				}
				if(maxxn*2<zonghe){
					ans++;
				}
//				cout<<maxxn<<' '<<zonghe<<endl;
				continue;
			}
			else{
				int maxx=0;
				for(int k=i;k<duantou[fenduan[i]+1];k++){
					maxx=max(maxx,a[k]);
				}
				for(int k=fenduan[i]+1;k<fenduan[j];k++){
					maxx=max(maxx,maxn[k]);
				}
				for(int k=duantou[fenduan[j]];k<=j;k++){
					maxx=max(maxx,a[k]);
				}
				if(maxx*2<zonghe){
					ans++;
				}
//				cout<<maxx<<' '<<zonghe<<endl;
				continue;
			}
		}
	}	
	cout<<ans<<endl;
	return 0;
}
