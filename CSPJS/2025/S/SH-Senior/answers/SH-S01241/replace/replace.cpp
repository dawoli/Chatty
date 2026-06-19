#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
string s1[N],s2[N];
int n,Q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(Q--){
		string s0,st;
		cin>>s0>>st;
		int len1=s0.length(),len2=st.length();
		if(len1!=len2){
			cout<<0<<'\n';
			continue;
		}
		int cnt=0;
		for(int x=1;x<=n;x++){
			for(int i=0;i<=s0.length()-s1[x].length();i++){
				bool f=1;
				for(int j=0;j<s1[x].length();j++){
					if(s1[x][j]!=s0[i+j]||s2[x][j]!=st[i+j]){
						f=0;break;
					}
				}
				for(int j=i+s1[x].length();j<s0.length();j++){
					//cout<<x<<' '<<s0[j]<<' '<<st[j]<<'\n';
					if(s0[j]!=st[j]){
						f=0;break;
					}
				}
				cnt+=f;
				if(s0[i]!=st[i])break;
			}
		}
		cout<<cnt<<'\n';
	}
}
