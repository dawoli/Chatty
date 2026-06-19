#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],ans;
int num[N][25];
int xr[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i]; xr[i]=xr[i-1]^a[i];
		for(int j=1;j<=20;j++) num[i][j]=num[i-1][j];
	}
	int lst=0;
	for(int i=1;i<=n;i++){
		for(int j=lst;j<i;j++){
			if(int(xr[i]^xr[j])==k){
				lst=i; ans++;
				j=i; continue;
			}
		}
	}
	cout<<ans;
	return 0;
}
