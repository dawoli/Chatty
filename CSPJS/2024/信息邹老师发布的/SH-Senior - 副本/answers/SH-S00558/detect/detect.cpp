#include<bits/stdc++.h>
using namespace std;
int p[100010],T,n,dp[1000010],m,L,s;
long long V;
struct car{
	int d,v,a;
}c[100010];
struct node{
	int l,r;
}t[100010];
bool cmp1(car x,car y){
	return x.d<y.d;
}
bool cmp(node x,node y){
	if(x.r==y.r)
		return x.l<y.l;
	return x.r<y.r;
}
long long calc(int i,int x){
	long long tmp=p[x]-c[i].d;
	if(tmp*2*c[i].a+(long long)c[i].v*c[i].v<0ll)
		return 0;
	return tmp*2*c[i].a+(long long)c[i].v*c[i].v;
}
int work1(int i,int j){
	int tmp=m+1,l=j,r=m;
	while(l<=r){
		int mid=(l+r)/2;
		if(calc(i,mid)>V*V)
			tmp=min(tmp,mid),r=mid-1;
		else
			l=mid+1;
	}
	return tmp;
}
int work2(int i,int j){
	int tmp=0,l=j,r=m;
	while(l<=r){
		int mid=(l+r)/2;
		if(calc(i,mid)>V*V)
			tmp=max(tmp,mid),l=mid+1;
		else
			r=mid-1;
	}
	return tmp;
}
void solve(){
	s=0;
	int l=0,ans=0,flag=1,www;
	cin>>n>>m>>L>>V;
	for(int i=1;i<=n;i++){
		cin>>c[i].d>>c[i].v>>c[i].a;
	}
	for(int i=1;i<=m;i++)
		cin>>p[i];
	sort(c+1,c+n+1,cmp1);
	for(int i=1;i<=n;i++){
		int r=0;
		while(l<=m&&p[l]<c[i].d)
			l++;
		if(c[i].a==0){
			if(l>m)
				continue;
			assert(l<=m);
			if(c[i].v>V)
				s++,t[s].l=l,t[s].r=m;
			continue;
		}
		if(c[i].a>0){
			if(l>m)
				continue;
			int tmp=work1(i,l);
			if(tmp>m)
				continue;
			s++;
			t[s].l=tmp,t[s].r=m;
			continue;
		}
		int tmp=work2(i,l);
		if(tmp<l)
			continue;
		s++;
		t[s].l=l,t[s].r=tmp;
	}
	l=1;
	sort(t+1,t+s+1,cmp);
	for(int i=1;i<=s;i++){
		if(t[i].l==0)
			continue;
		ans++;
		for(int j=1;j<=s;j++){
			if(j!=i&&t[j].l<=t[i].r&&t[j].r>=t[i].r)
				t[j].l=t[j].r=0;
		}
		t[i].l=t[i].r=0;
	}
	cout<<s<<" "<<m-ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--)
		solve();
}
