#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string cnt,s[200009],t[200009],S,T;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
	}
	for (int i=1;i<=q;i++){
		cin>>S>>T;
		ans=0;
		for (int j=1;j<=n;j++){
			if (S.find(s[j])>S.size()) continue;
			if (T.find(t[j])>T.size()) continue;
			cnt="";
			for (int k=0;k<S.size();k++){
				if (k==S.find(s[j])){
					cnt+=t[j];
					k+=s[j].size()-1; 
				} 
				else cnt+=S[k];
			}
			if (cnt==T) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
