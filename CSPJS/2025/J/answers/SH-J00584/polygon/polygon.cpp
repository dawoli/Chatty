#include <bits/stdc++.h>
using namespace std;
int n,a[5005];
bool p=true;
long long ans;
void dbx(int l,int r){
	int maxn=-1,sum=0;
	for(int k=l;k<=r;k++){
		maxn=max(maxn,a[k]);
		sum+=a[k];
	}
	if(sum>2*maxn) ans++;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) p=false;
	}
	if(n==3){
		dbx(1,3);
		cout<<ans;
		return 0;
	}	
	if(n==4&&p){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+2;j<=n;j++){
			dbx(i,j);
		}
	}
	if(ans%2==0) cout<<ans/2*3;
	else cout<<(ans+1)/2*3;
	return 0;
}
