#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
struct node{
	int w,id,bel,w2;
};
bool cmp(node x,node y){
	return x.w-x.w2>y.w-y.w2;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,cnt[4]={0,0,0,0},ans=0;
		node a[N];
		cin>>n;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			int maxn=max(x,max(y,z)),minn=min(min(x,y),z);
			a[i]={maxn,i,(maxn==x)*1+(maxn==y)*2+(maxn==z)*3,x+y+z-maxn-minn};
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(cnt[a[i].bel]==n/2){
				ans+=a[i].w2;
				continue;
			}
			ans+=a[i].w; 
			cnt[a[i].bel]++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
