#include<bits/stdc++.h>
using namespace std;
bool s[210][210];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,cnt=0;
	char a,b;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		if(s[a][b]==0){
			s[a][b]=1;
			cnt++; 
		} 
	}
	cout<<52-cnt;
	return 0;
}
