#include <bits/stdc++.h>
using namespace std;
map<string,int> a;
string c;
int n,ans;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>c;
		if(a[c]==0){
			ans++;
			a[c]=1;
		}
	}
	cout<<52-ans;
	return 0;
} 
