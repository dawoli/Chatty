#include<bits/stdc++.h>
using namespace std;
long long int a[5010];
int num;
long long int dfs(long long int n,long long int all,long long int maxs){
	if(n==num+1){
		if(all>2*maxs)return 1;
		else return 0;
	}
	return (dfs(n+1,all+a[n],(long long int)(max(maxs,a[n])))%998244353+dfs(n+1,all,maxs)%998244353)%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>num;
	for(int i=1;i<=num;i++){
		cin>>a[i];
	}
	sort(a+1,a+num+1);
	if(num<3){
		cout<<0;
		return 0;
	}else if(num==3){
		cout<<bool(a[3]*2<a[1]+a[2]);
		return 0;
	}
	cout<<dfs(1,0,0);
	return 0;
}
