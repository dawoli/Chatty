#include<bits/stdc++.h>
using namespace std;
bool poker[5][14];
int n;
void cardIn(){
	char a,b;
	cin>>a>>b;
	int cColor=0,cPoint=0;
	if(a=='D') cColor=1; 
	if(a=='C') cColor=2;
	if(a=='H') cColor=3;
	if(a=='S') cColor=4;
	if(b=='A') cPoint=1;
	if(b=='T') cPoint=10;
	if(b=='J') cPoint=11;
	if(b=='Q') cPoint=12;
	if(b=='K') cPoint=13;
	if(b>='2' && b<='9') cPoint=b-'0';
	poker[cColor][cPoint]=1;
	return;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cardIn();
	int cnt=52;
	for(int i=1;i<=4;i++)
		for(int j=1;j<=13;j++)
			if(poker[i][j]) cnt--;
	cout<<cnt<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
