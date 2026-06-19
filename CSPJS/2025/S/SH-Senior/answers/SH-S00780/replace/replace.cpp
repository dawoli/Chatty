#include<bits/stdc++.h>
using namespace std;

const int Maxn=2e5,Maxn1=1e6;
int n,q,d[Maxn1+5];
string s[Maxn+5][2];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	while(q--){
		int ans=0;
		string s1,s2;
		cin>>s1>>s2;
		int len1=s1.size(),len2=s2.size();
		if(len1!=len2){
			cout<<0<<endl;
			continue;
		}
		if(n*s[n][0].size()>1e8){
			for(int i=1;i<=n;i++){
				if(s[i][0]==s[i][1]&&s1.find(s[i][0])) ans++;
			}
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(s1.find(s[i][0])){
				for(int j=0;j+s[i][0].size()<=len1;j++){
					bool flag=false;
					for(int k=j;k<j+s[i][0].size();k++){
						if(s1[k]!=s[i][0][k-j]){
							flag=true;
							break;
						}
					}
					if(!flag){
						string s3=s1;
						s3.replace(j,s[i][0].size(),s[i][1]);
						if(s3==s2) ans++;
					}
				}
			}
			if(s1==s[i][0]&&s[i][1]==s2) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
