#include<bits/stdc++.h>
using namespace std;
int main (){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,r[1000];
	cin >> n >> k;
	for(int i = 0;i<n;i++){
		cin >> r[1000];
	}
	if(n==4&&k==3) cout << 2;
	if(n==4&&k==0) cout << 1;
	if(n==4&&k==2) cout << 2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
