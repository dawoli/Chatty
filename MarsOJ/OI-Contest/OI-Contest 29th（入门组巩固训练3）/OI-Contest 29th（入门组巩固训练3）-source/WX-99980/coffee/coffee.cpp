#include<bits/stdc++.h>
using namespace std;
int t;
void solve(){
	string s[6][9];
	int zhou=0;
	for(int i=1;i<=5;i++){
		for(int j=1;j<=8;j++){
			cin>>s[i][j];
			if(s[i][j]=="math")zhou++;
		}
	}
	long long n,m;
	cin>>n>>m;
	int a=n%7;
	long long b=1ll*n/7;
	long long ans=1ll*b*zhou;
	for(int i=m,j=1;j<=a;i++,i=(i-1)%7+1,j++){
		for(int j=1;j<=8;j++){
			if(s[i][j]=="math")ans++;
		}
	}
}
int main(){
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
} 
