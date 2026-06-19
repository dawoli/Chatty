#include<bits/stdc++.h>
using namespace std;
int test(char a){
	if(a=='A')return 1;
	else if('2'<=a&&a<='9')return a-'0';
	else if(a=='T')return 10;
	else if(a=='J')return 11;
	else if(a=='Q')return 12;
	else if(a=='K')return 13;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	bool vis[5][14]={};
	while(n--){
		char color,num;
		cin>>color>>num;
		if(color=='D'){
			int l=test(num);
			vis[1][l]=1;
		}else if(color=='C'){
			int l=test(num);
			vis[2][l]=1;
		}else if(color=='H'){
			int l=test(num);
			vis[3][l]=1;
		}else if(color=='S'){
			int l=test(num);
			vis[4][l]=1;
		}
	}
	int k=0;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(!vis[i][j])k++;
		}
	}
	cout<<k;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
