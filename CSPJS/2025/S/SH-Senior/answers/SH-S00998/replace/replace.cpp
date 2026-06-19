#include<bits/stdc++.h>
using namespace std;
struct Trie{
	int son[27]={};
	int fail=0;
	int len=0;
	vector<int>endd;
}tr1[5000050],tr2[5000050];
#define son1(x,y) (tr1[(x)].son[(y)])
#define son2(x,y) (tr2[(x)].son[(y)])
#define fail1(x) (tr1[(x)].fail)
#define fail2(x) (tr2[(x)].fail)
int cnt1=0,cnt2=0,q1[5000050],q2[5000050];
bool went1[5000050],went2[5000050];
void bfs(){
	int st1=0,ed1=0,st2=0,ed2=0;
	for(int i=0;i<26;i++){
		if(son1(0,i))q1[ed1++]=son1(0,i);
		if(son2(0,i))q2[ed2++]=son2(0,i);
	}
	while(st1!=ed1){
		int u=q1[st1];
		st1++;
		for(int i=0;i<26;i++){
			if(son1(u,i)){
				fail1(son1(u,i))=son1(fail1(u),i);
				q1[ed1++]=son1(u,i);
			}
			else{
				son1(u,i)=son1(fail1(u),i);
			}
		}
	}
	while(st2!=ed2){
		int u=q2[st2];
		st2++;
		for(int i=0;i<26;i++){
			if(son2(u,i)){
				fail2(son2(u,i))=son2(fail2(u),i);
				q2[ed2++]=son2(u,i);
			}
			else{
				son2(u,i)=son2(fail2(u),i);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		int sze=s1.size();
		int cur=0;
		for(int j=0;j<sze;j++){
			if(son1(cur,s1[j]-96)){
				cur=son1(cur,s1[j]-96);
			}
			else{
				cur=son1(cur,s1[j]-96)=++cnt1;
				tr1[cnt1].len=j+1;
			}
		}
		tr1[cur].endd.push_back(i);
		sze=s2.size();
		cur=0;
		for(int j=0;j<sze;j++){
			if(son2(cur,s2[j]-96)){
				cur=son2(cur,s2[j]-96);
			}
			else{
				cur=son2(cur,s2[j]-96)=++cnt2;
				tr2[cnt2].len=j+1;
			}
		}
		tr2[cur].endd.push_back(i);
	}
	bfs();
	/*
	for(int i=0;i<=cnt2;i++){
		for(int j=1;j<=26;j++){
			cout<<son2(i,j)<<' ';
		}
		cout<<'\n';
	}
	*/
	int ans=0;
	while(q--){
		ans=0;
		string t1,t2;
		cin>>t1>>t2;
		int sze=t1.size();
		int cur1=0,cur2=0;
		int stbef=-1,edaft=0;
		for(int i=0;i<sze;i++){
			if(t1[i]!=t2[i])stbef=stbef==-1?i:stbef,edaft=max(edaft,i);
		}
		for(int i=0;i<sze;i++){
			cur1=son1(cur1,t1[i]-96);
			cur2=son2(cur2,t2[i]-96);
			//cout<<i-tr2[cur2].len<<' '<<edaft<<' '<<stbef<<'\n';
			if(i>=edaft&&i-tr1[cur1].len<stbef&&i-tr2[cur2].len<stbef){
				vector<int>get1,get2;
				get1.clear(),get2.clear();
				int tmp1=cur1,tmp2=cur2;
				while(tmp1){
					int szze=tr1[tmp1].endd.size();
					for(int j=0;j<szze;j++){
						get1.push_back(tr1[tmp1].endd[j]);
						//cout<<"pushed1 "<<tr1[tmp1].endd[j]<<'\n';
					}
					szze=tr2[tmp2].endd.size();
					for(int j=0;j<szze;j++){
						get2.push_back(tr2[tmp2].endd[j]);
						//cout<<"pushed2 "<<tr2[tmp2].endd[j]<<'\n';
					}
					tmp1=fail1(tmp1),tmp2=fail2(tmp2);
					if(i-tr1[tmp1].len>=stbef)break;
					if(i-tr2[tmp2].len>=stbef)break;
				}
				sort(get1.begin(),get1.end());
				int szz=get2.size();
				for(int j=0;j<szz;j++){
					vector<int>::iterator it=lower_bound(get1.begin(),get1.end(),get2[j]);
					if(it!=get1.end()){
						if(*it==get2[j]){
							ans++;
						}
					} 
				}
			}
		}
		cout<<ans<<endl;
	}
}
