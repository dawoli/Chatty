#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T,x0,y0,d0;
	cin>>T;
	for(int i=0;i<T;i++){
		if(T%i==0)cout<<1;
		else cout<<0;
	}
	return 0;
}


