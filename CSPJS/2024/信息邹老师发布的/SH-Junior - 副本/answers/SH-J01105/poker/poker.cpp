#include<bits/stdc++.h>
using namespace std;
bool a[10][20];
int n,ans=52;
inline int Judge1(char str){
	if(str=='D') return 1;
	else if(str=='C') return 2;
	else if(str=='H') return 3;
	else return 4;
}
inline int Judge2(char str){
	if(str>='2' && str<='9') return int(str-'0');
	else if(str=='A') return 1;
	else if(str=='T') return 10;
	else if(str=='J') return 11;
	else if(str=='Q') return 12;
	else return 13;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char t1,t2;
		cin>>t1>>t2;
		a[Judge1(t1)][Judge2(t2)] = true;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(a[i][j]) ans--;
		}
	}
	cout<<ans;
	return 0;
}
