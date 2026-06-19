#include<bits/stdc++.h>
#define q1 1451
#define p1 999853
#define p2 470299
#define q2 995699
#define N 200010
#define M 11000010
using namespace std;

int n,q;
int Hash1[M],Hash2[M],cnt,pow1[M],pow2[M];
struct Hash{
	int l,r;
	
	void init_hash(string s){
		l = cnt;
		Hash1[l] = Hash2[l] = 0;
		int c;
		for(int i = 1;i <= s.size();i++){
			c = s[i-1]-'a';
			Hash1[l+i] = Hash1[l+i-1]*q1%p1+c;
			Hash1[l+i] %= p1;
			Hash2[l+i] = Hash2[l+i-1]*q2%p2+c;
			Hash2[l+i] %= p2;
		}
		cnt = l+s.size()+3;
	}
	
	pair<int,int> get_hash(int x,int y){
		int a = (Hash1[l+y+1]-Hash1[l+x]*pow1[y-x+1]%p1+p1)%p1;
		int b = (Hash2[l+y+1]-Hash2[l+x]*pow2[y-x+1]%p2+p2)%p2;
		return {a,b};
	}
	
}s1[N],s2[N],t1,t2;
bool operator==(pair<int,int> x,pair<int,int> y){
	return x.first==y.first&&x.second==y.second;
}
bool operator!=(pair<int,int> x,pair<int,int> y){
	return x.first!=y.first||x.second!=y.second;
}
int posl[N],posr[N],le[N];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pow1[0] = pow2[0] = 1;
	for(int i = 1;i <= 5000010;i++){
		pow1[i] = pow1[i-1]*q1%p1;
		pow2[i] = pow2[i-1]*q2%p2;
	}
	cin>>n>>q;
	cnt = 1;
	for(int i = 1;i <= n;i++){
		string sx,sy;
		cin>>sx>>sy;
		s1[i].init_hash(sx);
		s2[i].init_hash(sy);
		int k = sx.size();
		posl[i] = -1;
		for(int j = 0;j < k;j++){
			if(s1[i].get_hash(0,j)!=s2[i].get_hash(0,j)){
				posl[i] = j;
				break;
			}
		}
		if(posl[i]==-1) posr[i] = -1;
		else{
			for(int j = k-1;j >= 0;j--){
				if(s1[i].get_hash(j,k-1)!=s2[i].get_hash(j,k-1)){
					posr[i] = j;
					break;
				}
			} 
		}
		posr[i]--;
		le[i] = k;
	}
	int cntk = cnt;
	while(q--){
		string ta,tb;
		cin>>ta>>tb;
		cnt = cntk;
		int k = ta.size();
		if(k!=tb.size()){
			cout<<0<<'\n';
			continue;
		}
		t1.init_hash(ta);t2.init_hash(tb);
		int l=0,r=0;
		for(int i = 0;i < k;i++){
			if(t1.get_hash(0,i)!=t2.get_hash(0,i)){
				l = i;
				break;
			}
		}
		for(int i = k-1;i >= 0;i++){
			if(t1.get_hash(i,k-1)!=t2.get_hash(i,k-1)){
				r = i;
				break;
			}
		}
		r--;

		int ans = 0;
		for(int i = 1;i <= n;i++){
			if(posl[i]==-1) continue;
			if(posr[i]-posl[i]+1==r-l+1){
				int rpos = r-posr[i]+le[i];
				int lpos = l-posl[i]+0;
				if(t1.get_hash(lpos,rpos)!=s1[i].get_hash(0,le[i])) continue;
				if(t2.get_hash(lpos,rpos)!=s2[i].get_hash(0,le[i])) continue;
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
