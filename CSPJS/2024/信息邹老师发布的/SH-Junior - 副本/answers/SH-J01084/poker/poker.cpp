#include<bits/stdc++.h>
using namespace std;

set<string> mp;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	 
	int n;cin>>n;
	for(int i=0;i<n;i++){
		string st;cin>>st;
		mp.insert(st);
	}
	cout<<52-mp.size()<<endl;
	
	fclose(stdin);
	fclose(stdout);
} 


