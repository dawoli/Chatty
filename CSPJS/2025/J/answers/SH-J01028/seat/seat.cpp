#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105];
int b[105];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		b[i]=a[n*m-i+1];
//		cout<<b[i]<<" ";
	}
//	cout<<endl;
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				cnt++;
				if(b[cnt]==r){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				cnt++;
				if(b[cnt]==r){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
