#include <bits/stdc++.h>
using namespace std;
int t,n,m,a[100005],c[100005],f[100005],d[25][100005],x[5],ans;
string s;
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++) cin >> a[i];
	for(int i = 1;i<=m;i++) cin >> c[i];
	for(int i = 1;i<=log2(n);i++){
		int q = log2(n);
		cin >> s;
		for(int j = 1;j<=(1<<(q-i));j++) d[q-i+1][j] = s[j-1];
	}
	cin >> t >> x[0] >> x[1] >> x[2] >> x[3];
	for(int i = 1;i<=n;i++) a[i]^=x[i%4];
	for(int i = 1;i<=m;i++){
		int q = log2(c[i]);
		for(int j = 1;j<=q;j++){
			if(j==1){
				for(int k = 1;k<=n;k+=2){
					if(d[q-j+1][k/2+1]==0){
						if(a[k]>=j) f[k/2+1] = k;
						else f[k/2+1] = k+1;
					}
					else if(d[q-j+1][k/2+1]==1){
						if(a[k+1]>=j) f[k/2+1] = k+1;
						else f[k/2+1] = k;
					}
				}
			}
			else{
				for(int k = 1;k<=1<<(q-j);k+=2){
					if(d[q-j+1][k/2+1]==0){
						if(a[f[k]]>=j) f[k/2+1] = k;
						else f[k/2+1] = k+1;
					}
					else if(d[q-j+1][k/2+1]==1){
						if(a[f[k+1]]>=j) f[k/2+1] = k+1;
						else f[k/2+1] = k;
					}
				}
			}
		}
		ans^=(i*f[1]);
	}
	cout << ans << endl;
	return 0;
}
