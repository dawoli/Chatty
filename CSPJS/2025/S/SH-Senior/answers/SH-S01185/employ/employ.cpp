#include<bits/stdc++.h>
using namespace std;
int c[505];
string s;
int n,m;
long long ans=0;
long long mod=998244353;
int jing[505];
long long jc(int x){
	long long aa=1;
	for(int i=n;i>=n-x;i--){
		aa*=i;
		aa%=mod;
	}
	return aa;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	sort(c,c+n);
	if(n<=10){
		
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
	if(m==1){
		int st=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='1'){
				st=i;
				for(int i=1;i<=n;i++){
					if(c[i]>=st){
						ans+=jc(st);
						ans%=mod;
					}
				}
			}
		}
		
		cout<<ans%mod;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
