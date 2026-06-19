#include<bits/stdc++.h>
using namespace std;
int n,m,c[501],f[19],ans;
char s[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)f[i]=i;
	do{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(c[f[i]]<=cnt||s[i]=='0')cnt++;
		}
		if(n-cnt>=m)ans++;
	}while(next_permutation(f+1,f+n+1));
	cout<<ans;
	return 0;
}

