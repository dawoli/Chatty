#include <bits/stdc++.h>
using namespace std;
int n,r[100009],k;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	int x;
	for(int i=1;i<=n;i++){
		cin>>x;
		r[x]++;
	}
	for(int i=1;i<=100000;i++){
		k=max(k-r[i],0);
		k+=r[i];
	}
	cout<<k;
	return 0;
}

