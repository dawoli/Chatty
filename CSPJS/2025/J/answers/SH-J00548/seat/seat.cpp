#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x,z=0;
	int a[n*m+1],b[n*m+1];
	cin>>x;
	a[0]=x;
	for(int i=1; i<n*m; i++) {
		cin>>a[i];
	}
	//
	sort(a,a+n*m);
	int j=0;
	for(int i=n*m-1; i>=0; i--) {
		b[j]=a[i];
		j++;
	}
	for(int i=0; i<n*m; i++) {
		a[i]=b[i];
	}
	//
	for(int i=0; i<m; i++) {
		for(int j=0;j<n;j++){
			if(a[z]==x){
				cout<<i+1<<" "<<j+1;
				return 0;
			}
			z++;
		}
	}
	return 0;
}
