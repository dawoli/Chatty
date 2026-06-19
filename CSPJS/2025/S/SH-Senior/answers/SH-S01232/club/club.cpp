#include<bits/stdc++.h>
using namespace std;
int n,ans;
int flagA,flagB;
int a[201][5];
int aa[201];
int choose[201];
void dfs(int u,int cnta,int cntb,int cntc){
	if(cnta>n/2||cntb>n/2||cntc>n/2){
		return ;
	}
	if(u==n+1){
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i][choose[i]];
		}
		ans=max(ans,sum);
		return ;
	}
	choose[u]=1;
	dfs(u+1,cnta+1,cntb,cntc);
	choose[u]=2;
	dfs(u+1,cnta,cntb+1,cntc);
	choose[u]=3;
	dfs(u+1,cnta,cntb,cntc+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _=1;
	cin>>_;
	while(_--){
		ans=flagA=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0){
				flagA=1;
			}
			if(a[i][3]!=0){
				flagB=1;
			}
		}
		if(n<=10){
			dfs(1,0,0,0);
			cout<<ans<<'\n';
			continue;
		}
		else if(flagA==0){
			for(int i=1;i<=n;i++){
				aa[i]=a[i][1];
			}
			int sum=0;
			sort(aa+1,aa+1+n);
			for(int i=n;i>n/2;i--){
				sum+=aa[i];
			}
			cout<<sum<<'\n';
			continue;
		}
		else if(flagB==0){
			
		}
		else{
			int sum=0;
			for(int i=1;i<=n;i++){
				sum+=max(a[i][1],max(a[i][2],a[i][3]));
			}
			cout<<sum;
		}
	}
	return 0;
}
