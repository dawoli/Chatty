#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a[121], s[11][11];
	cin >> n >> m;
	cin>>a[0];
	int b= a[0];
	for(int i=1; i<n*m; i++) cin>>a[i];
	sort(a, a+n*m)
	int x = 1,c=1,r=1;
	for(int i = 0; i<n*m; i++){
		if((i+1)%n==0) x=-x,c++,j+=x;
		if(a[i] = b){
			b++;
		}
	}
	return 0;
}
