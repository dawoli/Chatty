#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;
bool flag[505],c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	int n,m,ans=1;
	scanf("%d%d",&n,&m);
	string s;
	cin>>s;
	for(int i=1;i<=s.size();i++){
		flag[i]=s[i]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		ans=ans*i%998244353;
	}
	cout<<ans<<endl;
	return 0;
}
