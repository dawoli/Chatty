#include<iostream>
#include<cstdio>
using namespace std;
bool cards[4][13]; 
FILE* fin=freopen("poker.in","r",stdin);
FILE* fout=freopen("poker.out","w",stdout);
int color(char a){
	if (a=='D') return 0;
	if (a=='C') return 1;
	if (a=='H') return 2;
	else return 3;
}
int nums(char a){
	if (a=='A') return 0;
	if (a=='T') return 9;
	if (a=='J') return 10;
	if (a=='Q') return 11;
	else return 12;
}
int main(){
	int n;
	cin>>n;
	char temp1,temp2;
	for(int i=1;i<=n;i++){
		cin>>temp1>>temp2;
		if (temp2>'0'&&temp2<='9'){
			cards[color(temp1)][temp2-'0'-1]=true;
		} 
		else cards[color(temp1)][nums(temp2)]=true;
	}
	int ans=0;
	for (int i=0;i<=3;i++){
		for (int j=0;j<=12;j++){
			if (!cards[i][j]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
