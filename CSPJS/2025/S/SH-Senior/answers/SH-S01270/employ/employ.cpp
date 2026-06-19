#include<bits/stdc++.h>
using namespace std;
const int N=502;
const int mod=998244353;
string s;
bool b[N];
long long n,m,x[N],c[N],ans,fac[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		b[i]=s[i-1]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		x[i]=i; //x[i]表示第i轮面试的是谁 
	}
	do{
		int rejected=0,accepted=0;
		for(int i=1;i<=n;i++){
			if(rejected>=c[x[i]]){
				rejected++; //放弃也算拒绝 
				continue;
			}
			if(b[i]==0){
				rejected++;
			}
			else{
				accepted++;
			}
		}
		if(accepted>=m)
			ans=(ans+1)%mod;
	}while(next_permutation(x+1,x+n+1));
	cout<<ans;
	return 0;
} 
