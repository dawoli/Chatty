#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,q;

const int Max_N=5e6+10;
unsigned short trie[Max_N][30][2],trie2[Max_N][30][2];
int fail[Max_N],fail2[Max_N];
int mem[Max_N],mem2[Max_N];
vector<tuple<int,int,int> >end1[Max_N],end2[Max_N];

int cnt1=1,cnt2=1;
string s1,s2;
			
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q;
	
	//build trie
	fail[1]=fail2[1]=1;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int now=1;
		for(int j=0;j<s1.size();j++){
			int tp=s1[j]-'a'+1,last=now;
			now=trie[now][tp][0]*64+trie[now][tp][1];
			if(now==0){
				trie[last][tp][0]=(++cnt1)/64;
				trie[last][tp][1]=cnt1%64;
				now=cnt1;
				end1[now].push_back(make_tuple(0,0,0));
			}
		}
		end1[now].push_back(make_tuple(s1.size(),i,1));
		
		now=1;
		for(int j=0;j<s2.size();j++){
			int tp=s2[j]-'a'+1,last=now;
			now=trie2[now][tp][0]*64+trie2[now][tp][1];
			if(now==0){
				trie2[last][tp][0]=(++cnt2)/64;
				trie2[last][tp][1]=cnt2%64;
				now=cnt2;
			}
		}
		end2[now].push_back(make_tuple(s2.size(),i,1));
	}
	//build fail
	queue<int>Q;
	Q.push(1);
	while(!Q.empty()){
		int last=Q.front();Q.pop();
		for(int i=1;i<=26;i++){
			if(trie[last][i][0]*64+trie[last][i][1]!=0){
				int now=trie[last][i][0]*64+trie[last][i][1];
				Q.push(now);
				int now_fail=fail[last];
				while(trie[now_fail][i][0]*64+trie[now_fail][i][1]==0){
					if(now_fail==1||now_fail==0)break;
					now_fail=fail[now_fail];
				}
				fail[now]=trie[now_fail][i][0]*64+trie[now_fail][i][1];
				if(fail[now]==0||fail[now]==now)fail[now]=1;
				for(auto e:end1[fail[now]]){
					end1[now].push_back(e);
				}
			}
		}
	}
	
	//build fail2
	Q.push(1);
	while(!Q.empty()){
		int last=Q.front();Q.pop();
		for(int i=1;i<=26;i++){
			if(trie2[last][i][0]*64+trie2[last][i][1]!=0){
				int now=trie2[last][i][0]*64+trie2[last][i][1];
				Q.push(now);
				int now_fail=fail2[last];
				while(trie2[now_fail][i][0]*64+trie2[now_fail][i][1]==0){
					if(now_fail==1||now_fail==0)break;
					now_fail=fail2[now_fail];
				}
				fail2[now]=trie2[now_fail][i][0]*64+trie2[now_fail][i][1];
				if(fail2[now]==0||fail2[now]==now)fail2[now]=1;
				for(auto e:end2[fail2[now]]){
					end2[now].push_back(e);
				}
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<"0\n";
			continue;
		}
		int now1=1,now2=1,fdf=-1,ans=0;
			
		for(int i=0;i<s1.size();i++){
			if(s1[i]!=s2[i]){
				ans=0;
				if(fdf==-1)fdf=i;
			}
			int tp1=s1[i]-'a'+1,tp2=s2[i]-'a'+1,last1=now1,last2=now2;
			now1=trie[now1][tp1][0]*64+trie[now1][tp1][1];
			now2=trie2[now2][tp2][0]*64+trie2[now2][tp2][1];
			if(now1==0)now1=trie[fail[last1]][tp1][0]*64+trie[fail[last1]][tp1][1];
			if(now1==0)now1=1;
			if(now2==0)now2=trie2[fail2[last2]][tp2][0]*64+trie2[fail2[last2]][tp2][1];
			if(now2==0)now2=1;
			
			//cout<<now1<<" "<<end1[now1].size()<<" "<<end2[now2].size()<<endl;
			//memset(mem,0,sizeof(mem));
			if(end1[now1].size()&&end2[now2].size()){
				for(auto e:end1[now1]){
					int siz=get<0>(e),id=get<1>(e);
					if(i-siz<=fdf&&i-siz>=-1)mem[id]=i+1;
				}
				for(auto e:end2[now2]){
					int siz=get<0>(e),id=get<1>(e);
					if(mem[id]==i+1)ans++;
				}
				for(auto e:end1[now1]){
					int siz=get<0>(e),id=get<1>(e);
					mem[id]=0;
				}
			}
		}
		cout<<ans<<endl;
	}
}
