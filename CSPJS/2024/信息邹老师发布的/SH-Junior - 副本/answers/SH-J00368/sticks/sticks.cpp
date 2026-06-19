#include<iostream>
#include<fstream>
using namespace std;
int t,n;
int dp[100001];
int main() {
	ifstream fin("sticks.in");
	ofstream fout("sticks.out");
	dp[0]=6,dp[1]=2,dp[2]=5,dp[3]=5,dp[4]=4,dp[5]=5,dp[6]=6,dp[7]=3,dp[8]=7,dp[9]=6;
	for(int i=10; i<=100000; ++i) {
		int m=i;
		do{
			dp[i] += dp[m%10];
			m/=10;
		}while(m!=0);
	}
	fin>>t;
	while(t--) {
		fin>>n;
		int i=1;
		for(;i<=100000;++i){
			if(dp[i] == n){
				fout<<i<<endl;
				break;
			}
		}
		if(i>=100000)
			fout<<-1<<endl;
	}
}
