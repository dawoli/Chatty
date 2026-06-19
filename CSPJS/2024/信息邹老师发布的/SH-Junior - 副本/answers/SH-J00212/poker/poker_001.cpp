#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		m[s]++;
	}
	int sum=0;
	for(auto i=m.begin();i!=m.end();i++){
		sum+=i->second;
	}
	cout<<52-sum;
	return 0;
}
