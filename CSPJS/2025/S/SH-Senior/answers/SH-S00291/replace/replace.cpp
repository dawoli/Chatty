#include<bits/stdc++.h>
using namespace std;
const int N=200100;
const int M=5500010;
int n,q;
string ss1,ss2;
map<pair<string,string>,int> mp;
int idx,rt[N],cnt,li[N];
int fl[M],nx[M][27],go[M][27];
int pp[M*2];
long long f[M],g[M];
vector<string> e[N];
void pre(int pos){
	rt[pos]=++cnt;
	int cur=0;
	for(string v:e[pos]){
		cur=rt[pos];
		for(auto vv:v){
			int dire=vv-'a';
			if(!nx[cur][dire]) nx[cur][dire]=++cnt;
			cur=nx[cur][dire];
		}
		f[cur]++;
	}
	li[pos]=cnt;
	fl[rt[pos]]=rt[pos];
	int t=rt[pos];
	pp[t]=rt[pos];
	for(int i=rt[pos];i<=t;i++){
		for(int j=0;j<27;j++){
			if(nx[pp[i]][j]){
				go[pp[i]][j]=nx[pp[i]][j];
				if(pp[i]==rt[pos]) fl[nx[pp[i]][j]]=i;
				else fl[nx[pp[i]][j]]=go[fl[pp[i]]][j];
				pp[++t]=nx[pp[i]][j];
			}
			else{
				if(pp[i]==rt[pos]) go[pp[i]][j]=i;
				else go[pp[i]][j]=go[fl[pp[i]]][j];
			}
		}
	}
	for(int i=pp[rt[pos]];i<=pp[li[pos]];i++){
		f[i]+=f[fl[i]];
	}
}
void solve(int pos,string s){
	int cur=rt[pos],num=0;
	for(auto vv:s){
		int dire=vv-'a';
		cur=go[cur][dire];
		num+=f[cur];
	}
	cout<<num<<'\n';
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>ss1>>ss2;
		int l=ss1.length();
		int fi=-1,ls=-1;
		for(int i=0;i<l;i++){
			if(ss1[i]!=ss2[i]){
				fi=i;break;
			}
		}
		for(int i=l-1;i>=0;i--){
			if(ss1[i]!=ss2[i]){
				ls=i;break;
			}
		}
		if(ls==-1) continue;
		string tt1="",tt2="";
		for(int i=fi;i<=ls;i++){
			tt1+=ss1[i];
			tt2+=ss2[i];
		}
		if(!mp.count({tt1,tt2})) mp[{tt1,tt2}]=++idx;
		int pos=mp[{tt1,tt2}];
		string st1="";
		for(int i=0;i<fi;i++){
			st1+=ss1[i];
		}
		st1+=(char)('a'+26);
		for(int i=ls+1;i<l;i++){
			st1+=ss1[i];
		}
		e[pos].push_back(st1);
	}
	for(int i=1;i<=idx;i++) pre(i);
	for(int i=1;i<=q;i++){
		cin>>ss1>>ss2;
		int l=ss1.length();
		int fi=-1,ls=-1;
		for(int i=0;i<l;i++){
			if(ss1[i]!=ss2[i]){
				fi=i;break;
			}
		}
		for(int i=l-1;i>=0;i--){
			if(ss1[i]!=ss2[i]){
				ls=i;break;
			}
		}
		if(ls==-1) continue;
		string tt1="",tt2="";
		for(int i=fi;i<=ls;i++){
			tt1+=ss1[i];
			tt2+=ss2[i];
		}
		if(!mp.count({tt1,tt2})){
			cout<<0<<'\n';continue;
		}
		int pos=mp[{tt1,tt2}];
		string st1="";
		for(int i=0;i<fi;i++){
			st1+=ss1[i];
		}
		st1+=(char)('a'+26);
		for(int i=ls+1;i<l;i++){
			st1+=ss1[i];
		}
		solve(pos,st1);
	}
	cout<<flush;
	return 0;
}
