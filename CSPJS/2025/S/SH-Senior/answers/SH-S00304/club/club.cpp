#include<bits/stdc++.h>
using namespace std;
struct node{
	int a1,a2,a3;
	bool vis=0;
}a[100005];
bool cmp1(node &x,node &y){
	return x.a1>y.a1;
}
bool cmp2(node &x,node &y){
	return x.a2>y.a2;
}
bool cmp3(node &x,node &y){
	return x.a3>y.a3;
}
int ans=0;
bool vis[100005];
void dfs(int i,int num,int aa,int bb,int cc,int n){
	if(aa>n/2)return;
	if(bb>n/2)return;
	if(cc>n/2)return;
	ans=max(ans,num);
	if(i==n+1)return;
	dfs(i+1,num+a[i].a1,aa+1,bb,cc,n);
	dfs(i+1,num+a[i].a2,aa,bb+1,cc,n);
	dfs(i+1,num+a[i].a3,aa,bb,cc+1,n);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int n,t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool flaga=1,flagb=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a2!=0||a[i].a3!=0)flaga=0;
		}
		sort(a+1,a+1+n,cmp1);
		if(flaga==1){
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a1;
			}
			cout<<ans;
		}
		else if(flagb==1){
			for(int i=1;i<=n;i++){
				if(a[i].a1>a[i].a2){
					ans+=a[i].a1;
					a[i].vis=1;
				}
			}
			sort(a+1,a+1+n,cmp2);
			int num=0;
			for(int i=1;i<=n&&num<=n/2;i++){
				if(a[i].vis==0){
					ans+=a[i].a2;
					a[i].vis=1;
					num++;
				}
			}
			for(int i=1;i<=n;i++){
				if(a[i].vis==0)ans+=a[i].a1;
			}
			cout<<ans;
		}
		else{
			dfs(1,0,0,0,0,n);
			cout<<ans<<endl;
			ans=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
