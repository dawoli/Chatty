#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],s[505],a[505];
long long ans=0;
const int mod=998244353;
string x;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>x;
	for(int i=0;i<n;i++)cin>>c[i];
	for(int i=0;i<n;i++){
		s[i]=x[i]-48;
	}
	for(int i=0;i<n;i++){
		a[i]=i;
	}
	do{
		int wtg=0;
		for(int i=0;i<n;i++){
			if(wtg>=c[a[i]]){
				wtg++;continue;
			}
			if(s[i]==0)wtg++;
		}
		if(n-wtg>=m){
			ans++;
		}
	}while(next_permutation(a,a+n));
	cout<<ans;
	return 0;
}
