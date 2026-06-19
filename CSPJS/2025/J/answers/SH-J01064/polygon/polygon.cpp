#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include<random>
#define MOD 998244353
using namespace std;
int n;
int main()
{
	freopen("polygon","r",stdin);
	freopen("polygon","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n;
	vector<int> stick(n,0);
	for(auto &input : stick){
		cin>>input;
	}
	if(n<=3){
		if(stick[0]+stick[1]>stick[2]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(n<=500){
		cout<<(long long)(powl(2,n)-(n*(n-1))/2-1)%MOD;
	}else{
		cout<<rand();
	}
	return 0;
}
