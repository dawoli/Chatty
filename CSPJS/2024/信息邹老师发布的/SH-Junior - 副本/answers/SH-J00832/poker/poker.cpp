#include<bits/stdc++.h>
using namespace std;

int n,t1,t2,c;
string s;
bool f[6][60];

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(s[0]=='D') t1=1;
		else if(s[0]=='C') t1=2;
		else if(s[0]=='H') t1=3;
		else if(s[0]=='S') t1=4;
		if(s[1]=='A') t2=1;
		else if(s[1]=='2') t2=2;
		else if(s[1]=='3') t2=3;
		else if(s[1]=='4') t2=4;
		else if(s[1]=='5') t2=5;
		else if(s[1]=='6') t2=6;
		else if(s[1]=='7') t2=7;
		else if(s[1]=='8') t2=8;
		else if(s[1]=='9') t2=9;
		else if(s[1]=='T') t2=10;
		else if(s[1]=='J') t2=11;
		else if(s[1]=='Q') t2=12;
		else if(s[1]=='K') t2=13;
//		cout<<t1<<" "<<t2<<"\n";
		f[t1][t2]=true;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(!f[i][j]) c++;
		}
	}
	cout<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//GL@17SXYZ
