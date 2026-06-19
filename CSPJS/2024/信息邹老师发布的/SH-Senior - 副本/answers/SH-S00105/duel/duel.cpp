#include <bits/stdc++.h>
using namespace std;
long long n,r[100010],rp[100010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		rp[r[i]]++;
	}
	sort(rp,rp+100010);
	cout<<rp[100009];
	return 0;
}
