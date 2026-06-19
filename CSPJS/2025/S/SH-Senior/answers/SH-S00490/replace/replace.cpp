#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		int cnt=0;
		for(int i=1;i<=n;i++){
			int pos1=a.find(s[i][0]);
			if(pos1==-1)continue;
			string t=a;
			t.replace(pos1,s[i][0].size(),s[i][1]);
			if(t==b)cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
