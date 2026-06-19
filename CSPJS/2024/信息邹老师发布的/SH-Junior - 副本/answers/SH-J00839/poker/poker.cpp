#include<bits/stdc++.h> 
using namespace std;
map<string,int> m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	string s; 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		m[s]=1;
	}
	int a=m.size();
	cout<<52-a;
	return 0;
}
