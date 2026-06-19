#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=2e5+5,L=5e6+5;
int n,q,ans,len[N];
ull b=13331,p[L],s[N][2];
char st[L];
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q; p[0]=1;
	for(int i=1;i<=L;i++) p[i]=p[i-1]*b;
	for(int i=1;i<=n;i++){
	  cin>>(st+1); len[i]=strlen(st+1);
	  for(int j=1;j<=len[i];j++) s[i][0]=s[i][0]*b+(st[j]-'a');
	  cin>>(st+1);
	  for(int j=1;j<=len[i];j++) s[i][1]=s[i][1]*b+(st[j]-'a');
	}
	while(q--){
	  ull va=0,vb=0; ans=0;
	  cin>>(st+1); int ln=strlen(st+1);
	  for(int j=1;j<=ln;j++) va=va*b+(st[j]-'a');
	  cin>>(st+1);
	  for(int j=1;j<=ln;j++) vb=vb*b+(st[j]-'a');
	  for(int i=1;i<=n;i++)
		for(int j=1;j<=ln-len[i];j++)
	  	  if(va-s[i][0]*p[j]+s[i][1]*p[j]==vb) ans++;
	  cout<<ans<<endl;
	}
	return 0;
}
