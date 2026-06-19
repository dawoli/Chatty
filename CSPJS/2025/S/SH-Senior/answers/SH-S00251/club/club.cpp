#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n;
int cnt1,cnt2,cnt3;
long long ans;
struct node{
	int a,b,c;
}x[100005];
bool cmp(node u,node v){
	int fx,sx,fy,sy;
	fx=max(u.a,max(u.b,u.c));
	fy=max(v.a,max(v.b,v.c));
	if(fx==u.a) sx=max(u.b,u.c);
	if(fx==u.b) sx=max(u.a,u.c);
	if(fx==u.c) sx=max(u.b,u.a);
	if(fy==v.a) sy=max(v.b,v.c);
	if(fy==v.b) sy=max(v.a,v.c);
	if(fy==v.c) sy=max(v.b,v.a);
	return fx-sx>fy-sy;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		cnt1=0;
		cnt2=0;
		cnt3=0;
		for(int i=1;i<=n;i++) cin>>x[i].a>>x[i].b>>x[i].c;
		sort(x+1,x+n+1,cmp);
		for(int i=1;i<=n;i++){
			int fx,sx;
			fx=max(x[i].a,max(x[i].b,x[i].c));
			if(fx==x[i].a&&cnt1<n/2){
				ans+=x[i].a;
				cnt1++;
				continue;
			}
			if(fx==x[i].b&&cnt2<n/2){
				ans+=x[i].b;
				cnt2++;
				continue;
			}
			if(fx==x[i].c&&cnt3<n/2){
				ans+=x[i].c;
				cnt3++;
				continue;
			}
			if(fx==x[i].a) sx=max(x[i].b,x[i].c);
			if(fx==x[i].b) sx=max(x[i].a,x[i].c);
			if(fx==x[i].c) sx=max(x[i].b,x[i].a);
			if(sx==x[i].a){
				ans+=x[i].a;
				cnt1++;
				continue;
			}
			if(sx==x[i].b){
				ans+=x[i].b;
				cnt2++;
				continue;
			}
			if(sx==x[i].c){
				ans+=x[i].c;
				cnt3++;
				continue;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
