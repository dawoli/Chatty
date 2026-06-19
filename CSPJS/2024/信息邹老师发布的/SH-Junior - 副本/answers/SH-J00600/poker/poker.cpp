#include <bits/stdc++.h>
using namespace std;
int n;
string s[100];
int cnt;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);   
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>s[i];
	for(int i=1;i<=n;++i){
		bool flag=true;
		for(int j=1;j<=i-1;++j)
			if(s[i]==s[j]){
				flag=false;
				break;
			}
		if(flag)
			++cnt;
	}
	cout<<52-cnt;
	return 0;
}
