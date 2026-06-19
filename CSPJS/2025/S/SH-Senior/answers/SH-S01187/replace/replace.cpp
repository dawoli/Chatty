#include<bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int qq=1;qq<=q;qq++){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j+s1[i].size()<=t1.size();j++){
				bool flag1=1;
				string tt=t1;
				for(int k=0;k<s1[i].size();k++){
					if(tt[j+k]!=s1[i][k]){
						flag1=0;
						break;
					}
				}
				if(flag1){
					for(int k=0;k<s1[i].size();k++){
						tt[j+k]=s2[i][k];
					}
					bool flag2=1;
					for(int k=0;k<t1.size();k++){
						if(tt[k]!=t2[k]){
							flag2=0;
							break;
						}
					}
					if(flag2)	ans++;
				}
				
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

