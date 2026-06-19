#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
string s1[200009],s2[200009],t1[200009],t2[200009];
bool isTypeB=1;
namespace TypeB{
	int bp1[200009],bp2[200009],ans[200009];
	void solve(){
		for(int i=1;i<=n;i++){
			for(int j=0;j<s1[i].size();j++){
				if(s1[i][j]=='b'){
					bp1[i]=j; 
				}
				if(s2[i][j]=='b'){
					bp2[i]=j; 
				}
			}
		}
		for(int i=1;i<=q;i++){
			if(t1[i].size()!=t2[i].size()){
				ans[i]=0;
				continue;
			}
			int tbp1=0,tbp2=0;
			for(int j=0;j<t1[i].size();j++){
				if(t1[i][j]=='b'){
					tbp1=j; 
				}
				if(t2[i][j]=='b'){
					tbp2=j; 
				}
			}
		}
		for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
	}
}
namespace BF{
	int ans;
	void solve(){
		for(int i=1;i<=q;i++){
//			cout<<"--"<<i<<' '<<t1[i]<<' '<<t2[i]<<'\n';
			if(t1[i].size()!=t2[i].size()){
				cout<<0<<'\n';
				continue;
			}
			ans=0;
			for(int j=1;j<=n;j++){
				int sz1=t1[i].size(),sz2=s1[j].size();
//				cout<<'+'<<t1[i].size()<<' '<<s1[j].size()<<endl;
				for(int k=0;k<=sz1-sz2;k++){
//					cout<<i<<' '<<j<<' '<<k<<' '<<t1[i]<<' '<<t1[i].substr(k,s1[j].size())<<' '<<s1[j]<<'\n';
					if(t1[i].substr(k,sz2)==s1[j]){
						string x=t1[i].substr(0,k),z=t1[i].substr(k+sz2,sz1-k-sz2);
//						cout<<"!! `"<<x<<"` `"<<s1[j]<<"` `"<<z<<"`\n";
						if(x+s2[j]+z==t2[i]) ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
}//brute force which provides AC on 2or5 test cases aka. 10or25pts
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		bool hasb1=0,hasb2=0;
		for(int j=0;j<s1[i].size();j++){
			if(s1[i][j]!='a'&&s1[i][j]!='b') isTypeB=0;
			if(s2[i][j]!='a'&&s2[i][j]!='b') isTypeB=0;
			if(s1[i][j]=='b'){
				if(hasb1) isTypeB=0;
				else hasb1=1;
			}
			if(s2[i][j]=='b'){
				if(hasb2) isTypeB=0;
				else hasb2=1;
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
		bool hasb1=0,hasb2=0;
		for(int j=0;j<t1[i].size();j++){
			if(t1[i][j]!='a'&&t1[i][j]!='b') isTypeB=0;
			if(t1[i][j]=='b'){
				if(hasb1) isTypeB=0;
				else hasb1=1;
			}
		}
		for(int j=0;j<t2[i].size();j++){
			if(t2[i][j]!='a'&&t2[i][j]!='b') isTypeB=0;
			if(t2[i][j]=='b'){
				if(hasb2) isTypeB=0;
				else hasb2=1;
			}
		}
	}
	BF::solve();
//	if(isTypeB) TypeB::solve();
	return 0;
}
