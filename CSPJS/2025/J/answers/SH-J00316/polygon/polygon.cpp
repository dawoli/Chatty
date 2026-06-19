#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans=0,selected[5005];
bool visited[5005];
void dfs(int k,int dep,int end){
	for(int i=k+1;i<=n;i++){
		if(!visited[i]){
			visited[i]=true;
			selected[dep]=a[i];
		}
		if(dep!=end) dfs(i,dep+1,end);
		else{
			long long sum=0,mx=0;
			for(int j=1;j<=end;j++){
				mx=max(mx,selected[j]);
				sum+=selected[j];
			}
			if(sum>mx*2) ans=(ans+1)%998244353;
		}
		visited[i]=false;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=3;i<=n;i++){
		dfs(0,1,i);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
