#include<bits/stdc++.h>
using namespace std;
const int N=200009;
int n,q;
string s[N][3],t[N][3];

bool special(string s){
	int countB=0;
	for(int i=0;i<s.size();i++)
		if(s[i]!='a'&&s[i]!='b')return false;
		else if(s[i]=='b')countB++;
	if(countB!=1)return false;
	return true;
}
bool B(){
	for(int i=1;i<=n;i++)
		if(!(special(s[i][1])&&special(s[i][2])&&special(t[i][1])&&special(t[i][2])))
			return false;
	return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=n;i++)cin>>t[i][1]>>t[i][2];
	if(B()){
		vector<int>aBeforeBs1,aAfterBs1,aBeforeBs2,aAfterBs2,aBeforeBt1,aAfterBt1,aBeforeBt2,aAfterBt2;
		for(ll )
	}
	return 0;
}
