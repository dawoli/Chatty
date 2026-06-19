#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int n;
bool card[4][13]={};
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	string s;
	for (int i=0;i<n;i++){
		cin>>s;
		if (s[0]=='D'){
			if (s[1]=='A'){
				card[0][0]=1;
			}else if (s[1]=='T'){
				card[0][9]=1;
			}else if (s[1]=='J'){
				card[0][10]=1;
			}else if (s[1]=='Q'){
				card[0][11]=1;
			}else if (s[1]=='K'){
				card[0][12]=1;
			}else{
				card[0][s[1]-'0'-1]=1;
			}
		}else if (s[0]=='C'){
			if (s[1]=='A'){
				card[1][0]=1;
			}else if (s[1]=='T'){
				card[1][9]=1;
			}else if (s[1]=='J'){
				card[1][10]=1;
			}else if (s[1]=='Q'){
				card[1][11]=1;
			}else if (s[1]=='K'){
				card[1][12]=1;
			}else{
				card[1][s[1]-'0'-1]=1;
			}
		}else if (s[0]=='H'){
			if (s[1]=='A'){
				card[2][0]=1;
			}else if (s[1]=='T'){
				card[2][9]=1;
			}else if (s[1]=='J'){
				card[2][10]=1;
			}else if (s[1]=='Q'){
				card[2][11]=1;
			}else if (s[1]=='K'){
				card[2][12]=1;
			}else{
				card[2][s[1]-'0'-1]=1;
			}
		}else{
			if (s[1]=='A'){
				card[3][0]=1;
			}else if (s[1]=='T'){
				card[3][9]=1;
			}else if (s[1]=='J'){
				card[3][10]=1;
			}else if (s[1]=='Q'){
				card[3][11]=1;
			}else if (s[1]=='K'){
				card[3][12]=1;
			}else{
				card[3][s[1]-'0'-1]=1;
			}
		}
	}
	int ans=0;
	for (int i=0;i<4;i++){
		for (int j=0;j<13;j++){
			if (card[i][j]==0){
				ans++;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

