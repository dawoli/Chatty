#include<bits/stdc++.h>
using namespace std;
int n,ans;
string tmp;
set<string> s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>tmp;
		s.insert(tmp);
	}
	set<string>::iterator it;
	for(it=s.begin();it!=s.end();it++)
		ans++;
	cout<<52-ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
