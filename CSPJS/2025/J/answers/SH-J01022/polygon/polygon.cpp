#include<bits/stdc++.h>
using namespace std;
int o[5050];
int vis[5050];
long long cnt=0;
int n;
int maxn=0;
long long sum;
void dfs(int s,int k,int max,long long sum){
	if(sum>o[max]*2&&k>=3){
		cnt++;
	}
	else{
		return;
	}
	if(k==3){
		return;
	}
	for(int i=s;i<=max;i++){
		if(vis[i]==0&&i!=max){
			vis[i]=1;
			dfs(i,k-1,max,sum-o[i]);
			vis[i]=0;
		}
		else if(vis[i]==0&&i==max){
			vis[i]=1;
			int big;
			for(int j=max;j>=1;j--){
				if(vis[j]==0){
					big=j;
					break;
				}
			}
			dfs(i,k-1,big,sum-o[i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		 cin>>o[i];
		 sum+=o[i];
		 maxn=max(maxn,o[i]);
	}
	if(maxn>1){
		sort(o+1,o+1+n);
		dfs(1,n,n,sum);
		cout<<cnt;
	}
	else{
		for(int i=0;i<=n-3;i++){
			long long o=1;
			for(int j=1;j<=i;j++){
				o*=j;
				o%=998244353;
			}
			long long p=1;
			int zl=0;
			for(int j=n;j>0;j--){
				if(zl==i){
					break;
				}
				p*=j;
				zl++;
				p%=998244353;
			}
			cnt+=p/o;
			cnt%=998244353;			
		}
		cout<<cnt;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
