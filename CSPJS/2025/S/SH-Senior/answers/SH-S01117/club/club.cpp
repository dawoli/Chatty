#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+5;
int T,lm,ans,sum[3],n;
struct node{
	int id,w;
	bool operator<(const node&x){
		return w<x.w;
	}
}a[3];
priority_queue<int>dis[3];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		sum[0]=sum[1]=sum[2]=0;
		cin>>n;
		lm=n/2;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				cin>>a[j].w;
				a[j].id=j;
			}
			sort(a,a+3);
			sum[a[2].id]++;
			ans+=a[2].w;
			dis[a[2].id].push(a[1].w-a[2].w);
		}
		int m=sum[0],mid=0;
		if(m<sum[1]){
			m=sum[1];
			mid=1;
		}
		if(m<sum[2]){
			m=sum[2];
			mid=2;
		}
		for(int i=1;i<=m-lm;i++){
			ans+=dis[mid].top();
			dis[mid].pop();
		}
		cout<<ans<<endl;
		for(int i=0;i<3;i++){
			while(!dis[i].empty()){
				dis[i].pop();
			}
		}
	}
	return 0;
}
