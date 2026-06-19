#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	string a[53]={};
	char d[14]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
	int b[53]={},sum,c,jie=52;
	cin>>sum;
	for(int i=0;i<sum;i++){
		cin>>a[i];
	}
	for(int i=0;i<sum;i++){
		if(a[i][0]=='D'){
			c=1;
		}else if(a[i][0]=='C'){
			c=2;
		}else if(a[i][0]=='H'){
			c=3;
		}else if(a[i][0]=='S'){
			c=4;
		}
		for(int j=0;j<13;j++){
			if(a[i][1]==d[j]){
				b[j*4+c]=1;
			}
		}
	}
	for(int i=0;i<53;i++){
		if(b[i]==1){
			jie--;
		}
	}
	cout<<jie;
	fclose(stdin);
	fclose(stdout);
	
	
	return 0;
}
