#include<bits/stdc++.h>
using namespace std;
const int N=3*1e5+5;
struct Node{
	int v,id,g;
	bool operator <(struct Node t){
		return v<t.v;
	}
}a[N];
int n,st[N/3],tot[5];
int solve(){
	memset(st,false,sizeof st);
	memset(tot,0,sizeof tot);
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[++cnt].v,&a[++cnt].v,&a[++cnt].v);
		a[cnt].g=3,a[cnt-1].g=2,a[cnt-2].g=1;
		a[cnt].id=i,a[cnt-1].id=i,a[cnt-2].id=i;
	}
	sort(a+1,a+cnt+1);
	int ans=0;
	for(int i=cnt;i;i--){
		if(st[a[i].id]||tot[a[i].g]>=n/2)continue;
		st[a[i].id]=true,tot[a[i].g]++;
		ans+=a[i].v;
	}
	return ans;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		cout<<solve()<<'\n';
	}
	return 0;
} 
