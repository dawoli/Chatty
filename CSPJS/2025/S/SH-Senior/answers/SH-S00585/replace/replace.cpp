#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct str{
	int af=0,b=0,ab=0;
};
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s[N][2];
	str st[N][2];
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		bool flag=true;
		for(int j=0;j<s[i][0].size();j++){
			if(s[i][j]=='b'){
				st[i][0].b=j;
				flag=false;
			}
			else if(flag){
				st[i][0].af++;
			}else
				st[i][0].ab++;
		}flag=true;
		for(int j=0;j<s[i][1].size();j++){
			if(s[i][j]=='b'){
				st[i][1].b=j;
				flag=false;
			}
			else if(flag){
				st[i][1].af++;
			}else
				st[i][1].ab++;
		}
	}
	for(int i=1;i<=q;i++){
		int ans=0,idx1,idx2;
		string t1,t2;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			for(int j=0;j<t1.size();j++){
				if(t1[j]=='b'){
					if()
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

