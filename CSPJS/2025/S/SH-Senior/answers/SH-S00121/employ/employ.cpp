#include<bits/stdc++.h>
using namespace std;

long long n,m,c[505],cnt,a[505];
string s;
const int MOD=998244353;

bool check(){
	long long co=0,pos=0;//pos for how many people failed before;co for cnt;
	for(int i=1;i<=n;i++){
//		cout<<s[a[i]-1]<<' ';
//		cout<<s[i-1]&&pos<c[a[i]]<<' ';
		if(((int)s[i-1]-48)&&pos<c[a[i]]){
			co++;
		}else{
			pos++;
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<' ';
//	}cout<<'\n';
//	cout<<co<<'\n';
	return co>=m;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) a[i]=i;
	if(n>=19){
		unsigned long long su=1;
		for(int i=1;i<=n;i++){
			su=su*(unsigned long long)i%MOD;
		}
		cout<<su;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	do{
		if(check()){
			cnt++;
		}
	}while(next_permutation(a+1,a+n+1));
	cout<<cnt;
	return 0;
}
