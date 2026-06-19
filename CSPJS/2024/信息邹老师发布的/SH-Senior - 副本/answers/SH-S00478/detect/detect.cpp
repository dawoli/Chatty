#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
struct Car{
	int d,v,a;
	int l,r;//在第l和r个摄像头间超速
	bool vis;
}c[N];
int p[N];
int n,m,L,V;
int ans=0;
int x;
bool cmp(Car x,Car y){
	if(x.r==y.r)return x.l<y.l;
	return x.r<y.r;
}
void solve1(){
	for(int i=1;i<=n;i++){
		if(c[i].a>0){
			if(c[i].v>V)
				x=c[i].d;
			else x=c[i].d+ceil((V*V-c[i].v*c[i].v)/(2*c[i].a));
			c[i].l=lower_bound(p+1,p+m+1,x)-p;//遇到的第一个测速点
			c[i].r=m;
			if(c[i].l>=1&&c[i].r<=m&&c[i].l<=c[i].r){
				ans++;	
			}
			else c[i].vis=1;
		}
		else if(c[i].a==0){
			if(c[i].v<=V||c[i].d>p[m]){
				c[i].vis=1;
			}
			else{
				ans++;
				c[i].l=lower_bound(p+1,p+m+1,c[i].d)-p;//遇到的第一个测速点
				c[i].r=m;
			}
		}
		else{
			if(c[i].v<=V){
				c[i].vis=1;
				continue;
			}
			x=c[i].d+floor(abs((V*V-c[i].v*c[i].v))/(abs(2*c[i].a)));
			c[i].l=lower_bound(p+1,p+m+1,c[i].d)-p;//遇到的第一个测速点
			c[i].r=upper_bound(p+1,p+m+1,x)-p-1;//超速时遇到的最后一个测速点
			if(c[i].r<=m&&c[i].l>=1&&c[i].l<=c[i].r){
				ans++;
			}
			else c[i].vis=1;
		}
		//if(m==73251&&c[i].vis==0)cout<<c[i].l<<" "<<c[i].r<<endl;
	}
	cout<<ans<<" ";
	//cout<<endl;
	int cnt=0,last=-1;
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(c[i].vis){
			continue;
		}
		if(c[i].l<=last)continue;
		cnt++;
		last=c[i].r;
	}
	cout<<m-cnt<<endl;
	return;
}
void solve2(){
	for(int i=1;i<=n;i++)
		if(c[i].v>V)ans++;
	if(ans==0)m++;
	cout<<ans<<" "<<m-1<<endl;
	return;
}
void solve3(){
	for(int i=1;i<=n;i++){
		if(c[i].v*c[i].v+2*c[i].a*(p[m]-c[i].d)>V*V)ans++;
	}
	if(ans==0)m++;
	cout<<ans<<" "<<m-1<<endl;
}
void solve(){
	ans=0;
	memset(c,0,sizeof c);
	cin>>n>>m>>L>>V;
	int maxa=-2e9,mina=2e9;
	for(int i=1;i<=n;i++){
		cin>>c[i].d>>c[i].v>>c[i].a;
		maxa=max(maxa,c[i].a);
		mina=min(mina,c[i].a);
	}
	for(int i=1;i<=m;i++)cin>>p[i];
	if(maxa==0&&mina==0)solve2();
	else if(mina>0)solve3();
	else
	solve1();
}
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
