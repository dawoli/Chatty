#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m, a[105]={0};
	cin >> n >> m;
	cin >> a[0];
	int z=a[0];
	for(int i=1; i<m*n; i++){
		cin >> a[i];
	}
	sort(a,a+m*n,greater<int>());
	for(int i=0; i<m*n; i++){
		if(a[i]==z){
			z=i+1;
			break;
		}
	}
	int c=(z+n-1)/n, r=z%n;
	if(r==0) r=n;
	if(c%2==0) r=n-r+1;
	cout << c <<" "<< r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
