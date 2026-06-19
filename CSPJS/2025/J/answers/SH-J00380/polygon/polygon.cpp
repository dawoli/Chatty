#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
const int MOD=998244353;
int n,a[N];
queue<int> q;
int ans;
void dfs(int m){
	if(m!=n){
		q.push(a[m]);
		dfs(m+1);
		for(unsigned long long i=1;i<q.size();i++){
			int p=q.front();
			q.pop();
			q.push(p);
		}
		q.pop();
		dfs(m+1);
		return;
	}
	q.push(a[m]);
	long long sum=0;
	int maxn=-1;
	for(unsigned long long i=0;i<q.size();i++){
		int p=q.front();
		sum+=p;
		maxn=max(maxn,p);
		q.pop();
		q.push(p);
	}
	if(sum> 2*maxn){
		ans++;
		ans%=MOD;
	}
	sum=0;
	maxn=-1;
	for(unsigned long long i=1;i<q.size();i++){
		int p=q.front();
		q.pop();
		q.push(p);
	}
	q.pop();
	for(unsigned long long i=0;i<q.size();i++){
		int p=q.front();
		sum+=p;
		maxn=max(maxn,p);
		q.pop();
		q.push(p);
	}
	if(sum> 2*maxn){
		ans++;
		ans%=MOD;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}
