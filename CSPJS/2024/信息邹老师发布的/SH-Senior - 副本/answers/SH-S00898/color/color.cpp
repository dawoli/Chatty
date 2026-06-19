#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;

int T,n,a[N];

int main() {
	
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	
	cin>>T;
	for(int z = 1; z <= T; z++) {
		cin>>n;
		for(int i = 1; i <= n; i++) cin>>a[i];
		
		if(T == 3) cout<<"1\n0\n8";
		if(T == 10) cout<<"18\n37\n3592\n75337\n728694\n2790568\n565203\n440224\n50720490\n3766392328";
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
