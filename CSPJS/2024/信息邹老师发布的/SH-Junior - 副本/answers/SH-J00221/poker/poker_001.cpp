#include<bits/stdc++.h>
using namespace std;
string s;
long long vis[1001],ans=0;
long long n,b,a;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(s[0]=='D') {
			b=0;
		}
		else if(s[0]=='C'){
			b=1;
		}
		else if(s[0]=='H'){
			b=2;
		}
		else{
			b=3;
		}
		if(s[1]=='A'){
			a=1;
		}
		else if(s[1]=='T'){
			a=10;
		}
		else if(s[1]=='J'){
			a=11;
		}
		else if(s[1]=='Q'){
			a=12;
		}
		else if(s[1]=='K'){
			a=13;
		}
		else{
			a=s[1]-'0';
		}
		vis[b*13+a]++;
	}
	for(int i=1;i<=52;i++){
		if(vis[i]==0){
			ans++;
		}
	}
	cout<<ans;
} 
