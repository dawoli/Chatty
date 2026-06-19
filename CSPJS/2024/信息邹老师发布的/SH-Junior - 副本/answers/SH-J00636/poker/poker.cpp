#include<bits/stdc++.h>
using namespace std;
map<char,int> col;//»¨É« 
map<char,int> num;//Êı×Ö 
bool ck[5][15];
int n;
string str;
int ans=0;
void init(){
	col['D']=1;
	col['C']=2;
	col['H']=3;
	col['S']=4;
	num['A']=1;
	num['2']=2;
	num['3']=3;
	num['4']=4;
	num['5']=5;
	num['6']=6;
	num['7']=7;
	num['8']=8;
	num['9']=9;
	num['T']=10;
	num['J']=11;
	num['Q']=12;
	num['K']=13;
	return;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>str;
		ck[col[str[0]]][num[str[1]]]=1;
//		cout<<str[0]<<" "<<str[1]<<" "<<col[str[0]]<<" "<<num[str[1]]<<endl;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(!ck[i][j])	ans++;
		}
	}
	printf("%d",ans);
	return 0;
}

