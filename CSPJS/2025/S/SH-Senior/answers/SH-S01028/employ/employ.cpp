#include<bits/stdc++.h>
using namespace std;
char tt[100000];
long long p[100000];
long long vis[100000];
long long n,m,cnt=0; 
void dfs(int step,int km,int l){
	if(step==n+1&&l>=m){
		cnt++;
		return;
	}
	cnt%=998244353;
	if(l>=m){
		long long lo=1;
		for(int i=1;i<=n-step+1;i++){
			lo*=i;
			lo%=998244353;
		}
		cnt+=lo;
		return;
	}
	if(tt[step]=='0'){
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				vis[i]=1;
				dfs(step+1,km+1,l);
				vis[i]=0;
			}
		}		
	}
	else{
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				if(p[i]>km){
					vis[i]=1;
					dfs(step+1,km,l+1);
					vis[i]=0;
				}
				else{
					vis[i]=1;
					dfs(step+1,km+1,l);
					vis[i]=0;
				}
			}
		}
	}
	
}
int main(){
	int q=0;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>tt[i];
		if(tt[i]=='1'){
			q++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	if(q<m){
		cout<<0;
		return 0;
	}
	if(q==n){
		long long lo=1;
		for(int i=1;i<=n;i++){
			lo*=i;
			lo%=998244353;
		}
		cnt=lo;
		cout<<cnt;
		return 0;
	}
	dfs(1,0,0);
	cout<<cnt;
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
