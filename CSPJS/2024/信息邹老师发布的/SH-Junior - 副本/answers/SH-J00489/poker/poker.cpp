#include<bits/stdc++.h>
using namespace std;
int change(char b,char a) {
	int c;
	if(a=='A')c=1;
	else if(a>='2'&&a<='9')c=a-'0';
	else if(a=='T')c=10;
	else if(a=='J')c=11;
	else if(a=='Q')c=12;
	else c=13;
	if(b=='D')return c*4-4;
	else if(b=='C')return c*4-3;
	else if(b=='H')return c*4-2;
	else return c*4-1; }
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int t,cnt=0;
	bool p[53]= {0 };
	cin>>t;
	while(t--) {
		char a,b;
		cin>>a>>b;
		p[change(a,b)]=1;}
	for(int i=0;i<52;i++){
		if(p[i]==0)cnt++;}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0; }
