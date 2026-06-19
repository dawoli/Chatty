#include<bits/stdc++.h>
using namespace std;
void freopen(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
}
int n,ans;
bool book[100][200];
string s;
int main(){
	freopen();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		s=' '+s;
		if(!book[s[1]-'A'][s[2]-'0']) book[s[1]-'A'][s[2]-'0']=1,ans++;
	}
	cout<<52-ans;
	return 0;
}
