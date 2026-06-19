#include <bits/stdc++.h>
using namespace std;

int n,m,a[10010],xr,k,xrs;
bool cmp(int x,int y){
	return (x>y);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)  cin>>a[i];
	xr=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++)
		if (a[i]==xr){
			xrs=i;
			break;
		}
	if (m%2==0)
		for (int i=1;i<=m;){
			for (int j=1;j<=n;j++){
				k++;
				if (k==xrs){
					cout<<i<<" "<<j;
					return 0; 
				}
			}
			i++;
			for (int j=n;j>=1;j--){
				k++;
				if (k==xrs){
					cout<<i<<" "<<j;
					return 0; 
				}
			}
			i++;
		}
	else{
		int i=0;
		for (i=1;i<=m-1;){
			for (int j=1;j<=n;j++){
				k++;
				if (k==xrs){
					cout<<i<<" "<<j;
					return 0; 
				}
			}
			i++;
			for (int j=n;j>=1;j--){
				k++;
				if (k==xrs){
					cout<<i<<" "<<j;
					return 0; 
				}
			}
			i++;
		}
		for (int j=1;j<=n;j++){
			k++;
			if (k==xrs){
				cout<<i<<" "<<j;
				return 0; 
			}
		}
	}
	return 0;
}
