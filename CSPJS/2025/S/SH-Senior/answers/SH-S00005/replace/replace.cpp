#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1000000007,mod2=998244353;
int n,q;
int base[5000010];
int invbase[5000010];
string s1[200010],s2[200010];
string t1[200010],t2[200010];
int h1[200010],h2[200010];
int nowh[5000010];
set<int>havelen;
unordered_map<int,int>mp[5000010];//h1->h2
vector<pair<int,int> >dui[5000010],dui2[5000010];
vector<int>fan[5000010],fan2[5000010];
int query(int l,int r){
	return (nowh[l]-nowh[r+1]*base[r-l+1]%mod+mod)%mod;
}
int qpow(int a,int x){
	int shu=1,base=a;
	while(x){
		if(x&1){
			shu=(shu*base)%mod;
		}
		base=(base*base)%mod;
		x/=2;
	}
	return shu;
}
int inv(int shu){
	return qpow(shu,mod-2);
}
int as[5000010];
signed main(){
	freopen("replace2.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	base[0]=1;
	for(int i=1;i<=5000000;i++){
		base[i]=base[i-1]*131%mod;
		//invbase[i]=inv(base[i]);
	}
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		//cout<<s1[i].size()<<" "<<s2[i].size()<<'\n';
		for(int j=s1[i].size()-1;j>=0;j--){
			h1[i]=(h1[i]*131+s1[i][j])%mod;
			h2[i]=(h2[i]*131+s2[i][j])%mod;
			//h1[i]=(h1[i]+s1[i][j]*base[j])%mod;
			//h2[i]=(h2[i]+s2[i][j]*base[j])%mod;
		}
		//cout<<h1[i]<<" "<<h2[i]<<'\n';
		fan[s1[i].size()].push_back(h1[i]*mod+h2[i]);
		mp[s1[i].size()][h1[i]*mod+h2[i]]++;
		havelen.insert(s1[i].size());
	}	int times=0;
	for(int i=1;i<=q;i++){//cout<<i<<'\n';
		cin>>t1[i]>>t2[i];
		//cout<<t1[i]<<'\n';
		//cout<<t2[i]<<'\n';
		if(t1[i].size()!=t2[i].size()){
			continue;
		}
		int th2=0;
		for(int j=t2[i].size()-1;j>=0;j--){
			th2=(th2*131+t2[i][j])%mod;
		}
		nowh[t1[i].size()]=0;
		for(int j=t1[i].size()-1;j>=0;j--){
			nowh[j]=(nowh[j+1]*131+t1[i][j])%mod;
		}
		//cout<<nowh[0]<<"A"<<th2<<'\n';
		//cout<<query(2,3)<<"B"<<'\n';
		int ans=0;
		for(auto it=havelen.begin();it!=havelen.end();it++){
			if((*it)>t1[i].size())break;
			//cout<<"LEN"<<(*it)<<" ";
			for(int j=0;j<t1[i].size()-(*it)+1;j++){times++;
				//j~(j+(*it)-1)
				int duanh=query(j,j+(*it)-1);
				//cout<<duanh<<" ";
				int expect=(th2-nowh[0]+duanh*base[j]%mod+mod)%mod*inv(base[j])%mod;//新的修改完的这一段是这个哈希 
				//cout<<expect<<'\n';
				dui[(*it)].push_back({duanh*mod+expect,i});
			}
			//cout<<'\n';
		}
		//cout<<t1[i].size()<<'\n';
	}
	for(int i=1;i<=5000000;i++){
		sort(dui[i].begin(),dui[i].end());
		sort(fan[i].begin(),fan[i].end());
		
		int dpos=0,apos=0;
		while(dpos<dui[i].size()&&apos<fan[i].size()){
			
		}
	}
	cout<<times;
}
