#include<bits/stdc++.h>
std::ifstream fin("replace.in");
std::ofstream fout("replace.out");
using ll=long long;
const int maxn=2e5+10;
const ll mod1=1e9+7,mod2=998244353;
int n,q,l[maxn],r[maxn];
ll has1[maxn],has2[maxn];
std::string q1,q2,s1[maxn],s2[maxn];
ll fpow(ll x,ll a,ll mod){
	if(x==1||a==0) return 1;
	if(x==0||a==1) return x;
	ll res=fpow(x,a/2,mod);
	res*=res;
	res%=mod;
	if(a%2) res*=x;
	return res%mod;
}
void solve1(){
	for(int i=1;i<=n;++i){
		fin>>s1[i]>>s2[i];
		int sz=s1[i].size(),j;
		for(j=0;j<sz;++j){
			if(s1[i][j]!=s2[i][j]){
				l[i]=j;
				break;
			}
		}
		if(j==sz){
			--n,--i;
			//fout<<n<<std::endl
			continue;
		}
		for(j=sz-1;j>0;--j){
			if(s1[i][j]!=s2[i][j]){
				r[i]=j;
				break;
			}
		}
		for(j=0;j<sz;++j){
			has1[i]*=26;
			has1[i]+=s1[i][j]-'a';
			has1[i]%=mod1;
			has2[i]*=26;
			has2[i]+=s2[i][j]-'a';
			has2[i]%=mod2;
		}
		//fout<<l[i]<<' '<<r[i]<<' '<<has1[i]<<' '<<has2[i]<<std::endl;
	}
	while(q--){
		fin>>q1>>q2;
		int sz=q1.size();
		if(sz!=q2.size()){
			fout<<"0\n";
			continue;
		}
		int j,lf,ri;
		for(j=0;j<sz;++j){
			if(q1[j]!=q2[j]){
				lf=j;
				break;
			}
		}
		for(j=sz-1;j>0;--j){
			if(q1[j]!=q2[j]){
				ri=j;
				break;
			}
		}
		//fout<<lf<<' '<<ri<<' '<<sz<<'\n';
		std::vector<ll> hq1,hq2;
		for(j=0;j<sz;++j){
			hq1.push_back(0);
			if(j>0) hq1[j]=hq1[j-1]*26;
			hq1[j]+=q1[j]-'a';
			hq1[j]%=mod1;
			hq2.push_back(0);
			if(j>0) hq2[j]=hq2[j-1]*26;
			hq2[j]+=q2[j]-'a';
			hq2[j]%=mod2;
		}
		hq1.push_back(0);
		hq2.push_back(0);
		int ans=0;
		for(int i=1;i<=n;++i){
			if(r[i]-l[i]!=ri-lf||s1[i].size()-r[i]>sz-ri||l[i]>lf) continue;
			int it1=ri+s1[i].size()-r[i]-1,it2=(lf-l[i]+sz)%(sz+1);
			//if(i==2&&q==1) fout<<it1<<' '<<hq1[it1]<<' '<<hq2[it1]<<' '<<it2<<' '<<hq1[it2]<<' '<<hq2[it2];
			if(has1[i]==hq1[it1]-hq1[it2]*fpow(26,it1-it2,mod1)%mod1&&has2[i]==hq2[it1]-hq2[it2]*fpow(26,it1-it2,mod2)%mod2){
				//fout<<i<<"y\n";
				++ans;
			}
		}
		fout<<ans<<std::endl;
	}
}
void solve2(){
	for(int i=1;i<=n;++i){
		fin>>s1[i]>>s2[i];
		int sz=s1[i].size(),j;
		for(j=0;j<sz;++j){
			if(s1[i][j]!=s2[i][j]){
				l[i]=j;
				break;
			}
		}
		if(j==sz){
			--n,--i;
			//fout<<n<<std::endl
			continue;
		}
		for(j=sz-1;j>0;--j){
			if(s1[i][j]!=s2[i][j]){
				r[i]=j;
				break;
			}
		}
		for(j=0;j<sz;++j){
			has1[i]*=26;
			has1[i]+=s1[i][j]-'a';
			has1[i]%=mod1;
		}
		//fout<<l[i]<<' '<<r[i]<<' '<<has1[i]<<' '<<has2[i]<<std::endl;
	}
	while(q--){
		fin>>q1>>q2;
		int sz=q1.size();
		if(sz!=q2.size()){
			fout<<"0\n";
			continue;
		}
		int j,lf,ri;
		for(j=0;j<sz;++j){
			if(q1[j]!=q2[j]){
				lf=j;
				break;
			}
		}
		for(j=sz-1;j>0;--j){
			if(q1[j]!=q2[j]){
				ri=j;
				break;
			}
		}
		//fout<<lf<<' '<<ri<<' '<<sz<<'\n';
		std::vector<ll> hq1,hq2;
		for(j=0;j<sz;++j){
			hq1.push_back(0);
			if(j>0) hq1[j]=hq1[j-1]*26;
			hq1[j]+=q1[j]-'a';
			hq1[j]%=mod1;
		}
		hq1.push_back(0);
		int ans=0;
		for(int i=1;i<=n;++i){
			if(r[i]-l[i]!=ri-lf||s1[i].size()-r[i]>sz-ri||l[i]>lf) continue;
			int it1=ri+s1[i].size()-r[i]-1,it2=(lf-l[i]+sz)%(sz+1);
			//if(i==2&&q==1) fout<<it1<<' '<<hq1[it1]<<' '<<hq2[it1]<<' '<<it2<<' '<<hq1[it2]<<' '<<hq2[it2];
			if(has1[i]==hq1[it1]-hq1[it2]*fpow(26,it1-it2,mod1)%mod1){
				//fout<<i<<"y\n";
				++ans;
			}
		}
		fout<<ans<<std::endl;
	}
}
int main(){
	fin>>n>>q;
	if(n*q<=1.1e6l){
		solve1();
	}
	else solve2();
	return 0;
}
