#include<bits/stdc++.h>
using namespace std;
int n,p[200][200];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	int sum=52;
	for(int i=1;i<=n;i++){
		char tp,num;
		cin>>tp>>num;
		if(p[tp][num]) continue;
		sum--;
		p[tp][num]=1;
	}
	cout<<sum;
	return 0;
}

