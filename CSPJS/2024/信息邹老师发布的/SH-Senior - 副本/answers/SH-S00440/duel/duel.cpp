#include<bits/stdc++.h>
std::ifstream fin("duel.in");
std::ofstream fout("duel.out");
long long n;
int r[100005];
long long sum=0;
int main(){
	fin>>n;
	for(int i=1;i<=n;++i){
		int x;
		fin>>x;
		r[x]++;
	}
	for(int i=1;i<=100000;++i){
		if(sum<=r[i]){
			sum=r[i];
		}
		else{
			sum=(sum-r[i])+r[i];
		}
	}
	fout<<sum;
}

