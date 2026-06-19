#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,r[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>r[i];
	sort(r+1,r+1+n);
	r[0]=0;
	int l=0;
	for(int i=1;i<=n;i++){
		if((l+1)<i&&r[(l+1)]<r[i]) l++;
	}
	cout<<n-l<<endl;
	return 0;
} 
