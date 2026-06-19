#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+9;
int n,m;
int ap[MAXN],c[MAXN];
string d[MAXN];

int get_bit(int x){
	int ans = 0;
	bool wanquan = true;
	while(x){
		x>>=1;
		if(x!=1 && x&1) wanquan=false;
		ans++;
	}
	if(wanquan) return ans-1;
	else return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ap[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	int roll = get_bit(n);
	for(int i=1;i<=roll;i++){
		cin>>d[i];
	}
	int T;
	while(T--){
		int x[4];
		for(int i=0;i<4;i++) cin>>x[i];
		vector<int> a(n+10);
		for(int i=1;i<=n;i++) a[i] = ap[i] ^ x[i%4];
		for(int i=1;i<=roll;i++){
			for(int j=0;j<d[i].size();j++){
				int c=d[i][j];
				if(c=='0'){
				}
			}
		}
	}
	return 0;
}
