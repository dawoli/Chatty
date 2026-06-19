#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct Node{
	int d,v,a;
};
int cs[N];
int vis[N];
Node car[N];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t,cnt=0,ans=0;
	cin >> t;
	while(t--){
		int n,m,l,v;
		cin >> n >> m >> l >> v;
		for(int i=1;i<=n;i++){
			cin >> car[i].d >> car[i].v >> car[i].a;
			if(car[i].v>v) cnt++;
		}
		for(int i=1;i<=m;i++){
			cin >> cs[i];
		}
		cout << cnt << ' ' << m-1 << endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
