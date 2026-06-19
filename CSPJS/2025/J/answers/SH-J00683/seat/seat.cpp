#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=15;
bool cmp(int x,int y) {
	return x>y;
}
int n,m,a[N*N];
int seat[N][N];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x=n*m;
	for(int i=1;i<=x;i++) {
		cin>>a[i];
	}
	int my=a[1];
	sort(a+1,a+x+1,cmp);
	int cnt=1;
	for(int i=1;i<=m;i++){
		if(i%2==0) {
			for(int j=n;j>=1;j--) {
				seat[j][i]=a[cnt++];
			}
		}
		else{
			for(int j=1;j<=n;j++){
				seat[j][i]=a[cnt++];
			}
		}
	}
	for(int i=n;i>=1;i--) {
		for(int j=m;j>=1;j--){
			if(seat[i][j]==my){
				cout<<j<<' '<< i;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
		}
	}
	fclose (stdin);
	fclose(stdout);
	return 0;
} 
