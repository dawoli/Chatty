#include<bits/stdc++.h>
using namespace std;
int m,n,cnt=0;
int c[505];
char s[505];
bool typea=true;
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]!='0')
			typea=false;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)
			cnt++;
	}
	if(typea){
		for(int i=2;i<=n-cnt;i++)
			ans*=i;
		cout<<ans;
		return 0;
	}
	return 0;
}
