#include<bits/stdc++.h>
int a[5005];
int ans;
int n;
const int NN = 998244353;
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,b,c;
	cin >> a >> b >> c;
	if(a+b>c)cout<<1;
	else cout<<0;
	return 0;
}
