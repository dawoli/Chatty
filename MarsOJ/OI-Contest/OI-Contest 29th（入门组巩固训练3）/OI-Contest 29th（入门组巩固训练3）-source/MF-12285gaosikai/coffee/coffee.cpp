#include<bits/stdc++.h>
using namespace std;
string s[10][10];
int n,m,pre[10];
void solve(){
	memset(pre,0,sizeof(pre));
	for(int i=1;i<=5;i++){
		for(int j=1;j<=8;j++){
			cin>>s[i][j];
			if(s[i][j]=="math") pre[i]++;
		}
		pre[i]+=pre[i-1];
	}
	cin>>n>>m;
	int nn,sum=0;
	if(m==1) nn=n;
	else if(m<=5) nn=n-(8-m)%7,sum=pre[5]-pre[m-1];
	else nn=n-(8-m)%7;
	sum=sum+(nn/7)*pre[5];
	if(nn%7!=0) sum=sum+pre[min(nn%7,5)];
	cout<<sum<<endl;
}
int main(){
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}
