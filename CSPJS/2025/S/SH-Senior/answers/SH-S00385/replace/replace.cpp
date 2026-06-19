#include<bits/stdc++.h>
using namespace std;
const int BASE=131;
int n,q,l[200009],fir[200009],k;
string s[200009],t[200009];
unsigned long long h1[200009],h2[200009],p[5000009]={1};//表示字符串对的哈希值
unsigned long long hs1[5000009],hs2[5000009];//表示q前缀哈希值 

unsigned long long query(unsigned long long* h,int l,int r){
//	cout<<"hash"<<' '<<l<<' '<<r<<endl;
//	cout<<h[l-1]<<' '<<h[r]<<endl;
//	cout<<h[r]-h[l-1]*p[r-l+1]<<endl;
	return h[r]-h[l-1]*p[r-l+1];
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=5000009;i++) p[i]=p[i-1]*BASE;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
		l[i]=s[i].size();
		fir[i]=2e9;
		for(int j=0;j<l[i];j++){
			if(s[i][j]!=t[i][j]){fir[i]=j;break;}
		}
//		cout<<i<<' '<<fir[i]<<endl;
		for(int j=0;j<l[i];j++){
			h1[i]=h1[i]*BASE+s[i][j];
			h2[i]=h2[i]*BASE+t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<endl;
			continue;
		}
		int len=s1.size();
		for(int j=0;j<len;j++){
			if(s1[j]!=s2[j]){k=j;break;}
		}
		for(int j=0;j<len;j++){
			hs1[j+1]=hs1[j]*BASE+s1[j];
			hs2[j+1]=hs2[j]*BASE+s2[j];
		}
		int ans=0;
		for(int j=1;j<=n;j++){
//			cout<<j<<endl;
			if(fir[j]==2e9) continue;
			int st=k-fir[j]+1;
			
			if(st<=0||st+l[j]-1>len) continue;
//			cout<<j<<' '<<st<<' '<<st+l[j]-1<<endl;
			if(query(hs1,st,st+l[j]-1)==h1[j]&&query(hs2,st,st+l[j]-1)==h2[j]&&query(hs1,st+l[j],len)==query(hs2,st+l[j],len)) ans++;
//			cout<<query(hs1,st,st+l[j]-1)<<' '<<h1[j]<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
