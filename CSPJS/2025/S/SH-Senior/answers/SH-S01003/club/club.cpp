#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
typedef pair<int,int> typ;

int t,n;
struct node{
	int val,id;
}a[N][3];
int ans;

priority_queue <typ,vector<typ>,greater<typ> > q[3];//first²î second±àºÅ 

bool cmp(node i,node j){
	return i.val>j.val;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0].val,&a[i][1].val,&a[i][2].val);
			a[i][0].id=0,a[i][1].id=1,a[i][2].id=2;
			sort(a[i],a[i]+3,cmp);
		}
		for(int i=1;i<=n;i++){
			int bst=a[i][0].id;
			q[bst].push({a[i][0].val-a[i][1].val,i});
		}
		for(int i=0;i<3;i++){
			while(q[i].size()>n/2){
				int u=q[i].top().second;
				q[i].pop();
				q[a[u][1].id].push({-1,u});
			}
		}
		int ans=0;
		for(int i=0;i<3;i++){
			while(q[i].size()){
				int u=q[i].top().second;
				int mov=q[i].top().first;
				q[i].pop();
				ans+=a[u][(mov==-1?1:0)].val;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
