#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[100005][4], b[100005];
long long f[205][205][205];
bool cmp(int &a, int &b){
	return a>b;
}
void work(int n){
	long long res = 0;
	for(int i = 1; i <= n; i++){
		b[i] = a[i][1];
	}
	sort(b+1, b+n+1, cmp);
	for(int i = 1; i <= n/2; i++){
		res += b[i];
	}
	cout << res << endl;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while(T--){
		memset(f, 0, sizeof f);
		int n;
		cin >> n;
		for(int i = 1; i<= n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		if(n>200){
			work(n);
		}else{
			for(int i = 1; i <= n; i++){
				for(int j = 0; j <= i; j++){
					for(int k = 0; k <= i-j; k++){
						int l = i-j-k;
						if(l>0)f[i][j][k] = max(f[i][j][k], f[i-1][j][k]+a[i][3]);
						if(j>0)f[i][j][k] = max(f[i][j][k], f[i-1][j-1][k]+a[i][1]);
						if(k>0)f[i][j][k] = max(f[i][j][k], f[i-1][j][k-1]+a[i][2]);
						//cout << f[i][j][k] << " ";
					}
					//cout << endl;
				}
				//cout << endl;
			}
			long long res = 0;
			for(int i =1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					if(i<=n/2&&j<=n/2&&(n-i-j)<=n/2){
						res = max(res, f[n][i][j]);
					}
				}
			}	
			cout << res << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
