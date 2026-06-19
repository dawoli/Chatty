#include<iostream>
#include<algorithm>
using namespace std;
int t;
int n;
struct node{
	int a1,a2,a3;
}a[100010];
bool cmp(node x,node y){
	return x.a1>y.a1;
}
int maxn=-1;
void dfs(int now,int a1,int a2,int a3,int ans){
	if(now>=n){
		if(ans>maxn) cout<<a1<<" "<<a2<<" "<<a3<<"\n"; 
		maxn=max(maxn,ans);
		return;
	}
	if(a1<n/2) dfs(now+1,a1+1,a2,a3,ans+a[now].a1);
	if(a2<n/2) dfs(now+1,a1,a2+1,a3,ans+a[now].a2); 
	if(a3<n/2) dfs(now+1,a1,a2,a3+1,ans+a[now].a3);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		bool sp1=1;//A 	
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a2!=0||a[i].a3!=0) sp1=0;
		}
		if(sp1){
			sort(a,a+n,cmp);
			int ans=0;
			for(int i=0;i<n/2;i++) ans+=a[i].a1;
			cout<<ans<<"\n";
			continue;
		}
		maxn=-1;
		dfs(0,0,0,0,0);
		cout<<maxn<<"\n";
	}
}
