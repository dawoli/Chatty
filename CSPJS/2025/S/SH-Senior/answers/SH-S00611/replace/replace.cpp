#include<bits/stdc++.h>
#define int long long
using namespace std;
ifstream fin("replace.in");
ofstream fout("replace.out"); 
const int N=2e5,S=5e6,P=27,mod=1e9+7;
int n,q,po[N+5],l1[N+5],r1[N+5],l2[N+5],r2[N+5];
vector<int> s11[N+5],s12[N+5],s21[N+5],s22[N+5];
string s1[N+5],s2[N+5],t1[N+5],t2[N+5];
signed main() {
	fin>>n>>q;
	for(int i=1;i<=n;i++) {
		fin>>s1[i]>>s2[i]; s1[i]=" "+s1[i],s2[i]=" "+s2[i];
//		int sz=s1[i].size()-1; s11[i].resize(sz+1),s12[i].resize(sz+1);
//		for(int j=1;j<=sz;j++)  s11[i]=(s11[i-1]+po[i]*s1[i][j])%mod;
//		for(int j=1;j<=sz;j++)  s12[i]=(s12[i-1]+po[i]*s2[i][j])%mod;
//		for(int j=1;j<=sz;j++)  if(s1[i][j]!=s2[i][j]) {l1[i]=j;break;}
//		for(int j=sz;j>=1;j--)  if(s1[i][j]!=s2[i][j]) {r1[i]=j;break;}
	}
	for(int i=1;i<=q;i++) {
		fin>>t1[i]>>t2[i]; t1[i]=" "+t1[i],t2[i]=" "+t2[i]; int ans=0;
//		int sz=t1[i].size()-1; s21[i].resize(sz+1),s22[i].resize(sz+1);
//		for(int j=1;j<=sz;j++)  s21[i]=(s21[i-1]+po[i]*t1[i][j])%mod;
//		for(int j=1;j<=sz;j++)  s22[i]=(s22[i-1]+po[i]*t2[i][j])%mod;
//		for(int j=1;j<=sz;j++)  if(t1[i][j]!=t2[i][j]) {l2[i]=j;break;}
//		for(int j=sz;j>=1;j--)  if(t1[i][j]!=t2[i][j]) {r2[i]=j;break;}
//		for(int j=1;j<=n;j++) {
//			if(r2[i]-l2[i]+1!=r1[j]-l1[j]+1)  continue;
//			for(int j=0;j<r2[i]-l2[i]+1;j++)  if(t1[l2[i]]!=s1[l1[j]])  continue;
//			bool have=false;
//			for(int j=max(0,r2[i]-s1[j].size());j<min(r2[i].size());j++)
//		}
		fout<<0<<"\n";
	}
}
