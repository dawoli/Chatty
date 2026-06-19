#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,ans;
string tou[N],wei[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>tou[i]>>wei[i];
	for(int i=1;i<=q;i++){
		string s1,s2;ans=0;
		cin>>s1>>s2;
		for(int i=1;i<=n;i++)
			if(tou[i]==s1&&wei[i]==s2){
				ans++;
				break;
			}
		string s3,s4;
		int len=s1.size();bool f=0;
		for(int i=0;i<len;i++){
			if(s1[i]==s2[i]){
				s3+=s1[i];
				s4+=s2[i];
			}
			else {
				s3="";s4="";
				while(s1[i]!=s2[i]){
					s3+=s1[i];
					s4+=s2[i];
					i++;
				}
				for(int j=1;j<=n;j++)
					if(tou[j]==s3&&wei[j]==s4){
						ans++;
						break;
					}
				break;
			}
		}
		cout<<ans<<endl;
	 }
	return 0;
} 
