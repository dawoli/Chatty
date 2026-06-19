#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const long long mod=998244353;
long long n,a[5005],num[5005];
unsigned long long cnt=0;
void dfs(int step,int now,int maxn)
{
	if(now>2*maxn) cnt++;
	if (step>n){
		return;
	}
	for (int i=step;i<=n;i++){
		dfs(i+1,now+num[i],num[i]);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>num[i];
	}
	sort(num+1,num+n+1);
	dfs(1,0,0);
	cout<<cnt%mod;
	return 0;
}
