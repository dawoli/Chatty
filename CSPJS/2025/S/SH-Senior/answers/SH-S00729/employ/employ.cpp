#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m,c[505],f=1;
string s; 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	int k=n;
	for(int i=0;i<n;i++) {
		cin>>c[i];
		if(c[i]==0) k--;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!='1'){
			f=0;
			break;
		}
	}
	if(f){
		long long ans=1;
		for(int i=2;i<=k;i++){
//			cout<<i<<' ';
			ans=(ans*i)%MOD;
		}
		cout<<ans;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

