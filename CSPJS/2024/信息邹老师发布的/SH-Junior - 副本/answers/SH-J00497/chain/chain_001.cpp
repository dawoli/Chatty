#include<bits/stdc++.h>
using namespace std;
#define N 1005//设置大小
#define M 200005//设置大小

int n,k,q,s[N][M],r[N],c[N];
bool isF=false;

void dfs(int lastPeople,int endNum,int k,int r,int nc){
	if(r==0){
		if(endNum==nc) isF=true;
		return; 
	}
	for(int i=1;i<=n;++i){
		int lsFind=-1;
		if(i==lastPeople) continue;
		for(int j=1;j<=s[i][0];++j){
			if(lsFind!=-1&&(j-lsFind+1)>=2&&(j-lsFind+1)<=k){
				dfs(i,s[i][j],k,r-1,nc);
			}
			if(s[i][j]==endNum) lsFind=j;
		} 
	}
}

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;++i){
			cin>>s[i][0];
			for(int j=1;j<=s[i][0];++j) cin>>s[i][j];
		}
		for(int i=1;i<=q;++i) cin>>r[i]>>c[i];
		for(int z=1;z<=q;++z){
			if(r[z]==1){
				bool isFind=false;
				for(int i=1;i<=n;++i){
					int flag=-1;
					for(int j=1;j<=s[i][0];++j){
						if(s[i][j]==c[z]&&flag!=-1&&(j-flag+1)>=2&&(j-flag+1)<=k){
							isFind=true;
							cout<<1<<endl;
							break;
						}
						if(s[i][j]==1) flag=j;
					}
					if(isFind==true) break;
				}
				if(isFind==false) cout<<0<<endl;
			}
			if(r[z]<=5&&r[z]!=1){
				isF=false;
				dfs(0,1,k,r[z],c[z]);
				if(isF) cout<<1<<endl;
				else cout<<0<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


