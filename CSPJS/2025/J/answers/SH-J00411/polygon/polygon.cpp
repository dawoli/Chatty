#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,m[100009];
	cin>>a;
	for(int i=0;i<a;i++)
		cin>>m[i];
	if(a<=3&&m[2]<=2*(m[0]+m[1]))
		cout<<1;
	else
		cout<<0;
	return 0;
}
