#include<bits/stdc++.h>
using namespace std;
int m,n;
string s;
int c; 
long long ans=1;
int acl;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    acl=n;
    for(int i=1;i<=n;++i){
    	cin>>c;
        if(n-acl>=c) acl--;
	}
	for(int i=1;i<=acl;++i){
		ans*=i;
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}
