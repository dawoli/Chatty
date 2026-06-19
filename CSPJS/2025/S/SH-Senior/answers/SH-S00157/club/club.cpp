#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,id;
}a[100010][3];
struct node2{
	int a,b,id;
}b[100010];
bool cmp(node a,node b){
	return a.v>b.v;
} 
bool cmp2(node2 a,node2 b){
	return a.a>b.a;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		memset(b,0,sizeof(b));
		memset(a,0,sizeof(a));
		int n,ans=0,c[4]={0};
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i][0].v>>a[i][1].v>>a[i][2].v,a[i][0].id=1,a[i][1].id=2,a[i][2].id=3;
		for(int i=1;i<=n;i++)sort(a[i],a[i]+3,cmp);
		for(int i=1;i<=n;i++)b[i].a=a[i][0].v-a[i][1].v,b[i].b=a[i][1].v-a[i][2].v,b[i].id=i;
		sort(b+1,b+n+1,cmp2);
		for(int i=1;i<=n;i++){
		//	cout<<c[a[b[i].id][0].id]<<" "<<c[a[b[i].id][1].id]<<endl;
			if(c[a[b[i].id][0].id]<n/2)ans+=a[b[i].id][0].v,c[a[b[i].id][0].id]++;
			else if(c[a[b[i].id][1].id]<n/2)ans+=a[b[i].id][1].v,c[a[b[i].id][1].id]++;
			else ans+=a[b[i].id][2].v,c[a[b[i].id][2].id]++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
