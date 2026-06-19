#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long ans;
struct node{
	int cha,i,mx[4];
};
struct cmp{
	bool operator()(node p1,node p2){
		return p1.cha>p2.cha;
	}
};
priority_queue<node,vector<node>,cmp> q[4];
int t,n,a[N][5],len;
void check(int t){
	if(q[t].size()>len){
		node x=q[t].top();
		q[t].pop();
		ans-=x.cha;
		x.i++;
		int i=x.i;
		int nxt=x.mx[i],k=x.mx[0];
		x.cha=a[k][x.mx[i]]-a[k][x.mx[i+1]];
		q[nxt].push(x);
	}
}
void clear(int t){
	while(!q[t].empty())q[t].pop();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		clear(1);clear(2);clear(3);
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)
				scanf("%d",&a[i][j]);
			int mx1=-1,mx2=-1,mx3=-1;
			for(int j=1;j<=3;j++){
				if(a[i][j]>a[i][mx1])
					mx3=mx2,mx2=mx1,mx1=j;
				else if(a[i][j]>a[i][mx2])
					mx3=mx2,mx2=j;
				else mx3=j;
			}			
			ans+=a[i][mx1];
			q[mx1].push({a[i][mx1]-a[i][mx2],1,{i,mx1,mx2,mx3}});
		}
		len=n/2;
		while(q[1].size()>len||q[2].size()>len||q[3].size()>len){
			check(1);
			check(2);
			check(3);
			//printf("size: %d %d %d\n",q[1].size(),q[2].size(),q[3].size());
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
