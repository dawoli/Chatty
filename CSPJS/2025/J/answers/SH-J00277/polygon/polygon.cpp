#include<bits/stdc++.h>
using namespace std;
long long MOD=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	int n,maxn=0;
	cin>>n;
	int a[5009];
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>maxn){
			maxn=a[i];
		}
	}
	if(maxn==1){
		long long ans=1;
		for(int i=4;i<=n;i++){
			ans*=i;
			ans%=MOD;
		}
		cout<<ans;
	}
	else{
		long long k=1;
		long long ans=0;
		for(int i=0;i<n;i++){
			k*=2;
		}
		for(int i=0;i<k;i++){
			string s;
			int p=i;
			while(p!=0){
				s+=(p%2+'0');
				p/=2;
			}
			for(int i=0;i<n-s.size();i++){
				s="0"+s;
			}
			long long maxn=-1,sumn=0;
			for(int i=0;i<n;i++){
				if(s[i]=='1'){
					sumn+=a[i];
					if(a[i]>maxn) maxn=a[i];
				}
			}
			if(maxn*2<sumn) ans++;
			ans%=MOD;
		}
		cout<<ans%MOD;
	}
	return 0;
}
