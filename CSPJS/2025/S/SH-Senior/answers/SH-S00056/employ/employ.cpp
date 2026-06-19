#include<iostream>
int n,m;
int s[510],c[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		if(c[i]>s[i])ans=ans*i;
	}
	cout<<ans<<endl;
}
