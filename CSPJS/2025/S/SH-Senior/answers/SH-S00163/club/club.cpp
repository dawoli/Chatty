#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct node{
	int a,b,c;
}a[100009];
bool cmp(const node &x,const node &y){
	int xx=max(x.a,max(x.b,x.c));
	int yy=max(y.a,max(y.b,y.c));
	int xx2=max(x.a,x.b);
	if(xx2==xx&&x.a==x.b)
		xx2=xx;
	else if(xx2==xx)
		xx2=max(x.c,min(x.a,x.b));
	else
		xx2=max(x.a,x.b);
	int yy2=max(y.a,y.b);
	if(yy2==yy&&y.a==y.b)
		yy2=yy;
	else if(yy2==yy)
		yy2=max(y.c,min(y.a,y.b));
	else
		yy2=max(y.a,y.b);
	if(xx-xx2!=yy-yy2)
		return xx-xx2>yy-yy2;
	else if(xx!=yy)
		return xx>yy;
	else if(xx2!=yy2)
		return xx>yy;
	else
		return min(x.a,min(x.b,x.c))>min(y.a,min(y.b,y.c));
}
int t,n;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].a>>a[i].b>>a[i].c;
	sort(a+1,a+n+1,cmp);
	int ans=0,sa=0,sb=0,sc=0;
	for(int i=1;i<=n;i++){
		node x=a[i];
		if(max(x.a,max(x.b,x.c))==x.a){
			if(sa<n/2)
				ans+=x.a,sa++;
			else if(x.b>x.c)
				ans+=x.b,sb++;
			else
				ans+=x.c,sc++;
		}
		else if(max(x.a,max(x.b,x.c))==x.b){
			if(sb<n/2)
				ans+=x.b,sb++;
			else if(x.a>x.c)
				ans+=x.a,sa++;
			else
				ans+=x.c,sc++;
		}
		else{
			if(sc<n/2)
				ans+=x.c,sc++;
			else if(x.a>x.b)
				ans+=x.a,sa++;
			else
				ans+=x.b,sb++;
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
		solve();
	return 0;
}
