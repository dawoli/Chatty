#include<bits/stdc++.h>
using namespace std;
void open(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
#define N 111
int n,cnt;
string s[N];
int main(){
	open("poker");
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	sort(s+1,s+1+n);
	for(int i=1;i<=n;i++)
		if(s[i]!=s[i+1])++cnt;
	cout<<52-cnt<<endl;
}
