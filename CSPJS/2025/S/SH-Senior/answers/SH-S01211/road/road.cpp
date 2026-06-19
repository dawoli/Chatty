#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int c1,c2,p,ans;
	int a[10009];
	for(int i=1;i<=n;i++){
		a[i]==100000009;
	}
	for(int i=1;i<=n;i++){
		cin>>c1>>c2>>p;
		a[i] = p;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]>a[i+1]){
				int c;
				c = a[i];
				a[i] = a[i+1];
				a[i+1] = c;
			}
		}
	}
	for(int i=1;i<n;i++){
		ans+=a[i];
	}
	cout<<ans;
	return 0;
}
