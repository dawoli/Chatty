#include<iostream>
#include<algorithm>
using namespace std;
long long ans=0;
int n,a[5005];
void dfs(int y,int num,int sum){
	if(y>n)return;
	if(y>=3&&num>2*sum){
		ans=(ans+1)%998244353;
	}
	for(int i=sum+1;i<=n;i++){
		dfs(y+1,num+a[i],a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	dfs(0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
