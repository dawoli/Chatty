#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m;
string s;
int c[505];
bool flag=1;
void solve_all(){
	long long ans=1;for(int i=1;i<=n;i++){
		ans*=i;
		ans%=MOD;
	}
	cout<<ans<<endl;
	return;
}
void solve_al(){
	if(flag==0){
		cout<<0<<endl;
		return;
	}
	else{
		solve_all();
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!='1'){
			flag=0;
			break;
		}
	}
	if(m==n){
		solve_al();
		return 0;
	}
	if(flag){
		solve_all();
		return 0;
	}
	cout<<0<<endl;
	return 0;
}
