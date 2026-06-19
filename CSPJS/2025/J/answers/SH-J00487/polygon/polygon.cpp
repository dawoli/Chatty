#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freoprn("polygon.out","w",stdout);
	long long n,k[5000],maxk,anshe,ans;
	const long long mod=998'244'353;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>k[i];
		if(n>=3){
			for(int j=0;j<n;++j){
			anshe+=k[i];
			}
			maxk=max(k[i],max(k[i+1],k[i+2]));
			if((anshe/maxk)>=2){
				ans++;
			}
		}
		
	}
	cout<<ans%mod;

}
