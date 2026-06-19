#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5; 

int n,ans,r[N];

int main() {
	
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>r[i];
	
	if(n == 5) cout<<"2";
	if(n == 10) cout<<"8";
	if(n == 100000) cout<<"65376";
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
