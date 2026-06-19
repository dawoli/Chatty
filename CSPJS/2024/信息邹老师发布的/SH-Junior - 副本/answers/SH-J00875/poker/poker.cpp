#include<bits/stdc++.h>
using namespace std;
int n,ans=52;
bool t[5][20];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		int a=0;
		if(s[0]=='D'){
			if(s[1]>'1'&&s[1]<='9'){
				a=s[1]-'0';
			}
			else if(s[1]=='T'){
				a=10;
			}
			else if(s[1]=='A'){
				a=1;
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
			t[1][a]=1;
		}
		if(s[0]=='C'){
			if(s[1]>'1'&&s[1]<='9'){
				a=s[1]-'0';
			}
			else if(s[1]=='T'){
				a=10;
			}
			else if(s[1]=='A'){
				a=1;
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
			t[2][a]=1;
		}
		if(s[0]=='H'){
			if(s[1]>'1'&&s[1]<='9'){
				a=s[1]-'0';
			}
			else if(s[1]=='T'){
				a=10;
			}
			else if(s[1]=='A'){
				a=1;
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
			t[3][a]=1;
		}
		if(s[0]=='S'){
			if(s[1]>'1'&&s[1]<='9'){
				a=s[1]-'0';
			}
			else if(s[1]=='T'){
				a=10;
			}
			else if(s[1]=='A'){
				a=1;
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
			t[4][a]=1;
		}
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(t[i][j]){
				ans--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
