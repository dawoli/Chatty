#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
long long n,k,a[N],s[N],ans;
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			int mx=a[j];
			
			if(s[j]-s[i-1]>mx*2){
				cout<<i<<' '<<j<<endl;
				ans++;
				ans%=mod;
			}
			
			if(j-i>2){
				for(int k=i+1;k<j;k++){
					if(s[j]-s[i-1]-a[k]>2*mx){
						cout<<i<<' '<<j<<' '<<k<<endl;
						ans++;
						ans%=mod;
					}
				}
			}
			
		}
		
		
		
		
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
