#include<bits/stdc++.h>
using namespace std;
int vis[105];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=0;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		int t1,t2;
		if(s[0]=='D'){
			t1=1;
		}
		else if(s[0]=='C'){
			t1=2;
		}
		else if(s[0]=='H'){
			t1=3;
		}
		else{
			t1=4;
		}
		if(s[1]=='A'){
			t2=1;
		}
		else if(s[1]=='T'){
			t2=10;
		}
		else if(s[1]=='J'){
			t2=11;
		}
		else if(s[1]=='Q'){
			t2=12;
		}
		else if(s[1]=='K'){
			t2=13;
		}
		else{
			t2=s[1]-'0';
		}
		if(!vis[t1*14+t2]){
			ans++;
			vis[t1*14+t2]=1;
		}
	}
	cout<<52-ans;
	return 0;
}
