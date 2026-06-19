#include<bits/stdc++.h>
const long long mod=998244353;
const int N=509;
using std::cin;
using std::cout;
int n,m,c[N],p[N];
std::string s;
long long ans;
void solveN(){
	for(int i=0;i<n;i++)p[i]=i;
	int unpass,i;
	do{
		unpass=i=0;
		while(i<n&&unpass<=n-m){
			if(s[i]=='0'||unpass>=c[p[i]])unpass++;
			i++;
		}
		if(unpass<=n-m)ans=(ans+1)%mod;
	}while(std::next_permutation(p,p+n));
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);std::ios::sync_with_stdio(0);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)cin>>c[i];
	if(n<=18)solveN();
	else ans=0;
	cout<<(ans%mod+mod)%mod;
	return 0;
}

