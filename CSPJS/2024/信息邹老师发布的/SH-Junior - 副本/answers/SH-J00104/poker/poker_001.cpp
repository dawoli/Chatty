#include<iostream>
#include<cstring>
using namespace std;
int n;
bool pk[10][20];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		int x,y;
		char a=str[0],b=str[1];
		if(a=='D'){
			x=0;
		}else if(a=='C'){
			x=1;
		}else if(a=='H'){
			x=2;
		}else{
			x=3;
		}
		if(b=='A'){
			y=1;
		}else if(b=='T'){
			y=10;
		}else if(b=='J'){
			y=11;
		}else if(b=='Q'){
			y=12;
		}else if(b=='K'){
			y=13;
		}else{
			y=(b-'0');
		}
		pk[x][y]=1;
	}
	int cnt=0;
	for(int i=0;i<4;i++){
		for(int j=1;j<=13;j++){
			if(pk[i][j]==0){
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
