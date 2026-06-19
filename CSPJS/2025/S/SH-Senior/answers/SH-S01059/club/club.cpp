#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define N 100005
int t,n,ans;
struct a_info{
	int vl,id;
}a[4];
bool comp(a_info xx,a_info yy){
	return xx.vl>yy.vl;
}
int cnt[4];
multiset<int> S[4];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;while(t--){
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<=3;i++)
			cnt[i]=0,S[i].clear();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)
				scanf("%d",&a[j].vl),
				a[j].id=j;
			sort(a+1,a+3+1,comp);
			int mx=a[1].vl,id=a[1].id,dlt=a[1].vl-a[2].vl;
			if(cnt[id]==n/2){
				int mn=*S[id].begin();
				if(mn<=dlt){
					ans+=mx-mn;
					S[id].erase(S[id].begin());
					S[id].insert(dlt);
				}else{
					ans+=mx-dlt;
				}
			}else{
				ans+=mx;
				cnt[id]++;
				S[id].insert(dlt);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
	/*
	3
	4
	4 2 1
	3 2 4
	5 3 4
	3 5 1
	4
	0 1 0
	0 1 0
	0 2 0
	0 2 0
	2 
	10 9 8
	4 0 0
	*/
}
