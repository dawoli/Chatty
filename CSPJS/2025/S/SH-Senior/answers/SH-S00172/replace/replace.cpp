#include<bits/stdc++.h>
using namespace std;
const long long mod1=998244353,mod2=1000000007ll;
const long long base1=131,base2=13331;
int n,q;
string ts[200001][3],s[200001][3],t[200001][3];
int lens[5000001]={},lent[5000001]={};
long long p1[5000001]={},p2[5000001]={};
vector<pair<long long,long long> > empty;
vector<int> empty2;
vector<vector<pair<long long,long long> > > hsh_s[3];
vector<vector<pair<long long,long long> > > hsh_t[3];
int sl[200001]={},sr[200001]={},tl[200001]={},tr[200001]={};
string read(){
	string s="";
	char c=getchar();
	while(!(c>='a'&&c<='z'))c=getchar();
	while(c>='a'&&c<='z')s+=c,c=getchar();
	return s;
}
map<pair<pair<long long,long long>,pair<long long,long long> >,vector<int> > mp;
pair<long long,long long> get_hsh(char mode,int id/*1或2*/,int num/*第几个字符串*/,int l,int r){
	if(mode=='s'){
		pair<long long,long long> t1=hsh_s[id][num][r];
		pair<long long,long long> t2=hsh_s[id][num][l];
		if(l>=1)t2=hsh_t[id][num][l-1];else t2={0,0};
		long long hj=t1.first,hi=t2.first;
		long long hij=hj-hi*p1[r-l+1];
		hij%=mod1;
		hij=(hij+mod1)%mod1;
		long long hhj=t1.second,hhi=t2.second;
		long long hhij=hhj-hhi*p2[r-l+1];
		hhij%=mod2;
		hhij=(hhij+mod2)%mod2;
		return make_pair(hij,hhij);
	}else if(mode == 't'){
		pair<long long,long long> t1=hsh_t[id][num][r];
		pair<long long,long long> t2;
		if(l>=1)t2=hsh_t[id][num][l-1];else t2={0,0};
		long long hj=t1.first,hi=t2.first;
		long long hij=hj-hi*p1[r-l+1];
		hij%=mod1;
		hij=(hij+mod1)%mod1;
		long long hhj=t1.second,hhi=t2.second;
		long long hhij=hhj-hhi*p2[r-l+1];
		hhij%=mod2;
		hhij=(hhij+mod2)%mod2;
		return make_pair(hij,hhij);
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	p1[0]=1ll;p2[0]=1ll;
	for(int i=1;i<=5000000;i++){
		p1[i]=p1[i-1]*base1;p1[i]%=mod1;
		p2[i]=p2[i-1]*base2;p2[i]%=mod2;
	}
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		ts[i][1]=read();ts[i][2]=read();
	}
	int idx=0;
	for(int i=1;i<=n;i++){
		if(ts[i][1]!=ts[i][2]){
			s[++idx][1]=ts[i][1];
			s[idx][2]=ts[i][2];
		}
	}
	n=idx;
	
	for(int i=1;i<=n;i++){
		bool exec=0;
		int l=0,r=0;
		for(int j=0;j<s[i][1].length();j++){
			if(s[i][1][j]!=s[i][2][j]){
				if(!exec)l=r=j,exec=1;
				else r=j;
			}
		}
		sl[i]=l,sr[i]=r;
	}
	
	hsh_s[1].push_back(empty);
	hsh_s[2].push_back(empty);
	for(int i=1;i<=n;i++){
		lens[i]=s[i][1].length();
		hsh_s[1].push_back(empty);
		hsh_s[2].push_back(empty);
		hsh_s[1][i].push_back({(long long)s[i][1][0],(long long)s[i][1][0]});
		hsh_s[2][i].push_back({(long long)s[i][2][0],(long long)s[i][2][0]});
		for(int j=1;j<lens[i];j++){
			pair<long long,long long> tmp=hsh_s[1][i][j-1];
			long long h1=tmp.first,h2=tmp.second;
			h1=h1*base1+s[i][1][j];
			h1%=mod1;
			h2=h2*base2+s[i][1][j];
			h2%=mod2;
			hsh_s[1][i].push_back({h1,h2});
			
			tmp=hsh_s[2][i][j-1];
			h1=tmp.first,h2=tmp.second;
			h1=h1*base1+s[i][2][j];
			h1%=mod1;
			h2=h2*base2+s[i][2][j];
			h2%=mod2;
			hsh_s[2][i].push_back({h1,h2});
		}
	}
	
	for(int i=1;i<=q;i++){
		t[i][1]=read();t[i][2]=read();
		lent[i]=t[i][1].length();
	}
	
	for(int i=1;i<=q;i++){
		bool exec=0;
		int l=0,r=0;
		for(int j=0;j<t[i][1].length();j++){
			if(t[i][1][j]!=t[i][2][j]){
				if(!exec)l=r=j,exec=1;
				else r=j;
			}
		}
		tl[i]=l,tr[i]=r;
	}
	
	hsh_t[1].push_back(empty);
	hsh_t[2].push_back(empty);
	for(int i=1;i<=q;i++){
		lent[i]=t[i][1].length();
		hsh_t[1].push_back(empty);
		hsh_t[2].push_back(empty);
		hsh_t[1][i].push_back({(long long)t[i][1][0],(long long)t[i][1][0]});
		hsh_t[2][i].push_back({(long long)t[i][2][0],(long long)t[i][2][0]});
		for(int j=1;j<lens[i];j++){
			pair<long long,long long> tmp=hsh_t[1][i][j-1];
			long long h1=tmp.first,h2=tmp.second;
			h1=h1*base1+t[i][1][j];
			h1%=mod1;
			h2=h2*base2+t[i][1][j];
			h2%=mod2;
			hsh_t[1][i].push_back({h1,h2});
			
			tmp=hsh_t[2][i][j-1];
			h1=tmp.first,h2=tmp.second;
			h1=h1*base1+t[i][2][j];
			h1%=mod1;
			h2=h2*base2+t[i][2][j];
			h2%=mod2;
			hsh_t[2][i].push_back({h1,h2});
		}
	}
	for(int i=1;i<=n;i++){
		pair<long long,long long> x=get_hsh('s',1,i,sl[i],sr[i]);
		pair<long long,long long> y=get_hsh('s',2,i,sl[i],sr[i]);
		if(mp[make_pair(x,y)].empty())mp[make_pair(x,y)]=(empty2);
		mp[make_pair(x,y)].push_back(i);
	}
	for(int i=1;i<=q;i++){
		pair<long long,long long> x=get_hsh('t',1,i,tl[i],tr[i]);
		pair<long long,long long> y=get_hsh('t',2,i,tl[i],tr[i]);
		if(mp[make_pair(x,y)].empty()){
			printf("0\n");
		}else{
			int ans=0;
			vector<int> qingdan=mp[make_pair(x,y)];
			int cnt=qingdan.size(); 
			for(int _=0;_<cnt;_++){
				int maimaidx=qingdan[_];
				int L=tl[i],R=tr[i],l=sl[maimaidx],r=sr[maimaidx];
				if(L-l<0||(lent[i]-R)-(lens[maimaidx]-r)<0)continue;
				pair<long long,long long> xx=get_hsh('s',1,maimaidx,0,lens[maimaidx]-1);
				pair<long long,long long> yy=get_hsh('s',2,maimaidx,0,lens[maimaidx]-1);
				pair<long long,long long> xxx=get_hsh('t',1,i,L-l,R+(lens[maimaidx]-r-1));
				pair<long long,long long> yyy=get_hsh('t',2,i,L-l,R+(lens[maimaidx]-r-1));
				if(make_pair(xxx,yyy)==make_pair(xx,yy)){
					ans++;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
