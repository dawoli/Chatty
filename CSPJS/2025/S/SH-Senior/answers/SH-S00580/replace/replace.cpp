#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int n,q;
string s[N][2],t[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++) cin>>t[i][0]>>t[i][1];
	for(int i=1;i<=q;i++){
		int ans=0;
		string str1=t[i][0];
		for(int j=0;j<str1.size();j++){
			for(int k=1;k<=n;k++){
				string str2=s[k][0];
				bool flag=1;
				if(j+str2.size()>str1.size()) continue;
				for(int l=j;l<j+str2.size();l++){
					if(str1[l]!=str2[l-j]) flag=0;
				}
				if(flag){
					for(int l=j;l<j+str2.size();l++){
						str1[l]=s[k][1][l-j];
					}
					if(str1==t[i][1]){
						//cout<<j<<" "<<k<<endl;
						ans++;
					} 
					str1=t[i][0];
				}
			}
		}
		cout<<ans<<endl;
	} 
	return 0;
}
