#include<iostream>
using namespace std;
int main(){
	freopen("./poker.in","r",stdin);
	freopen("./poker.out","w",stdout);
	
	int n,x,y,space[4][14]={0},count=0;
	char t,s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t>>s;
		if(t=='D') x=0;
		else if(t=='C') x=1;
		else if(t=='H') x=2;
		else if(t=='S') x=3;
		if(s=='T') y=10;
		else if(s=='J') y=11;
		else if(s=='Q') y=12;
		else if(s=='K') y=13;
		else if(s=='A') y=1;
		else y=s-'0';
		if(space[x][y]==0) {
			count++;
			space[x][y]=1;
		}
	}
	cout<<52-count;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
