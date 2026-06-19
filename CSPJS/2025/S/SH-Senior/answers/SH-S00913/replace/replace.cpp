#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
string s1[200005],s2[200005],t1[200005],t2[200005];
void bruce1(){
	for(int i=1;i<=q;i++){
		int ans=0;
		if(t1[i].length()!=t2[i].length()){
			cout<<0<<endl;
			continue;
		}
		for(int j=1;j<=n;j++){
			int tmp=t1[i].length();
			bool flag=true;
			int ttmp=0;
			for(int k=0;k<tmp;k++){
				if(t1[i][k]==s1[j][0]&&t2[i][k]==s2[j][0]&&s1[j].length()+k<=tmp){
					bool tag=true;
					for(int ii=0;ii<s1[j].length();ii++){
						if(t1[i][k+ii]!=s1[j][ii]||t2[i][k+ii]!=s2[j][ii]){
							tag=false;
							break;
						}
					} 
					if(tag){
						k+=s1[j].length();
						continue;
					} 
				}
				if(t1[i][k]!=t2[i][k]){
					flag=false;
					break;
				}
			}
			if(flag)
				ans++;
		}
		cout<<ans<<endl;
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
	if(n<=1000){
		bruce1();
	}
	return 0;
}

