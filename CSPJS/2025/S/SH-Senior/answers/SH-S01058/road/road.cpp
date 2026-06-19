#include <bits/stdc++.h>
using namespace std;
struct rd{
	int x;
	int y;
	long long cost;
}road[1000086];
int boss[10086];
bool cmp3(rd a,rd b){
	return a.cost<b.cost;
}
int find(int a){
	if(boss[a]=a)return a;
	return boss[a]=find(boss[a]);
}
void merge(int a,int b){
	int x=find(a);
	int y=find(b);
	boss[x]=y;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int cnt2=0;
	for(int i=0;i<m;i++){
		int a,b;
		long long v;
		cin>>a>>b>>v;
		road[i].x=a;
		road[i].y=b;
		road[i].cost=v;
		cnt2++;
	}
	for(int i=1;i<=n;i++){
		boss[i]=i;
	}
	for(int i=1;i<=k;i++){
		int lj;
		cin>>lj;
		long long a[10086];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				road[cnt2].x=i;
				road[cnt2].y=j;
				road[cnt2].cost=a[i]+a[j];
				cnt2++;
			}
		}
	}
	sort(road,road+cnt2,cmp3);
	int cnt=0;long long ans=0;
	while(cnt!=n-1){
		if(find(road[cnt].x)!=find(road[cnt].y)){
			merge(road[cnt].x,road[cnt].y);
			ans+=road[cnt].cost;
			cnt++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
