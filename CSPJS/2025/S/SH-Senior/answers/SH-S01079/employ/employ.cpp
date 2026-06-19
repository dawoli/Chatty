#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#define int long long
using namespace std;
const int N=501;
const int mod=998244353;
int c[N],p[N];int ans;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s; s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		p[i]=i;
	}
	do{
		int cnt=0,pp=0;
		for(int i=1;i<=n;i++){
			int j=p[i];
			if(s[i]=='0'||cnt>=c[j]){
				cnt++;
//				 cout<<j<<endl;
			}else{
				pp++;
			}
		}
		if(pp>=m) {ans=(ans+1)%mod;}
//			for(int i=1;i<=n;i++) cout<<p[i]<<" ";cout<<endl;}
		
	}while(next_permutation(p+1,p+n+1));
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
} 
