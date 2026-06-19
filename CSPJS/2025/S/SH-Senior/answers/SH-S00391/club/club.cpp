#include<bits/stdc++.h>
using namespace std;
const int N=1.1e5;
int n,a[N][5],T;
void input(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)for(int j=1;j<=3;j++)scanf("%d",&a[i][j]);
}
void solve(){
	priority_queue<int>pq[4];
	int tepv[4];
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++)tepv[j]=a[i][j];
		sort(tepv+1,tepv+4);
		for(int j=1;j<=3;j++){
			if(a[i][j]==tepv[3]){
				ans+=tepv[3];
				pq[j].push(tepv[2]-tepv[3]);
				break;
			}
		}
	}
	for(int i=1;i<=3;i++){
		while(pq[i].size()>n/2){
			ans+=pq[i].top();
			pq[i].pop();
		}
	}
	printf("%lld\n",ans);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)input(),solve();
	return 0;
}
