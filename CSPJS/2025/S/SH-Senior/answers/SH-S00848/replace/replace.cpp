#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,q;
string s1[MAXN],s2[MAXN],qs1[MAXN],qs2[MAXN];
void solve1(){
	for(int i=1;i<=q;i++){
		int ans=0;
		int len=qs1[i].size();
		for(int j=1;j<=n;j++){
			int size=s1[j].size();
			for(int t=0;t<len;t++)
				if(qs1[i][t]==s1[i][1]){
					bool b=1;
					for(int k=0;k<s1[j].size();k++){
						if(qs1[i][t+k]!=s1[i][k+1]){
							break;
						}
					}
					if(b==1){
						string buff=qs1[i];
						for(int x=t;x<=t+s1[j].size();x++)
							buff[x]=s2[j][x];
						if(buff==qs2[i]) ans++;
					}
				}
		}
		cout<<ans<<endl;
	}
}
void solve2(){
	for(int i=1;i<=n;i++){
		int ans=0;
		int size=qs1[i].size();
		for(int j=1;j<=q;j++){
			int lenth=s1[j].size();
			for(int k=1;k<=size;k++){
				for(int x=1;x<=lenth;k++){
					if(qs1[i][k]!=s1[j][x]){
						break;
					}
					else qs1[i][k]=s2[j][k];
				}
			}
			bool b;
			for(int k=1;k<=n;k++){
				if(qs1[i][k]==qs2[i][k])
					continue;
				else b=0;
			}
			if(b==1) ans++;
		}
		cout<<ans<<endl;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++) cin>>qs1[i]>>qs2[i];
	if(q>=100005) solve1();
	else if(q<=100005) solve2();
	else if(q<=100005){
		for(int i=1;i<=q;i++) cout<<0<<endl;
	}
	return 0;
}
