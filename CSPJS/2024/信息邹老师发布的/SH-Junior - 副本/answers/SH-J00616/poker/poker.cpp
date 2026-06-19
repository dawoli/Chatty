#include<bits/stdc++.h>
using namespace std;
int n;
map<pair<char,char>,int>M;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	char a,b;
	int flag=0;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		if(M.find(make_pair(a,b))==M.end()){
			flag++;
			M[make_pair(a,b)]=1;
		}
	}
	cout<<52-flag;
	return 0;
} 

