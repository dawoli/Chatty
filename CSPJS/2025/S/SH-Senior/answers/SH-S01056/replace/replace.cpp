#include<bits/stdc++.h>
const int N=2e5+9;
using std::cin;
using std::cout;
using std::string;
int n,q,cnt;
string s[N][2],t[N][2];
int l[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);std::ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		l[i]=s[i][0].size();
	}
	for(int i=1,j,id;i<=q;i++){
		cnt=0;
		cin>>t[i][0]>>t[i][1];
		if(t[i][0].size()!=t[i][1].size()){cout<<"0\n";continue;}
		if(n<2e3){
			for(j=1;j<=n;j++){
				id=t[i][0].find(s[j][0]);
				if(id!=string::npos&&t[i][0].replace(id,l[j],s[j][1])==t[j][1])
					cnt++;
			}
			cout<<cnt<<'\n';
		}else{cout<<"0\n";}
	}
	return 0;
}

