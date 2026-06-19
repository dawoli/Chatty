#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll N=2e5+9;
const ll M=2500009;
const ull BASE=255;
ll n,q,pos_L[N],pos_R[N],ans;
ull hash1[M],val[N][4],v1,v2,b[M];
string s1[N],s2[N],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld %lld",&n,&q);
	for(ll i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		pos_L[i]=-1;
		pos_R[i]=-1;
		for(ll j=0;j<s1[i].size();j++)
			if(s1[i][j]!=s2[i][j]){
				pos_L[i]=j;
				break;
			}
		for(ll j=s1[i].size()-1;j>=0;j--)
			if(s1[i][j]!=s2[i][j]){
				pos_R[i]=j;
				break;
			}	
		val[i][0]=0;
		val[i][1]=0;
		val[i][2]=0;
		val[i][3]=0;
		for(ll j=0;j<=pos_L[i]-1;j++) val[i][0]=val[i][0]*BASE+(s1[i][j]-'a'+1);
		for(ll j=pos_L[i];j<=pos_R[i];j++){
			val[i][1]=val[i][1]*BASE+(s1[i][j]-'a'+1);
			val[i][2]=val[i][2]*BASE+(s2[i][j]-'a'+1);
		}
		for(ll j=pos_R[i]+1;j<=s1[i].size()-1;j++) val[i][3]=val[i][3]*BASE+(s1[i][j]-'a'+1);
	}
	b[0]=1;
	for(ll i=1;i<=2500000;i++) b[i]=b[i-1]*BASE;
	for(ll k=1;k<=q;k++){
		ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			printf("%lld\n",ans);
			continue;
		}
		ll pos1=0,pos2=0;
		for(ll j=0;j<t1.size();j++)
			if(t1[j]!=t2[j]){
				pos1=j;
				break;
			}
		for(ll j=t1.size()-1;j>=0;j--)
			if(t1[j]!=t2[j]){
				pos2=j;
				break;
			}
		v1=0;
		v2=0;
		for(ll j=pos1;j<=pos2;j++) v1=v1*BASE+(t1[j]-'a'+1);
		for(ll j=pos1;j<=pos2;j++) v2=v2*BASE+(t2[j]-'a'+1);
		for(ll j=1;j<=t1.size();j++) hash1[j]=hash1[j-1]*BASE+(t1[j-1]-'a'+1);
		for(ll i=1;i<=n;i++){
			if(pos_L[i]==-1) continue;
			if(pos2-pos1+1==pos_R[i]-pos_L[i]+1&&v1==val[i][1]&&v2==val[i][2]){
				if(val[i][0])
					if(!(pos1-1+1>=1&&pos1-1-pos_L[i]+1>=0&&hash1[pos1-1+1]-hash1[pos1-1-pos_L[i]+1]*b[pos_L[i]]==val[i][0])) continue;
				if(val[i][3])
					if(!(pos2+s1[i].size()-1-pos_R[i]+1>=1&&pos2+s1[i].size()-1-pos_R[i]+1<=t1.size()&&(hash1[pos2+s1[i].size()-1-pos_R[i]+1]-hash1[pos2+1]*b[s1[i].size()-1-pos_R[i]]==val[i][3]))) continue;
				ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
