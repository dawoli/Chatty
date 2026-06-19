#include<bits/stdc++.h>
using namespace std;
int n,sum = 0;
char pok[55][3],kin[55][3];
//pok代表poker,kin代表kind 
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>pok[i][0]>>pok[i][1];//输入 
		for(int j = 1;j <= n;j++){
			if((pok[i][0]==kin[j][0])&&(pok[i][1]==kin[j][1])){
				break;
				//这里重复了,要break 
			}
			if(j==n){
				kin[i][0] = pok[i][0];
				kin[i][1] = pok[i][1];
				sum++;
				//这里没有重复,要保存 
			}
		}
	}
	cout<<52-sum;
	//正好52张牌(不同种类) 
	
	return 0;
}
