#include <bits/stdc++.h>
using namespace std;
struct Z{
	int l, r;
}z[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n, a, a2[500005]={0};
	long long k;
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> a;
		a2[i]=a2[i-1]^a;
	}
	int x=1;
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			int zz=a2[i-1]^a2[j];
			if(zz==k){
				z[x]={i,j};
				x++;
				break;
			}
		}
	}
	
	for(int i=2; i<x; i++){
		int j=i-1;
		while(z[j].r>=z[i].r&&j>0){
			z[j].l=0;
			j--;
		}
	}
	int j=1, ans=0;
	if(x!=1) ans++;
	while(z[j].l==0&&j<x) j++;
	for(int i=j+1; i<x; i++){
		if(z[i].l==0) continue;
		if(z[j].r>=z[i].l){
			z[i].l=0;
			continue;
		}
		j=i;
		ans++;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
