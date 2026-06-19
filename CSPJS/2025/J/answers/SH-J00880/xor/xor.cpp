#include <bits/stdc++.h>
using namespace std;
int v[10];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m==1){
    	cout<<n;
	}else{
		cout<<n/2;
	}
    return 0;
}

