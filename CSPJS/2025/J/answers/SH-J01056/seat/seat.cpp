#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("seat.in");
	ofstream fout("seat.out");
	int n,m;//n行数 m列数
	fin>>n>>m;
	int number=m*n;
	int N=number+5;
	int score[N]={0};
	for(int i=0;i<number;i++){
		fin>>score[i];
	}
	int a=score[0];
	sort(score,score+number);
	int s=0;
	int num=0;
	int k=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			num++;
			if(a==score[number-num]){
				if(i%2==1){
					fout<<i<<" "<<j;
					return 0;
				}
				else{
					fout<<i<<" "<<n-j+1;
					return 0;
				}
			}
		}
	}
	return 0;
}
