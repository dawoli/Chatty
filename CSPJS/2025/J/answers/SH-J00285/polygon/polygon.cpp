#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
long long n,a[5050],l,r,cnt[5050],ans;
void dfs(long long id,long long sum,long long m,long long mx){
	if(m>=3&&sum>2*mx){
		ans=(ans+1)%998244353;
	}
	for (int i=id;i<=n;i++){
		dfs(i+1,sum+a[i],m+1,a[i]);
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(1,0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
