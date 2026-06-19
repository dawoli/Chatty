#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n;
long long ans=0;
struct node{int a,b,c;};
node a[100005];
bool cmp1(node x,node y){
	return x.a>y.a;
}
bool cmp2(node x,node y){
	if(abs(x.a-x.b)!=abs(y.a-y.b)) return abs(x.a-x.b)>abs(y.a-y.b);
	return max(x.a,x.b)>max(y.a,y.b);
}
bool check_break_1(){
	for(int i=1;i<=n;i++) if(a[i].b!=0||a[i].c!=0) return false;
	sort(a+1,a+n+1,cmp1);
	for(int i=1;i<=n/2;i++) ans+=a[i].a;
	cout<<ans<<"\n";
	return true;
}
bool check_break_3(){
	for(int i=1;i<=n;i++) if(a[i].c!=0) return false;
	sort(a+1,a+n+1,cmp2);
	int na=0,nb=0;
	for(int i=1;i<=n;i++){
		if(nb==n/2||a[i].a>=a[i].b) ans+=a[i].a,na++;
		if(na==n/2||a[i].a<a[i].b) ans+=a[i].b,nb++;
	}
	cout<<ans<<"\n";
	return true;
}
void dfs(int k,long long s,int na,int nb,int nc){
	if(k>n){
		ans=max(ans,s);
		return;
	}
	if(na<n/2) dfs(k+1,s+a[k].a,na+1,nb,nc);
	if(nb<n/2) dfs(k+1,s+a[k].b,na,nb+1,nc);
	if(nc<n/2) dfs(k+1,s+a[k].c,na,nb,nc+1);
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
	}
	ans=0;
//	if(check_break_1()) return;
//	if(check_break_3()) return;
	dfs(1,0,0,0,0);
	cout<<ans<<"\n";
}
int main(){
	freopen("club3.in","r",stdin);
	freopen("club3.out","w",stdout);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}
