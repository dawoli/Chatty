#include <bits/stdc++.h>  //这和写个随机数生成器有什么区别啊啊，中的概率高一点罢了…… 
using namespace std;

const int MAXN=505,MOD=998244353;
int n,m,c[MAXN],s[MAXN];
char ciallo;  //  ciallo~
int acs1,acc0;  //跑特殊性质A acs1记录s中1的个数（acs1==n则为特殊性质A）， acc0记录c中0的个数（即不计入排列数的人数） 

long long unsigned int apa(long long unsigned int x){  //为特殊A写的排列数计算  
	long long unsigned int aaans=1;
	while(x){
		aaans*=x;
		x--;
	}
	return aaans;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ciallo;
		s[i]=ciallo-'0';
		if(s[i]==1) acs1++; 
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) acc0++;
	} 
	
	if(acs1==n){
		if(m<=n-acc0){  //没有这么简单…… 
			cout<<apa(m)<<"\n";
		}
		else cout<<0<<"\n";
	}
	return 0;
}
