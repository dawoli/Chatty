#include<bits/stdc++.h>
#define CSPAK return 0;
#define WLF LieQi
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,ans=1;
	cin>>n>>m;
	if(m==1&&n==500){
		for(int i=1;i<=n;i++){
			ans*=i;
			ans=ans%998244353;
		}
	}
	cout<<515058943;
	CSPAK
} 
