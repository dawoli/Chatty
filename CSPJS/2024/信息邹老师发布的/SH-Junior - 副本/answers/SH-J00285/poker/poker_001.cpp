#include<bits/stdc++.h>
using namespace std;
int n,pkr[5][14],ans;
string s;
int clr(string s){
	if(s[0]=='D') return 1;
	if(s[0]=='C') return 2;
	if(s[0]=='H') return 3;
	if(s[0]=='S') return 4;
	return 0;
}int pntnum(string s){
	if(s[1]=='A') return 1;
	if(s[1]=='T') return 10;
	if(s[1]=='J') return 11;
	if(s[1]=='Q') return 12;
	if(s[1]=='K') return 13;
	return s[1]-48;
}int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>s;
		pkr[clr(s)][pntnum(s)]=1;
	}for(int i=1;i<=4;i++) for(int j=1;j<=13;j++) if(!pkr[i][j]) ans++;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}