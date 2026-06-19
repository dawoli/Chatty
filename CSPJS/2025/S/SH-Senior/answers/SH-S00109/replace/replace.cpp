#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

inline bool pd(const string& s){
	bool fl=0;
	for(char c:s){
		if(c=='b'){
			if(fl) return 0;
			fl=1;
		}
		else if(c!='a'&&c!=' ') return 0;
	}
	return fl;
}

inline int finnd(const string& s){
	for(int i=1;i<(int)s.size();++i){
		if(s[i]=='b') return i;
	}
	throw "You have no egg!";
}

constexpr int get1(int i){
	return i*2-1;
}

constexpr int get2(int i){
	return i*2;
}

int n,q;
string m[400005];

int l[400005];

vector<int> fail[400005];

bool subtask=1;

void pre0(){
	for(int i=1;i<=2*n;++i){
		fail[i]={0,0};
		for(int j=2;j<=l[i];++j){
			int k=fail[i][j-1];
			while(k&&m[i][k+1]!=m[i][j]) k=fail[i][k];
			if(m[i][k+1]==m[i][j]) ++k;
			fail[i].push_back(k);
		}
	}
}

ll solve0(const string& s,const string& t){
	int le=s.size();
	vector<int> pre={0};
		
	for(int i=1;i<=le;++i){
		if(s[i]==t[i]) pre.push_back(pre[i-1]);
		else pre.push_back(pre[i-1]+1);
	}
	
	ll ans=0;
	
	for(int i=1;i<=n;++i){
		set<int> apps;
		
		int i1=get1(i),i2=get2(i);
		
		for(int j=1,k=0;j<=le;++j){
			while(k&&m[i1][k+1]!=s[j]) k=fail[i1][k];
			if(m[i1][k+1]==s[j]) ++k;
			if(k==l[i1]) apps.insert(j),k=fail[i1][k];
		}
		
		for(int j=1,k=0;j<=le;++j){
			while(k&&m[i2][k+1]!=t[j]) k=fail[i2][k];
			if(m[i2][k+1]==t[j]) ++k;
			if(k==l[i2]){
				if(apps.count(j)){
					if(pre[j]-pre[j-l[i2]]==pre[le]) ++ans;
				}
				k=fail[i2][k];
			}
		}
	}
	
	return ans;
}

map<pair<int,int>,vector<int>> mp;

void pre1(){
	for(int i=1;i<=n;++i){
		int i1=get1(i),i2=get2(i);
		
		int pre=finnd(m[i1])-1,suf=l[i1]-pre-1;
		int d=finnd(m[i2])-1-pre;
		
		mp[{d,pre}].push_back(suf);
	}
	
	for(auto p:mp){
		sort(p.second.begin(),p.second.end());
	}
}

ll solve1(const string& s,const string& t){
	int le=s.size();
	int pre=finnd(s)-1,suf=le-pre-1;
	int d=finnd(t)-1-pre;
	
	ll ans=0;
	
	for(int p=0;p<=pre;++p){
		if(!mp.count({d,p})) continue;
		auto& vec=mp[{d,p}];
		auto it=upper_bound(vec.begin(),vec.end(),suf);
		ans+=it-mp[{d,p}].begin();
	}
	
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	
	for(int i=1;i<=2*n;++i){
		cin>>m[i];
		l[i]=m[i].size();
		m[i]=" "+m[i];
		if(!pd(m[i])) subtask=0;
	}
	
	pre0();
	if(subtask) pre1();
	
	while(q--){
		string s,t;
		cin>>s>>t;
		
		if(s.size()!=t.size()){
			cout<<0<<endl;
			continue;
		}
		
		s=" "+s,t=" "+t;
		
		if(pd(s)&&pd(t)) cout<<solve1(s,t)<<endl;
		else cout<<solve0(s,t)<<endl;
	}
	
	return 0;
}
