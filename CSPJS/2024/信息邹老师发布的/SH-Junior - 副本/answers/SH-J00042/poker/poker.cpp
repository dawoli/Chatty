#include<bits/stdc++.h>
using namespace std;
bool have[5][20];
int turn_color(char c){
	if(c=='D')return 1;
	else if(c=='C')return 2;
	else if(c=='H')return 3;
	else return 4;
}
int turn_num(char c){
	if(c>='0' && c<='9')return c-'0';
	if(c=='A')return 1;
	if(c=='T')return 10;
	if(c=='J')return 11;
	if(c=='Q')return 12;
	if(c=='K')return 13;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char color,num;
		cin>>color>>num;
		have[turn_color(color)][turn_num(num)]=true;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(!have[i][j])cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}
