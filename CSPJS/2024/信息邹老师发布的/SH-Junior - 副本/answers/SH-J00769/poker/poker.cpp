#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// DCHS,A23456789TJQK
int find(char c,string s){
	for(int i=0;i<s.size();i++) 
		if(s[i]==c) return i;
	return s.size();
}
bool ok[60];
string cl="DCHS",nm="A23456789TJQK";
int n,ans=52;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char a,b;
		cin>>a>>b;
		int index=find(a,cl)*13+find(b,nm);
		if(!ok[index]) ans--;
		ok[index]=1;
	}
	cout<<ans<<endl;
	return 0;
}

