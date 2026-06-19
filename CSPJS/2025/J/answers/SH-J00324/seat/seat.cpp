#include <bits/stdc++.h>
#define N 108
using namespace std;
int n,m,a[N];
int cnt;
bool cmp(int d1,int d2){
	return d1>d2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int R=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				cnt++;
				if(a[cnt]==R){
					cout<<i<<' '<<j<<endl;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				cnt++;
				if(a[cnt]==R){
					cout<<i<<' '<<j<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
