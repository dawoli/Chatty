#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+9;
const int NN = 1e5+9; 
const int NINF = 0xcfcfcfcf;
int n,t;
int a[NN],b[NN],c[NN];
int f[N][N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--){
		cin>>n;
		bool flag = 1;
		for (int i = 1;i <= n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if (b[i] != 0 || c[i] != 0) flag = 0;
		}
		if (flag){
			sort(a+1,a+1+n);
			int sum = 0;
			for (int i = n/2+1;i <= n;i++) sum += a[i];
			cout<<sum<<endl;
		}else{
			memset(f,0xcf,sizeof(f)); 
			f[0][0] = 0;
			for (int i = 1;i <= n;i++){
				for (int j = n/2;j >= 0;j--){
					for (int k = n/2;k >= 0;k--){
						int res1 = 0,res2 = 0,res3 = 0;
						if (j+k <= i && (i-j-k) <= n/2){
							if (j > 0) res1 = max(f[j][k],f[j-1][k] + a[i]);
							if (k > 0) res2 = max(f[j][k],f[j][k-1] + b[i]);
							if ((i-1-j-k) <= n/2) res3 = max(f[j][k],f[j][k] + c[i]);
							f[j][k] = max(max(f[j][k],res1),max(res2,res3));
						}else{
							f[j][k] = NINF;
						}
					}
				}
			}
			int ans = 0;
			for (int i = 0;i <= n/2;i++){
				for (int j = 0;j <= n/2;j++){
					ans = max(ans,f[i][j]);
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
