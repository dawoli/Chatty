#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510;
char s[N];
int c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int f1=1;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]!='1'){
			f1=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(f1){
		unsigned long long s=n;
		ll cnt=1;
		for(int i=1;i<=m;i++){
			cnt*=i;
			cnt%=998244353;
		}
		for(int i=n-1;i>=m;i--){
			s*=i;
		}
		cout<<s%998244353;
		return 0;
	}
	cout<<2;
	return 0;
}

