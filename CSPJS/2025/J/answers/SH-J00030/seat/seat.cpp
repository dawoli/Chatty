#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int R=a[1],p=1;
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[p]==R){
					cout<<i<<' '<<j;
					return 0;
				}
				p++;
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[p]==R){
					cout<<i<<' '<<j;
					return 0;
				}
				p++;
			}
		}
	}
	return 0;
}
