#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200009],s2[200009];
int repOk(string st,string en,string rep1,string rep2){
	string l="",mid="",r="";
	int lenR=rep1.size(),len=st.size(),ans=0,midl=len-lenR,midr=len-1;
	for(int i=midl;i<=midr;i++) mid+=st[i];
	for(int i=0;i<=midl-1;i++) l+=st[i];
	for(int i=1;i<=len-lenR+1;i++){
		string nwrep1=rep1+r,nwrep2=rep2+r;
		if(mid==nwrep1){
			string nw=l+nwrep2;
			if(nw==en) ans++;
		}
		if(i==len-lenR+1) continue;
		mid=st[midl-1]+mid;
		r=st[midr]+r;
		l.erase(midl-1);
		midl--,midr--;
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		for(int ii=1;ii<=n;ii++){
			ans+=repOk(t1,t2,s1[ii],s2[ii]);
		}
		cout<<ans<<endl; 
	}
	return 0;
}
