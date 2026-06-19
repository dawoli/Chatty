#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int maxn=5e6+3;
string s[maxn][2],t1,t2;
int le[maxn][2],ri[maxn][2],cnt[33],where[maxn][2],other[maxn][2],n;
int solve(){
	int ans=0;
	string tmp=t1;
	if(tmp==t2)ans++;
	for(int i=1;i<=n;i++){
		for(int j=0;j<tmp.size();j++){
			string now="";
			for(int k=j;k<min(tmp.size(),j+s[i][0].size());k++){
				now+=tmp[k];
			}
			if(now==s[i][0]){
				string nxt="";
				for(int k=0;k<j;k++){
					nxt+=tmp[k];
				}
				nxt+=s[i][1];
				for(int k=j+s[i][0].size();k<tmp.size();k++){
					nxt+=tmp[k];
				}
				if(nxt==t2)ans++;
			}
		}
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bool can=true,tmp;
	int q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		tmp=true;
		cin>>s[i][0]>>s[i][1];
		memset(cnt,0,sizeof(cnt));
		for(int j=0;j<s[i][0].size();j++){
			cnt[s[i][0][j]]++;
		}
		for(int j=0;j<26;j++){
			if(cnt[j]==1){
				for(int k=0;k<s[i][0].size();k++){
					if(s[i][0][k]==(char)('a'+j)){
						where[i][0]=k;
						le[i][0]=k-1;
						ri[i][0]=s[i][0].size()-k-1;
						break;
					}
				}
			}else if(cnt[j]){
				other[i][0]=j;
				if(tmp)tmp=false;
				else can=false;
			}
		}
		tmp=true;
		memset(cnt,0,sizeof(cnt));
		for(int j=0;j<s[i][1].size();j++){
			cnt[s[i][1][j]]++;
		}
		for(int j=0;j<26;j++){
			if(cnt[j]==1){
				for(int k=0;k<s[i][1].size();k++){
					if(s[i][1][k]==(char)('a'+j)){
						where[i][1]=k;
						le[i][1]=k-1;
						ri[i][1]=s[i][1].size()-k-1;
						break;
					}
				}
			}else if(cnt[j]){
				other[i][1]=j;
				if(tmp)tmp=false;
				else can=false;
			}
		}
	}
	if(!can || n<=100 && q<=100){
		while(q--){
			cin>>t1>>t2;
			cout<<solve()<<"\n";
		}
		return 0;
	}
	while(q--){
		int p,l,r,ans=0,gp,gl,gr,o,go;
		cin>>t1>>t2;
		if(t1==t2){
			ans++;
		}
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<t1.size();i++){
			cnt[t1[i]]++;
		}
		for(int i=0;i<26;i++){
			if(cnt[i]==1){
				for(int j=0;j<t1.size();j++){
					if(t1[j]==(char)('a'+i)){
						p=j;
						l=j-1;
						r=t1.size()-j-1;
						break;
					}
				}
			}else if(cnt[i]){
				o=i;
			}
		}
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<t2.size();i++){
			cnt[t2[i]]++;
		}
		for(int i=0;i<26;i++){
			if(cnt[i]==1){
				for(int j=0;j<t2.size();j++){
					if(t2[j]==(char)('a'+i)){
						gp=j;
						gl=j-1;
						gr=t2.size()-j-1;
						break;
					}
				}
			}else if(cnt[i]){
				go=i;
			}
		}
		for(int i=1;i<=n;i++){
			if(t1[p]==s[i][0][where[i][0]]){
				if(other[i][1]==o && t1[p]==s[i][1][where[i][1]] || le[i][0]==l && ri[i][0]==r){
					if(p+where[i][0]-where[i][1]==gp && le[i][1]==gl && ri[i][1]==gr && s[i][1][where[i][1]]==t2[gp] && other[i][1]==go){
						ans++;
					}
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
