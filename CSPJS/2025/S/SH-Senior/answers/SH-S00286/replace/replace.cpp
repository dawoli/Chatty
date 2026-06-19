#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][3],t[3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		int ans=0;
		cin>>t[1]>>t[2];
		int b,l=0;
		bool flag=false;
		for(int i=0;i<t[1].length();i++){
			if(t[1][i]!=t[2][i]){
				if(!flag){
					b=i;
					flag=true;
				}
				l=i-b+1;
			}
		}
		for(int i=1;i<=n;i++){
			if(s[i][1].length()<l) continue;
			int k=s[i][1].length();
			for(int j=min(b,(int)(t[1].length()-k));j>=0&&j+k<=t[1].length()&&j+k>=b+l;j--){
				if(t[1].substr(j,k)==s[i][1]&&t[2].substr(j,k)==s[i][2]){
					ans++;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
