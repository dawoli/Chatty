#include<bits/stdc++.h> 
using namespace std;
int n,ccount[4][13],ans;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >>n;
	for(int i=0;i<n;i++){
		char temp1,temp2;
		cin >> temp1 >> temp2;
		if(temp1=='D'){
			if(temp2<='9'&&temp2>='2')ccount[0][temp2-'0']=1;
			if(temp2=='A')ccount[0][0]=1;
			if(temp2=='T')ccount[0][9]=1;
			if(temp2=='J')ccount[0][10]=1;
			if(temp2=='Q')ccount[0][11]=1;
			if(temp2=='K')ccount[0][12]=1;
		}
		if(temp1=='C'){
			if(temp2<='9'&&temp2>='2')ccount[0][temp2-'0']=1;
			if(temp2=='A')ccount[1][0]=1;
			if(temp2=='T')ccount[1][9]=1;
			if(temp2=='J')ccount[1][10]=1;
			if(temp2=='Q')ccount[1][11]=1;
			if(temp2=='K')ccount[1][12]=1;
		}
		if(temp1=='H'){
			if(temp2<='9'&&temp2>='2')ccount[0][temp2-'0']=1;
			if(temp2=='A')ccount[2][0]=1;
			if(temp2=='T')ccount[2][9]=1;
			if(temp2=='J')ccount[2][10]=1;
			if(temp2=='Q')ccount[2][11]=1;
			if(temp2=='K')ccount[2][12]=1;
		}
		if(temp1=='S'){
			if(temp2<='9'&&temp2>='2')ccount[0][temp2-'0']=1;
			if(temp2=='A')ccount[3][0]=1;
			if(temp2=='T')ccount[3][9]=1;
			if(temp2=='J')ccount[3][10]=1;
			if(temp2=='Q')ccount[3][11]=1;
			if(temp2=='K')ccount[3][12]=1;
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
			if(ccount[i][j])ans++;
		}
	}
	if(ans>=52)cout << 0 ;
	else cout << 52-ans;


	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
