#include<bits/stdc++.h>
std::ifstream fin("replace.in");
std::ofstream fout("replace.out");
using pair=std::pair<long long,long long>;
const int mod=998244353;
const int mod2=1e9+7;
int n,q;
int L1,L2;
std::string s[200005][2],t[200005][2];
long long hashe[200005][2],hashe2[200005][2];
long long hasht[2003][2003][2],hasht2[2003][2003][2];
long long poww29[5000005],poww31[5000005];
int limitl[200005],limitr[200005];
bool flag[200005];
std::map<pair,int> mp;
pair HASHt(int i,int l,int r){
	long long H129=(hasht[i][r][0]-hasht[i][l-1][0]*poww29[r-l+1]%mod+mod)%mod;
	long long H131=(hasht2[i][r][0]-hasht2[i][l-1][0]*poww31[r-l+1]%mod2+mod2)%mod2;
	long long H1=H129*1024+H131;
	long long H229=(hasht[i][r][1]-hasht[i][l-1][1]*poww29[r-l+1]%mod+mod)%mod;
	long long H231=(hasht2[i][r][1]-hasht2[i][l-1][1]*poww31[r-l+1]%mod2+mod2)%mod2;
	long long H2=H229*1024+H231;
	return {H1,H2};
} 
int tot;

