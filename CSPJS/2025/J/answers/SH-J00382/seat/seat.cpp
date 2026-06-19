#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=105;
int n,m,a[N],mp[15][15];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int t=a[1];
	sort(a+1,a+1+n*m,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				mp[j][i]=a[++cnt];
			}
		}else{
			for(int j=n;j>=1;j--){
				mp[j][i]=a[++cnt];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(mp[i][j]==t){
				cout << j << " " << i;
				return 0;
			}
		}
	}
	return 0;
}

