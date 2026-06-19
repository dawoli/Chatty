#include<bits/stdc++.h>
 using namespace std;
 const int N=1005;
 int n,q,cnt;
 string s[N],s2[N];
 string t[N],t2[N];
 string subs(string s,int st,int ed){
 	string ans="";
	if(ed<st) return ans;
 	for(int i=st;i<=ed;i++)
 		ans+=s[i];
 	return ans;
 }
 int main(){//10pts
 	freopen("replace.in","r",stdin);
 	freopen("replace.out","w",stdout);
 	cin>>n>>q;
 	for(int i=1;i<=n;i++){
 		cin>>s[i]>>s2[i];
	 }
 	for(int i=1;i<=q;i++){
 		cin>>t[i]>>t2[i];
	 }
 	for(int i=1;i<=q;i++){//t
 	 	for(int j=1;j<=n;j++){//s
 	 		int l=s[j].length();
 		 	for(int k=0;k+l<=t[i].length();k++){
 		 		string rep=subs(t[i],k,k+s[j].length()-1);
 			//	cout<<rep<<endl;
				if(rep==s[j]){
					string ans="";
					ans+=subs(t[i],0,k-1);
					ans+=s2[j];
					ans+=subs(t[i],k+s[j].length(),t[i].length()-1);
					//cout<<ans<<endl;
					if(ans==t2[i]){
						cnt++;
						break;
					}
				}
	 		}
		}cout<<cnt<<endl;	
		cnt=0;
	 }
	
	return 0;
 }
