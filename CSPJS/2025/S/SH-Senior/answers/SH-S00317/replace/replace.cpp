#include<bits/stdc++.h>
using namespace std;
int n,q,ls[200005],ans;
vector<int> nxt[200005];
string s[200005][2],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		ls[i]=s[i][0].size();
		s[i][0]=" "+s[i][0];
		nxt[i].push_back(0);
		nxt[i].push_back(0);
		for(int k=2,l=0;k<=ls[i];k++){
			while(l&&s[i][0][l+1]!=s[i][0][k])l=nxt[i][l];
			if(s[i][0][l+1]==s[i][0][k])l++;
			nxt[i].push_back(l);
		}
	}
	while(q--){
		cin>>t1>>t2;
		if(t1.length()!=t2.length())cout<<0<<'\n';
		int lt1=t1.size();
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1,k=0;j<=lt1;j++){
				while(k&&t1[j]!=s[i][0][k+1])k=nxt[i][k];
				if(t1[j]==s[i][0][k+1])k++;
				if(k==ls[i]){
					int be=j-k+1;
					if((be==1||t1.substr(1,be-1)==t2.substr(1,be-1))&&(j==lt1||t1.substr(j+1,lt1-j)==t2.substr(j+1,lt1-j))&&t2.substr(be,k)==s[i][1]){
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
