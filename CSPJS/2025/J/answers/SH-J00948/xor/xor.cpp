#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],p[500010];
bool flag_a=1,flag_b=1;
int ans=0;

void dfs(int dep,int sum){
	if(dep>=n)return;
	ans=max(ans,sum);
	for(int i=dep+1;i<=n;i++){
		for(int j=dep+1;j<=i;j++){
			if((p[i]^p[j-1])==k){
				dfs(i,sum+1);
				return;
			}
		}
	}
	return;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=p[i-1]^a[i];
		if(a[i]!=0&&a[i]!=1)flag_b=0;
		if(a[i]!=1)flag_a=0;
	}
	if(flag_a){
		cout<<n;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(flag_b){
		int cnt=0;
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1)cnt++;
			}
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==0)cnt++;
				else if(a[i]==1&&a[i-1]==1){
					a[i]=0;
					a[i-1]=0;
					cnt++;
				}
			}
		}
		cout<<cnt;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

