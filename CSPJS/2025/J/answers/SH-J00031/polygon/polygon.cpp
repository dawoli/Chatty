#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin >>n;
	cin >> a >> b >> c;
	int g = max(a,max(b,c));
	if(a+b+c>2*g)puts("1");
	else puts("0");

   return 0;
}

