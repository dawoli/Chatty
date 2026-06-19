#include <bits/stdc++.h>
using namespace std;
const int N=200005;
//const long long MOD1=875612;
//const long long MOD2=652443;
//long long ksm(long long p,long long q,long long M){
//	p%=M;
//	long long ans=1;
//	while(q){
//		if(q&1) ans=ans*p%M;
//		p=p*p%M;
//		q>>=1;
//	}
//	return ans;
//}
//struct Hash{
//	int l;
//	long long h1;
//	long long h2;
//};
//bool eq(Hash h1,Hash h2){
//	return (h1==H2.h1&&h2==H2.h2&&l==H2.l)
//}
//Hash mn(Hash h1,Hash h2){
//	Hash ans;
//	ans.h1=(H1.h1+MOD1-(H2.h1*ksm(26,H1.l-H2.l)%MOD1))%MOD1;
//	ans.h2=(H1.h2+MOD2-(H2.h2*ksm(26,H1.l-H2.l)%MOD2))%MOD2;
//	return ans;
//}
//Hash cal(string s){
//	Hash q;
//	q.l=s.size();
//	q.h1=q.h2=0;
//	for(int i=0;i<s.size();i++){
//		q.h1=q.h1*26+(long long)(s[i]-'a');
//		q.h1%=MOD1;
//		q.h2=q.h2*26+(long long)(s[i]-'a');
//		q.h2%=MOD2;
//	}
//	return q;
//}
int n,q;
string s[2][N],t[2][N];
int f1[2*N],f2[2*N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[0][i]>>s[1][i];
	}
	for(int i=1;i<=q;i++){
		cin>>t[0][i]>>t[1][i];
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			int res=0;
			string s1=s[0][j]+"#"+t[0][i];
			string s2=s[1][j]+"#"+s[1][i];
//			cout<<"cal "<<s1<<","<<s2<<"=";
			f1[0]=0; f2[0]=0;
			for(int k=1;k<s1.size();k++){
				f1[k]=f1[k-1];
				while(f1[k]&&s1[f1[k]]!=s1[k]) f1[k]=f1[f1[k]-1];
				if(s1[f1[k]]==s1[k]) f1[k]++;
				f2[k]=f2[k-1];
				while(f2[k]&&s2[f2[k]]!=s2[k]) f2[k]=f2[f2[k]-1];
				if(s2[f2[k]]==s2[k]) f2[k]++;
//				cout<<"  "<<k<<"->"<<f1[k]<<","<<f2[k]<<"\n";
				if(f1[k]==f2[k]&&f1[k]==s[0][j].size()){
					ans++;
					res++;
				}
			}
//			cout<<res<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}
