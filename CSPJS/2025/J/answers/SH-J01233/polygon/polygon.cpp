#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
bool b[5005];
long long ans=0;
void dfs(int depth,int sum){
	if(depth==n){
		int _max=0;
		for(int i=n;i>=0;i--){
			if(b[i]){
				_max=a[i];
				break;
			}
		}
		if(sum>_max*2){ 
			ans++;
			ans%=998244353;
			return ;
		}
		return ;
	}else{
		dfs(depth+1,sum);
		
		b[depth+1]=true;
		dfs(depth+1,sum+a[depth+1]);
		b[depth+1]=false;
		return ;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	memset(b,false,sizeof(b));
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int t;
	for(int a1=1;a1<=n;a1++){
		for(int a2=a1;a2<=n;a2++){
			if(a[a1]>a[a2]){
				t=a[a1];
				a[a1]=a[a2];
				a[a2]=t;
			}
		}
	}
	dfs(0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
