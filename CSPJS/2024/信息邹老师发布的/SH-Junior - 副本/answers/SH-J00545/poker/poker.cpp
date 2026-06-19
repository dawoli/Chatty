#include<bits/stdc++.h>
using namespace std;
int ok[4][13];
void gt(string s){
	int a,b;
	if(s[0]=='D') a=0;
	else if(s[0]=='C') a=1;
	else if(s[0]=='H') a=2;
	else a=3;
	if(s[1]=='A') b=0;
	else if(s[1]=='J') b=10;
	else if(s[1]=='Q') b=11;
	else if(s[1]=='K') b=12;
	else if(s[1]=='T') b=9;
	else{
		b=int(s[1]-'0')-1;
	}
	ok[a][b]=1;
} 
int main(){
	freopen("poker.in","r",stdin); 
	freopen("poker.out","w",stdout);
    int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		string tmp;
		cin>>tmp;
		gt(tmp);
	} 
	int ans=0;
	for(int i=0;i<4;i++)
	    for(int j=0;j<13;j++) if(!ok[i][j]) ans++;
	cout<<ans<<endl;
	return 0; 
} 
