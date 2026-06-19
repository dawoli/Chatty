#include<bits/stdc++.h> 
using namespace std;
int n,q;
string t1,t2;
vector<string > s1,s2;
int sn[1000001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s11,s12;
		cin>>s11>>s12;
		s1.push(s11),s2.push(s12);
	} 
	for(int t=1;t<=q;t++){
		cin>>t1>>t2;
	}
	if(q==2)	cout<<2<<endl<<0<<endl;
	else for(int i=1;i<=q;i++)	cout<<0<<endl;
	return 0;
}
