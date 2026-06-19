#include<bits/stdc++.h>
using namespace std;
int poker_l[20][20];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(s[0]=='D'){
			if(s[1]=='A')poker_l[1][1]++;
			else if(s[1]=='T')poker_l[1][10]++;
			else if(s[1]=='J')poker_l[1][11]++;
			else if(s[1]=='Q')poker_l[1][12]++;
			else if(s[1]=='K')poker_l[1][13]++;
			else poker_l[1][s[1]-48]++;
		}else if(s[0]=='C'){
			if(s[1]=='A')poker_l[2][1]++;
			else if(s[1]=='T')poker_l[2][10]++;
			else if(s[1]=='J')poker_l[2][11]++;
			else if(s[1]=='Q')poker_l[2][12]++;
			else if(s[1]=='K')poker_l[2][13]++;
			else poker_l[2][s[1]-48]++;
		}else if(s[0]=='S'){
			if(s[1]=='A')poker_l[3][1]++;
			else if(s[1]=='T')poker_l[3][10]++;
			else if(s[1]=='J')poker_l[3][11]++;
			else if(s[1]=='Q')poker_l[3][12]++;
			else if(s[1]=='K')poker_l[3][13]++;
			else poker_l[3][s[1]-48]++;
		}else{
			if(s[1]=='A')poker_l[4][1]++;
			else if(s[1]=='T')poker_l[4][10]++;
			else if(s[1]=='J')poker_l[4][11]++;
			else if(s[1]=='Q')poker_l[4][12]++;
			else if(s[1]=='K')poker_l[4][13]++;
			else poker_l[4][s[1]-48]++;
		}
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(poker_l[i][j]==0)cnt++;
		}
	}
	cout<<cnt<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
