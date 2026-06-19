#include<bits/stdc++.h>
using namespace std;

int ans;
string s;
int n;
map<string,int> m;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);	
	cin>>n; ans=52;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(!m.count(s)) m[s]=1,ans--;
	}
	cout<<ans;
	return 0;
}
