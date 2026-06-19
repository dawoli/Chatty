#include<bits/stdc++.h>
using namespace std;
const long long N=509;
const long long Mod=998244353;
long long c[N];
long long n,m;
string s;
long long ans;
long long rk[N];
bool flag=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	for(long long i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) flag=0;
		rk[i]=i;
	}
	s='%'+s;
	if(n<=10){
		do{
//			for(long long i=1;i<=n;i++){
//				cout<<"rk["<<i<<"]="<<rk[i]<<endl;
//			}
			long long cnt=0,k=0;
			for(long long i=1;i<=n;i++){
				long long nw=c[rk[i]];
				if(k>=nw||s[i]=='0'){
					k++;
				}
				else{
					cnt++;
				}
			}
//			cout<<"cnt="<<cnt<<endl;
//			cout<<endl;
			ans=(ans+(cnt>=m))%Mod;
//			cout<<"ans="<<ans<<endl;
		}while(next_permutation(rk+1,rk+1+n));
	}
	else if(m==n&&!flag){
		cout<<"0\n";
		return 0;
	}
	else{
		ans=1;
		for(long long i=2;i<=n;i++){
			ans=(ans*i)%Mod;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
