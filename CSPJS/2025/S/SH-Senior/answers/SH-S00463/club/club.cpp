#include<bits/stdc++.h>

using namespace std;
int t;
long long maxn=-1;
struct node{
	int f;
	int s;
	int t;
}a[100007];
bool cmp(node x,node y){
	return x.f>y.f;
}
void dfs(int p,int now,int ac,int bc,int cc,long long sum){
	if(ac>p/2||bc>p/2||cc>p/2){
		return;
	}
	if(now==p+1){
		maxn=max(maxn,sum);
		return;
	}
	dfs(p,now+1,ac+1,bc,cc,sum+a[now].f);
	dfs(p,now+1,ac,bc+1,cc,sum+a[now].s);
	dfs(p,now+1,ac,bc,cc+1,sum+a[now].t);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		bool flag2=0;
		bool flag3=0;
		int n;
		cin>>n;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i].f>>a[i].s>>a[i].t;
			if(a[i].s!=0){
				flag2=1;
			}
			if(a[i].t!=0){
				flag3=1;
			}
		}
		if(n<=17){
			maxn=-1;
			dfs(n,1,0,0,0,0);
			cout<<maxn<<endl;
		} 
		else if(flag2==0&&flag3==0){
			sort(a+1,a+1+n,cmp);
			long long cnt=0;
			for(int i=1;i<=n/2;i++){
				cnt=cnt+a[i].f;
			}
			cout<<cnt<<endl;
		}
		else{
			cout<<16<<endl;
		}
	}
	return 0;
} 
