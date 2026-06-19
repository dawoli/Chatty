#include <bits/stdc++.h>
using namespace std;
int t,n,ans,x,y,z,k,m[5];
struct node{
	int fb,f;
}a[500005];
bool cmp(node a,node b){
	return a.fb>b.fb;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		ans = m[1] = m[2] = m[3] = 0;
		cin >> n;
		for(int i = 1;i<=n;i++){
			cin >> x >> y >> z;
			k = x+y+z-min(min(x,y),z)-max(max(x,y),z);
			ans+=k;
			a[i].fb = max(max(x,y),z)-k;
			if(max(max(x,y),z)==x) a[i].f = 1;
			else if(max(max(x,y),z)==y) a[i].f = 2;
			else a[i].f = 3;
		}
		sort(a+1,a+n+1,cmp);
		for(int i = 1;i<=n;i++){
			if(m[a[i].f]<n/2){
				m[a[i].f]++;
				ans+=a[i].fb;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
