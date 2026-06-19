#include<bits/stdc++.h>
using namespace std;
int n,q;
int ans[200020];
string s[2][200020];
string t[2][200020];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int ix=0;ix<n;ix++)cin>>s[0][ix]>>s[1][ix];//Ð³Òô×Ö¶Î 
	for(int ix=0;ix<q;ix++)cin>>t[0][ix]>>t[1][ix];//±»Ìæ»»
	for(int i=0;i<q;i++){
		string s00=t[0][i],s11=t[1][i];
		for(int j=0;j<n;j++){
			string s0 = s[0][j], s1 = s[1][j];
			//cout<<s00<<"ÖÐ"<<s0<<':'<<s00.find(s0)<<'\n';
			
			//¼ì²âÏàµÈ 
			long long p = s00.find(s0);//Ìæ»»µã
			if(p>s00.length())continue;
			char ch;
			bool flag = true;
			for(int cp=0;cp<s00.length();cp++){
				ch = (cp>=p&&cp-p<s0.length())?s1[cp-p]:s00[cp];
				if(ch!=s11[cp]){
					flag = false;
					break;
				}
			}
			if(flag)ans[i]++;
		}
	}
	for(int ix=0;ix<q;ix++)cout<<ans[ix]<<'\n';
	return 0;
}
