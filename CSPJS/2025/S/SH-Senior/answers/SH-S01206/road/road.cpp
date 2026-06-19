#include <bits/stdc++.h>
#define int long long
using namespace std;
struct F{
	int f1,f2,f3;
}a[2000050];
bool cmp(F ff1,F ff2){
	return ff1.f3<ff2.f3;
}
int b[15][10050];
int f[10050];
int an(int x){ 
	if(f[x]==x){
		return x;
	}
	f[x]=an(f[x]);
	return f[x];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,a2,c;
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin >> a[i].f1 >> a[i].f2 >> a[i].f3;
	}
	int tot=m;
	for(int i=1;i<=k;i++){
		cin >> c;
		int t=1;
		for(int j=1;j<=n;j++){
			cin >> a2;
			b[i][j]=a2;
			if(a2==0){
				t=j;
			} 
		}
		for(int j=1;j<=n;j++){
			if(j!=t){
				tot++;
				a[tot]={t,j,b[i][j]};
			}
		}
	}
	sort(a+1,a+1+tot,cmp);
	int ans=0;
	for(int i=1;i<=tot;i++){
		if(an(a[i].f1)!=an(a[i].f2)){
			f[an(a[i].f1)]=an(a[i].f2);
			an(a[i].f1);
			ans+=a[i].f3;
		}
	}
	cout << ans << endl;
	return 0;
}
