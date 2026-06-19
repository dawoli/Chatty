#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
const int mod=998244353;
int n,m,c[maxn],jc[maxn];string s;bool bj=true;
void solvejc(){
	jc[0]=1;
	for(int i=1;i<=n;i++){
		jc[i]=jc[i-1]*i%mod;
	}
	cout<<jc[n]%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++) cin>>c[i];
	for(int i=0;i<n;i++) if(s[i]!='1') bj=false;
	if(bj=true){
		solvejc();return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
