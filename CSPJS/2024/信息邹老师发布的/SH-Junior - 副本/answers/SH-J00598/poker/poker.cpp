#include<bits/stdc++.h>
using namespace std;
int n,cnt;
string s;
bool h[20][10];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>s;char c=s[1];
		if(s[0]=='D'){
			if('2'<=c and c<='9')h[c-'0'][1]=1;
			else if(c=='A')h[1][1]=1;
			else if(c=='T')h[10][1]=1;
			else if(c=='J')h[11][1]=1;
			else if(c=='Q')h[12][1]=1;
			else h[13][1]=1;
		}
		else if(s[0]=='C'){
			if('2'<=c and c<='9')h[c-'0'][2]=1;
			else if(c=='A')h[1][2]=1;
			else if(c=='T')h[10][2]=1;
			else if(c=='J')h[11][2]=1;
			else if(c=='Q')h[12][2]=1;
			else h[13][2]=1;
		}
		else if(s[0]=='H'){
			if('2'<=c and c<='9')h[c-'0'][3]=1;
			else if(c=='A')h[1][3]=1;
			else if(c=='T')h[10][3]=1;
			else if(c=='J')h[11][3]=1;
			else if(c=='Q')h[12][3]=1;
			else h[13][3]=1;
		}
		else{
			if('2'<=c and c<='9')h[c-'0'][4]=1;
			else if(c=='A')h[1][4]=1;
			else if(c=='T')h[10][4]=1;
			else if(c=='J')h[11][4]=1;
			else if(c=='Q')h[12][4]=1;
			else h[13][4]=1;
		}
	}
	for(int i=1;i<=13;i++){
		for(int j=1;j<=4;j++){
			if(!h[i][j])cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

