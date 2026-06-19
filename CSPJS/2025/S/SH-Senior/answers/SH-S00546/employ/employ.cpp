#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    int n,m;
    long long ans=1;
    long long mod=998244353;
    cin>>n>>m;
    int check=1;
    char a[505];
    int b[505];
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]=='0'){check=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	if(check==1){
    for(int i=1;i<=n;i++){
    	ans*=i;
    	ans%=mod;
	}
	cout<<ans;}
	else if(m==n){
		cout<<0;	
	}
	else if(m==1){
		sort(b+1,b+1+n);
		int nai=1;
		int c[505];
		int jian=0;
		for(int i=1;i<=n;i++){
			if(a[i]=='0'){
				nai++;
			}
			else{
				for(int j=1;j<=n;j++){
					if(b[j]>=nai){
						if((j-1-jian)<=0){
							cout<<0;return 0;
						}
						else{
							ans*=(j-1-jian);jian++;ans%=mod;break;
						}
					}
				}
			}
		}
		for(int i=1;i<=n-jian;i++){
			ans*=i;ans%=mod;
		}
		long long ans2=1;
		    for(int i=1;i<=n;i++){
    	ans2*=i;
    	ans2%=mod;
	}
	if(ans2>=ans)cout<<ans2-ans;
	else{
		cout<<ans2+mod-ans;
	}
	}
	else{
		cout<<0;
	}
	return 0;
}
