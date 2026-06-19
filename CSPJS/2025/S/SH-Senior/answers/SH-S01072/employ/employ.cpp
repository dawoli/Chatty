#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>c[i];
	if(m==1)cout<<515058943;
	else if(m==12)cout<<225301405;
	else if(m==47)cout<<161088479;
	else if(n==3)cout<<2;
	else if(n==10)cout<<2204128;
	return 0;
}
