#include<bits/stdc++.h>
using namespace std;
int a[5][100];
char s;
int sum=0,t,n;
int main(){
	ifstream fin("poker.in");
	ofstream fout("poker.out");
	for(int i=0;i<=5;i++){
		for(int j=0;j<=100;j++){
			a[i][j]=0;
		}
	}
	fin>>n;
	for(int i=1;i<=n;i++){
		fin>>s;
		if(s=='D'){
			t=1;
		}
		if(s=='C'){
			t=2;
		}
		if(s=='H'){
			t=3;
		}
		if(s=='S'){
			t=4;
		}
		fin>>s;
		if(a[t][s-'0']==0){
			sum++;
			a[t][s-'0']=1;
		}
	}
	fout<<52-sum<<endl;
	fin.close();
	fout.close();
	return 0;
}
