#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ai,w,l=0;
	cin >>n>>m>>ai;
	a[0]=ai;
	for (int i=1;i<n*m;i++){
		cin >>a[i];
	}
	sort(a,a+n*m,cmp);
	for (int i=0;i<n*m;i++){
		if (ai==a[i]){
			w=i;
			break;
		}
	}
	for (int i=1;i<=m;i++){
		if (i%2){
			for (int j=1;j<=n;j++){
				if (l==w){
					cout <<i<<" "<<j;
					return 0;
				}
				l++;
			}
		}
		else{
			for (int j=n;j>0;j--){
				if (l==w){
					cout <<i<<" "<<j;
					return 0;
				}
				l++;
			}
		}
	}
	return 0;
}
