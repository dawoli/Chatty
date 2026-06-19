#include<bits/stdc++.h>
using namespace std;
string xg[200001][3];
long long fin=18446744073709551615;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string s1,s2;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>xg[i][1]>>xg[i][2];
	while(q--){
		int f=1,f1=0,st=0,ans=0;
		string ts1="",ts2="";
		cin>>s1>>s2;
		if(s1.size()!=s2.size())cout<<0<<endl;
		else {
			for(int i=0;i<s1.size();i++){
				if(s1[i]!=s2[i]){
					ts1=ts1+s1[i],ts2=ts2+s2[i];
					if(f1==0)f1=1,st=i;
				}
				else if(s1[i]==s2[i]&&f1==1)break;
			}
			for(int i=st+ts1.size();i<s1.size();i++){
				if(s1[i]!=s2[i]){
					f=0;
					break;
				}
			}
			if(f==0){
				cout<<0<<endl;
				continue;
			}
			for(int i=1;i<=n;i++){
				if(xg[i][1]==ts1&&xg[i][2]==ts2)ans++;
				else if(xg[i][1].find(ts1)<xg[i][1].size()&&xg[i][2].find(ts2)<xg[i][2].size()&&s1.find(xg[i][1])<s1.size()&&s2.find(xg[i][2])<s2.size()){
					ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
}
