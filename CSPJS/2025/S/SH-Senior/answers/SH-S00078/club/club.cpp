//100pts
#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n;
struct node{
	int a1,a2,a3;
	int diff;
} f[100009];
node fa[100009], fb[100009], fc[100009];
int res=0;
bool cmp(node x, node y){
	return x.diff<y.diff;
}
void solve2(){
	//step1 fenlei
	int p1=0; int p2=0; int p3=0;
	for(int i=1;i<=n;i++) {
		if(f[i].a1>=f[i].a2 && f[i].a1>=f[i].a3) fa[++p1]=f[i];
		else if(f[i].a2>=f[i].a1 && f[i].a2>=f[i].a3) fb[++p2]=f[i];
		else if(f[i].a3>=f[i].a1 && f[i].a3>=f[i].a2) fc[++p3]=f[i];
	}
	for(int i=1; i<=p1; i++)  res+=fa[i].a1;
	for(int i=1; i<=p2; i++)  res+=fb[i].a2;
	for(int i=1; i<=p3; i++)  res+=fc[i].a3;
	if(p1<=n/2 && p2<=n/2 && p3<=n/2) {cout<<res<<endl; return;}
	if(p1>n/2) {
		for(int i=1;i<=p1;i++) 
			fa[i].diff=fa[i].a1-max(fa[i].a2,fa[i].a3);
		sort(fa+1,fa+p1+1,cmp);	
		for(int i=1;i<=p1-n/2;i++) {
			res-=fa[i].a1; res+=max(fa[i].a2,fa[i].a3);
		}
		cout<<res<<endl; return;
	}
	if(p2>n/2) {
		for(int i=1;i<=p2;i++) 
			fb[i].diff=fb[i].a2-max(fb[i].a1,fb[i].a3);
		sort(fb+1,fb+p2+1,cmp);	
		for(int i=1;i<=p2-n/2;i++) {
			res-=fb[i].a2; res+=max(fb[i].a1,fb[i].a3);
		}
		cout<<res<<endl; return;
	}
	if(p3>n/2) {
		for(int i=1;i<=p3;i++) 
			fc[i].diff=fc[i].a3-max(fc[i].a1,fc[i].a2);
		sort(fc+1,fc+p3+1,cmp);	
		for(int i=1;i<=p3-n/2;i++) {
			res-=fc[i].a3; res+=max(fc[i].a1,fc[i].a2);
		}
		cout<<res<<endl; return;
	}
}

signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++)
			cin>>f[i].a1>>f[i].a2>>f[i].a3;
		solve2();
		res=0;
		memset(f,0,sizeof(f));
		memset(fa,0,sizeof(fa));memset(fb,0,sizeof(fb));memset(fc,0,sizeof(fc));
	}
	return 0;
} 
