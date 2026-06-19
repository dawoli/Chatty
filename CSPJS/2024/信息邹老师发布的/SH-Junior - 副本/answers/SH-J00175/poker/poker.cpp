#include<bits/stdc++.h>
using namespace std;
int n,cnt=52;
string s;
bool vis[53];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		int id;
		if(s[0]=='S'){
			id+=13;
		}
		else if(s[0]=='D'){
			id+=26;
		}
		else if(s[0]=='C'){
			id+=39;
		}
		if('2'<=s[1]&&'9'>=s[1]){
			id+=s[1]-'0';
		}
		else if(s[1]=='A'){
			id+=1;
		}
		else if(s[1]=='T'){
			id+=10;
		}
		else if(s[1]=='J'){
			id+=11;
		}
		else if(s[1]=='Q'){
			id+=12;
		}
		else if(s[1]=='K'){
			id+=13;
		}
		if(vis[id])continue;
		vis[id]=1;
		cnt--;
	}
	cout<<cnt;
	return 0;
}

