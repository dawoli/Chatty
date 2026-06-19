#include<bits/stdc++.h>
using namespace std;
int n_,sum_,num_[5][14];
char poker_[53][3];
int main(){
		freopen("poker.in","r",stdin);
		freopen("poker.in","w",stdout);
	cin>>n_;
	for(int i=1;i<=n_;i++){
		cin>>poker_[i][1]>>poker_[i][2];
		if(poker_[i][1]=='D'){
			if(poker_[i][2]-'0'>=2&&poker_[i][2]-'0'<=9){
				num_[1][poker_[i][2]-'0']=1;
			}
			else if(poker_[i][2]=='A'){
				num_[1][1]=1;
			}
			else if(poker_[i][2]=='T'){
				num_[1][10]=1;
			}
			else if(poker_[i][2]=='J'){
				num_[1][11]=1;
			}
			else if(poker_[i][2]=='Q'){
				num_[1][12]=1;
			}
			else{
				num_[1][13]=1;
			}
		}
		if(poker_[i][1]=='C'){
			if(poker_[i][2]-'0'>=2&&poker_[i][2]-'0'<=9){
				num_[2][poker_[i][2]-'0']=1;
			}
			else if(poker_[i][2]=='A'){
				num_[2][1]=1;
			}
			else if(poker_[i][2]=='T'){
				num_[2][10]=1;
			}
			else if(poker_[i][2]=='J'){
				num_[2][11]=1;
			}
			else if(poker_[i][2]=='Q'){
				num_[2][12]=1;
			}
			else{
				num_[2][13]=1;
			}
		}
		if(poker_[i][1]=='H'){
			if(poker_[i][2]-'0'>=2&&poker_[i][2]-'0'<=9){
				num_[3][poker_[i][2]-'0']=1;
			}
			else if(poker_[i][2]=='A'){
				num_[3][1]=1;
			}
			else if(poker_[i][2]=='T'){
				num_[3][10]=1;
			}
			else if(poker_[i][2]=='J'){
				num_[3][11]=1;
			}
			else if(poker_[i][2]=='Q'){
				num_[3][12]=1;
			}
			else{
				num_[3][13]=1;
			}
		}
		if(poker_[i][1]=='S'){
			if(poker_[i][2]-'0'>=2&&poker_[i][2]-'0'<=9){
				num_[4][poker_[i][2]-'0']=1;
			}
			else if(poker_[i][2]=='A'){
				num_[4][1]=1;
			}
			else if(poker_[i][2]=='T'){
				num_[4][10]=1;
			}
			else if(poker_[i][2]=='J'){
				num_[4][11]=1;
			}
			else if(poker_[i][2]=='Q'){
				num_[4][12]=1;
			}
			else{
				num_[4][13]=1;
			}
		}
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(num_[i][j]==0){
				sum_++;
			}
		}
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			cout<<num_[i][j];
		}
		cout<<endl;
	}
	cout<<sum_;
	return 0;
}
