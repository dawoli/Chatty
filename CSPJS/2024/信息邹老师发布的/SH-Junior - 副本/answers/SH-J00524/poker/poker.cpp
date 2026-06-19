#include<bits/stdc++.h>
using namespace std;
map<string,int>m;
int n,ans=52;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		if(!m[s])
			ans--,m[s]=1;
	}
	cout<<ans;
} 
