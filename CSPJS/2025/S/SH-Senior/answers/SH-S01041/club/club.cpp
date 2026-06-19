#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN=100000+5;
int t;
int n,nn;

int v[MAXN][5];
int vis[MAXN];
int vis2[5];

int tea1=1,teb1=0,tec1=0;
int tea2[MAXN];

//dep -> current people already have a choice
int dfs(int dep, int myd){
	if (dep==n) return myd;
	int ma=0;
	for (int i=1; i<=n; i++){
		if (vis[i]) continue;
		if (vis2[1]<nn){
			vis[i]=1;
			vis2[1]++;
			ma = max(ma,dfs(dep+1,v[i][1]));
			vis[i]=0;
			vis2[1]--;
		}
		if (vis2[2]<nn){
			vis[i]=1;
			vis2[2]++;
			ma = max(ma,dfs(dep+1,v[i][2]));
			vis[i]=0;
			vis2[2]--;
		}
		if (vis2[3]<nn){
			vis[i]=1;
			vis2[3]++;
			ma = max(ma,dfs(dep+1,v[i][3]));
			vis[i]=0;
			vis2[3]--;
		}
	}
//	cout << ma << endl;
	return (ma+myd);
}


signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> t;
	while (t--){
		cin >> n;
		nn=n/2;
		
		if (n==2){
			int maa=0;
			for (int i=1; i<=n; i++) for (int j=1; j<=3; j++) cin >> v[i][j];
			for (int i=1; i<=3; i++){
				for (int j=1; (j<=3 && i!=j); j++) maa=max(maa,v[1][i]+v[2][j]);
			}
			cout << maa << endl;
			continue;
		}
		
		if (n<10){
			for (int i=1; i<=n; i++) for (int j=1; j<=3; j++) cin >> v[i][j];
			for (int i=1; i<=3; i++) vis2[i]=0;
			for (int i=1; i<=n; i++) vis[i]=0;
			cout << dfs(0,0) << endl;
			continue;
		}
		
		else{
			for (int i=1; i<=n; i++){
				cin >> v[i][1] >> v[i][2] >> v[i][3];
				if (v[i][2]!=0 || v[i][3]!=0) tea1=0;
			}
			
			if (tea1){
				int myda1=0;
				for (int i=1; i<=n; i++){
					tea2[i]=v[i][1];
				}
				sort(tea2+1,tea2+n+1,greater<int>());
				for (int i=1; i<=nn; i++){
					myda1+=tea2[i];
				}
				cout << myda1 << endl;
				continue;
			}
		}
	}
	
	return 0;
}
