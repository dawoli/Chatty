#include<bits/stdc++.h>
using namespace std;
bool vst[52][52];
long long n,cnt;
string s; 
void solve(char a,char b){
	int i,j;
	if(a=='D') i=1;
	else if(a=='C') i=2;
	else if(a=='H') i=3;
	else i=4;
	if(b=='A') j=1;
	else if(b=='T') j=10;
	else if(b=='J') j=11;
	else if(b=='Q') j=12;
	else if(b=='K') j=13;
	else j=b-'0';
	if(!vst[i][j]){
		cnt++;
		vst[i][j]=1;
	}
} 
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout); 
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		solve(s[0],s[1]);
	}
	cout<<52-cnt;
	return 0;
} 
