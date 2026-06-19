#include<bits/stdc++.h>
using namespace std;
map <string,int> m;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	int re=0;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		if(m[s]==1)
		re++;
		else
		m[s]=1;
	}
	cout<<52-n+re;
	return 0;
}
