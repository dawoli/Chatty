#include<bits/stdc++.h>
using namespace std;
string s1[200005];
string s2[200005];
string differs1[200005];
string differs2[200005];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
//		for(int j=0;j<s1[i].size();j++){
//			if(s1[i][j]!=s2[i][j]){
//				differs1[i]+=s1[i][j];
//				differs2[i]+=s2[i][j];
//			}
//		}
	}
	while(q--){
		string a,b;
		cin>>a>>b;
//		string differa,differb;
		int cnt=0;
		bool Is=false;
		int ans=0;
		for(int i=1;i<=n;i++){
			string tempa=a,tempb=b;
			bool Is=false;
			bool IS=false;
			while(tempa.find(s1[i])!=-1&&tempb.find(s2[i])!=-1){
				int posa=tempa.find(s1[i]),posb=tempb.find(s2[i]);
				if(posa==posb){
					if(Is==true)IS=true;
					Is=true;
					tempa[posa]='-';
					tempb[posb]='-';
				}
				else if(posb<posa){
					tempb[posb]='-';
				}
				else if(posa<posb){
					tempa[posa]='-';
				}
			}
			if(Is==true&&IS==false)ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
