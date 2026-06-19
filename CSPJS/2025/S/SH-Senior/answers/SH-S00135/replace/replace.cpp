#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;string a,b;
string str[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>str[i][1]>>str[i][2];
	for(int i=1;i<=q;i++){
		cin>>a>>b;
		bool flag=0;
		for(int j=1;j<=n;j++)
			if(a==str[i][1]&&b==str[i][2]){flag=1;cout<<2<<endl;break;}
		if(!flag)cout<<0<<endl;
	}
	return 0;
} 
