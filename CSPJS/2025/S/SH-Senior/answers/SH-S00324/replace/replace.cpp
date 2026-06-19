#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=5e6+9;
const int base=13331;
int n,qr,tot,t[N][27],fail[N],cnt[N];
vector <int> vec;
unordered_map <ull,int> mp;
string _s1,_s2,_t1,_t2,tt;
void insert(int p,string s){
	for(int i=0;i<s.size();i++){
		if(!t[p][s[i]-'a']) t[p][s[i]-'a']=++tot;
		p=t[p][s[i]-'a'];
	}
	cnt[p]++;//cout<<p<<'\n';
}
queue <int> q;
void get_fail(int rt){//cout<<t[1][26]<<'\n';
	fail[rt]=rt;
	for(int i=0;i<27;i++){
		if(t[rt][i]) q.push(t[rt][i]),fail[t[rt][i]]=rt;
		else t[rt][i]=rt;
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<27;i++){
			if(t[u][i]){//if(rt==1) cout<<u<<' '<<i<<' '<<t[u][i]<<'\n';
				fail[t[u][i]]=t[fail[u]][i];//cout<<fail[u]<<'\n';
				if(!fail[t[u][i]]) fail[t[u][i]]=rt;
				cnt[t[u][i]]+=cnt[fail[t[u][i]]];
				q.push(t[u][i]);
			}
			else {
				t[u][i]=t[fail[u]][i];
				if(!t[u][i]) t[u][i]=rt;
			}
		}
	}
	//cout<<rt<<' '<<fail[4]<<'\n';
}
int ask(int rt,string s){
	int p=rt,ans=0;
	for(int i=0;i<s.size();i++){
		p=t[p][s[i]-'a'];//cout<<fail[4]<<'\n';
		//int tmp=p;
		//while(tmp!=rt) ans+=cnt[tmp],tmp=fail[tmp];//,cout<<tmp<<'\n';
		ans+=cnt[p];
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>qr;
	for(int i=1;i<=n;i++){
		cin>>_s1>>_s2;
		int m=_s1.size();
		int pos=0,pos2=0;
		for(int j=0;j<m;j++)
			if(_s1[j]!=_s2[j]){
				pos=j;
				break;
			}
		for(int j=m-1;j>=0;j--)
			if(_s1[j]!=_s2[j]){
				pos2=j;
				break;
			}
		ull h=0;
		for(int j=pos;j<=pos2;j++) h=h*base+_s1[j];
		for(int j=pos;j<=pos2;j++) h=h*base+_s2[j];//cout<<h<<'\n';
		if(!mp[h]) mp[h]=++tot,vec.push_back(tot);
		//cout<<mp[h]<<'\n';
		tt="";
		for(int j=0;j<pos;j++) tt+=_s1[j];
		tt+=(char)('a'+26);
		for(int j=pos2+1;j<m;j++) tt+=_s2[j];//cout<<tt<<'\n';
		insert(mp[h],tt);
	}
	for(int i=0;i<vec.size();i++) get_fail(vec[i]);
	while(qr--){
		cin>>_t1>>_t2;
		int m=_t1.size();
		int pos=0,pos2=0;
		for(int j=0;j<m;j++)
			if(_t1[j]!=_t2[j]){
				pos=j;
				break;
			}
		for(int j=m-1;j>=0;j--)
			if(_t1[j]!=_t2[j]){
				pos2=j;
				break;
			}
		ull h=0;
		for(int j=pos;j<=pos2;j++) h=h*base+_t1[j];
		for(int j=pos;j<=pos2;j++) h=h*base+_t2[j];
		int rt=mp[h];
		if(!rt){
			cout<<0<<'\n';
			continue;
		}
		tt="";
		for(int j=0;j<pos;j++) tt+=_t1[j];
		tt+=(char)('a'+26);
		for(int j=pos2+1;j<m;j++) tt+=_t2[j];//cout<<tt<<'\n';
		cout<<ask(rt,tt)<<'\n';
	}
	return 0;
} 
