#include<bits/stdc++.h>
using namespace std;
long long T;
long long n,a[101010],maxn=-1;
void dfs(long long num,long long lr,long long lb,long long sum){
	if(num>n){
		maxn=max(maxn,sum);
		return;
	}
	if(a[num]==lr) dfs(num+1,a[num],lb,sum+lr);
	else dfs(num+1,a[num],lb,sum);
	if(a[num]==lb) dfs(num+1,lr,a[num],sum+lb);
	else dfs(num+1,lr,a[num],sum);
}
int main(){
	
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		maxn=-1;
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(1,0,0,0);
		cout<<maxn<<endl;
	}
	
	return 0;
} 
