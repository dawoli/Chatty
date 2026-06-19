#include<bits/stdc++.h>
using namespace std;
map<string,bool> mp;
int cnt=0;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		string x;
		cin>>x;
		if(!mp[x]){
			cnt++;
			mp[x]=1;
		}
	}
	cout<<52-cnt<<endl;
	return 0;
} 
