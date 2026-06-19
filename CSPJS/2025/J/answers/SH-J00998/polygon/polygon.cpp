#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int sum[5005];
long long ans=0;
int chosen[5005];
int dans;
void dfs(int beg,int d,int summ){
	if(d>=beg){
		int cnt=0;
		for(int i=1;i<beg;i++){
			if(chosen[i]==1){
				cnt++;
			}
		}
		if(summ>a[beg]&&cnt>=1) dans++;
		return;
	}
	chosen[d]=1;
	dfs(beg,d+1,summ+a[d]);
	chosen[d]=0;
	dfs(beg,d+1,summ);	

}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+1+n);
	sum[1]=a[1];
	for(int i=2;i<=n;i++)	sum[i]=sum[i-1]+a[i];
	int beg=n;
	for(int i=beg;i>=0;i--){
		if(sum[beg-1]<a[beg]) continue;
		dans=0;
		dfs(i,1,0);
		ans+=dans;
	}
	cout<<ans%998244353;
	return 0;
}
