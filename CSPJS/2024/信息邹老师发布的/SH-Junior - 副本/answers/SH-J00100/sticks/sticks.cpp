#include <bits/stdc++.h>
using namespace std;
int biao[20] = {0,-1,1,7,4,2,6,8,10,18,22,20,28,68};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n<=13){
			cout<<biao[n]<<endl;
			continue;
		}
		int c=n%7+7;
		cout<<biao[c];
		int tmp=(n-c)/7;
		for(int i=1;i<=tmp;i++){
			cout<<8;
		}
	}
	return 0;
}
