#include<bits/stdc++.h>
using namespace std;
string num="A23456789TJQK";
string col="DCHS";
string s;
int n,ans,f[20][20];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		f[col.find(s[0])][num.find(s[1])]=1;
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
			if(!f[i][j])ans++;
		}
	}
	cout<<ans;
	return 0;
}
