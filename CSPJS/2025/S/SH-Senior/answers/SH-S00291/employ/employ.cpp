#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int mod=998244353;
char s[N];
int n,m,c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n==m){
		for(int i=1;i<=n;i++){
			if(c[i]==0||s[i-1]=='0'){
				cout<<0<<endl;return 0;
			}
		}
		long long tmp=1;
		for(int i=1;i<=n;i++) tmp=tmp*i%mod;
		cout<<tmp<<endl;
	}
	return 0;
}
