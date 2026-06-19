#include<bits/stdc++.h>
using namespace std;
int n,ans=52;
string s;
char a,b;
map<string,int> m;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	m.clear();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		m[s]++;
		if(m[s]==1)ans--;
	}
	cout<<ans;
	return 0;
}
