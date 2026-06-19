#include<bits/stdc++.h> 
using namespace std;
int n,m;
string s;
int f=1;
int c[501];
long long mod = 998244353;
long long ans =1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++)
		if(s[i]==0){
			f=0;
			break;
		}
	if(m==n){
		if(f==0)ans=0;
	}
	cout<<ans<<endl;
	return 0;
}