void solve_easy(){
	poww29[0]=poww31[0]=1;
	for(int i=1;i<=std::max(L1,L2);i++){
		poww29[i]=poww29[i-1]*29%mod;
		poww31[i]=poww31[i-1]*31%mod2;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<s[i][0].size();j++){
			int now=s[i][0][j]-'a';
			now++;
			hashe[i][0]=(hashe[i][0]*29+now)%mod;
			hashe2[i][0]=(hashe2[i][0]*31+now)%mod2;
		}
		for(int j=0;j<s[i][1].size();j++){
			int now=s[i][1][j]-'a'; now++;
			hashe[i][1]=(hashe[i][1]*29+now)%mod;
			hashe2[i][1]=(hashe2[i][1]*31+now)%mod2;
		}
	//	std::cout<<hashe[i][0]<<" "<<hashe[i][1]<<" "<<hashe2[i][0]<<" "<<hashe2[i][1]<<"\n";
		long long H1=hashe[i][0]*1024+hashe2[i][0];
		long long H2=hashe[i][1]*1024+hashe2[i][1];
		mp[{H1,H2}]++;
	//	std::cout<<H1<<" "<<H2<<"\n";
	}
	for(int i=1;i<=q;i++){
		for(int j=0;j<t[i][0].size();j++){
			int now=t[i][0][j]-'a';now++;
			hasht[i][j+1][0]=(hasht[i][j][0]*29+now)%mod;
			hasht2[i][j+1][0]=(hasht2[i][j][0]*31+now)%mod2;
		//	std::cout<<(hasht[i][j+1][0]-hasht[i][j][0]*poww29[1]%mod+mod)%mod<<"\n";
		}
		for(int j=0;j<t[i][1].size();j++){
			int now=t[i][1][j]-'a';now++;
			hasht[i][j+1][1]=(hasht[i][j][1]*29+now)%mod;
			hasht2[i][j+1][1]=(hasht2[i][j][1]*31+now)%mod2;
		}
		for(int j=0;j<t[i][0].size();j++){
			if(t[i][0][j]!=t[i][1][j]){
				limitl[i]=j;
				flag[i]=true;
				break;
			}
		}
		for(int j=t[i][0].size()-1;j>=0;j--){
			if(t[i][0][j]!=t[i][1][j]){
				limitr[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		for(int j=0;j<t[i][0].size();j++){
			for(int k=j;k<t[i][0].size();k++){
				if(flag[i] and (j>limitl[i] or k<limitr[i])){
					continue;
				}
				pair now=HASHt(i,j+1,k+1);
			//	std::cout<<i<<" "<<j+1<<" "<<k+1<<" "<<now.first<<" "<<now.second<<"\n"; 
				ans+=mp[now];
			}
		}
		fout<<ans<<"\n";
	}
}
std::map<int,int> mpb;
struct node{
	int left,right,id,tp;
	bool operator < (const node x) const{
		return left<x.left or (left==x.left and tp>x.tp);
	}
};
std::vector<node> have[200005];
int ans[200005];
int x[800005],totnum,cntnum;
int lowbit(int x){
	return x&(-x);
}
int tree[800005];
void update(int x,int k){
	for(int i=x;i<=totnum;i+=lowbit(i)){
		tree[i]+=k;
	}
}
int query(int x){
	int res=0;
	for(int i=x;i;i-=lowbit(i)){
		res+=tree[i];
	}
	return res;
}
void solveb(){
	
	for(int i=1;i<=q;i++){
		int pos0,pos1,left,right;
		for(int j=0;j<t[i][0].size();j++){
			if(t[i][0][j]=='b'){
				pos0=j; left=j; right=t[i][0].size()-j-1; break;
			}
		}
		for(int j=0;j<t[i][1].size();j++){
			if(t[i][1][j]=='b'){
				pos1=j; break;
			}
		}
		if(!mpb.count(pos0-pos1)){
			mpb[pos0-pos1]=++tot;
		}
		have[mpb[pos0-pos1]].push_back({left,right,i,0});	
	}
	
	for(int i=1;i<=n;i++){
		int pos0,pos1,left,right;
		for(int j=0;j<s[i][0].size();j++){
			if(s[i][0][j]=='b'){
				pos0=j; left=j; right=s[i][0].size()-j-1; break;
			}
		}
		for(int j=0;j<s[i][1].size();j++){
			if(s[i][1][j]=='b'){
				pos1=j; break;
			}
		}
		if(!mpb.count(pos0-pos1)){
			mpb[pos0-pos1]=++tot;
		}
	//	std::cout<<left<<" "<<right<<" "<<pos0-pos1<<" "<<;
		have[mpb[pos0-pos1]].push_back({left,right,i,1});	
	}
	for(int i=1;i<=tot;i++){
		std::sort(have[i].begin(),have[i].end());
	//	std::cout<<i<<"\n\n";
		cntnum=0;
		for(int j=0;j<have[i].size();j++){
			x[++cntnum]=have[i][j].right;
		}
		std::sort(x+1,x+1+cntnum);
		totnum=std::unique(x+1,x+1+cntnum)-x-1;
		for(int j=1;j<=totnum;j++) tree[j]=0;
		for(int j=0;j<have[i].size();j++){
			auto xx=have[i][j];
			int l=xx.left,r=xx.right,id=xx.id,tp=xx.tp;
	//		std::cout<<l<<" "<<r<<" "<<id<<" "<<tp<<"\n";
			r=std::lower_bound(x+1,x+1+totnum,r)-x;
			if(tp==0){
				ans[id]=query(r);
			}
			else{
				update(r,1);
			}
		}
	}

	for(int i=1;i<=q;i++){
		fout<<ans[i]<<"\n";
	}
}
signed main(){
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	fin>>n>>q;
	
	for(int i=1;i<=n;i++){
		fin>>s[i][0]>>s[i][1];
		L1+=s[i][0].size()+s[i][1].size();
	}
	for(int i=1;i<=q;i++){
		fin>>t[i][0]>>t[i][1];
		L2+=t[i][0].size()+t[i][1].size();
	}
	if(L1<=2000 and L2<=2000){
		solve_easy();return 0;
	}
	bool flagb=true;
	for(int i=1;i<=n;i++){
		int ccnt=0;
		for(char x:s[i][0]){
			if(x=='b') ccnt++;
			else if(x!='a') flagb=false;
		}
		if(ccnt!=1) flagb=false;
		ccnt=0;
		for(char x:s[i][1]){
			if(x=='b') ccnt++;
			else if(x!='a') flagb=false;
		}
		if(ccnt!=1) flagb=false;
	}
	for(int i=1;i<=q;i++){
		int ccnt=0;
		for(char x:t[i][0]){
			if(x=='b') ccnt++;
			else if(x!='a') flagb=false;
		}
		if(ccnt!=1) flagb=false;
		ccnt=0;
		for(char x:t[i][1]){
			if(x=='b') ccnt++;
			else if(x!='a') flagb=false;
		}
		if(ccnt!=1) flagb=false;
	}
	if(flagb){
		solveb();
		return 0;
	}
} 
/*
5 4
aaaab baaaa
ab ba
b b
aaaab aaaab
aabaa abaaa
ab ba
aabaa aabaa
aaaaab abaaaa
aab aba
*/
