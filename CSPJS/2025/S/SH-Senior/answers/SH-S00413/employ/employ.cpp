#include<bits/stdc++.h>
using namespace std;
int n,m,c[501],a[501],ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		a[i]=i;
	}
	s=' '+s;
	do{
		int wa=0;
		for(int i=1;i<=n;i++) if(c[a[i]]<=wa||s[i]=='0') wa++;
		if(wa<=n-m) ans++;
		if(ans>998244352) ans-=998244353;
	}while(next_permutation(a+1,a+n+1));
	cout<<ans;
	return 0;
}
