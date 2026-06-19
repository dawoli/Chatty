#include<bits/stdc++.h>
using namespace std;
typedef string str;
str a[10009],b[10009],u,v;
long long  n,m,ans; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		ans=0;
		if(u.size()!=v.size()){
			cout<<"0";
			continue;
		}
		for(int j=1;j<=n;j++){
			if(u.find(a[i])==v.find(b[i]))
				ans++;
		}
		cout<<ans<<endl;
	}                                                                              
	return 0;
}
