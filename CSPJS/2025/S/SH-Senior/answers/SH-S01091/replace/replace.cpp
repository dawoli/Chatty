#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
int n,q;
int trie[MAXN][30];
pair<int,int> ans[MAXN];
int cnt=1;
int trie2[MAXN][30];
int ans2[MAXN];
int cnt2=1;
int trie3[MAXN][30];
int ans3[MAXN];
int cnt3=1;
int ind(char c){
	if('a'<=c && c<='z') return c-'a';
	else return 26;
}
void insert(string s1,string s2){
	if(s1==s2) return;
	int l=0,r=s1.size()-1;
	while(s1[l]==s2[l]) l++;
	while(s1[r]==s2[r]) r--;
	string buf=s1.substr(l,r-l+1)+' '+s2.substr(l,r-l+1);
	int len=buf.size();
	int cur=0;
	int jump1,jump2;
	for(int i=0;i<=len;i++){
		if(i==len){
			if(ans[cur].first || ans[cur].second){
				jump1=ans[cur].first;
				jump2=ans[cur].second;
				break;
			}
			ans[cur]=make_pair(cnt2,cnt3);
			jump1=ans[cur].first;
			jump2=ans[cur].second;
			cnt2++;
			cnt3++;
			break;
		}
		int nxt=trie[cur][ind(buf[i])];
		if(nxt){
			cur=nxt;
			continue;
		}
		nxt=cnt;
		cnt++;
		trie[cur][ind(buf[i])]=nxt;
		cur=nxt;
	}
	buf=s1.substr(0,l);
	len=buf.size();
	cur=jump1;
	for(int i=0;i<=len;i++){
		if(i==len){
			ans2[cur]++;
			break;
		}
		int nxt=trie2[cur][ind(buf[i])];
		if(nxt){
			cur=nxt;
			continue;
		}
		nxt=cnt2;
		cnt2++;
		trie2[cur][ind(buf[i])]=nxt;
		cur=nxt;
	}
	buf=s1.substr(r+1,s1.size()-r-1);
	len=buf.size();
	cur=jump2;
	for(int i=0;i<=len;i++){
		if(i==len){
			ans3[cur]++;
			break;
		}
		int nxt=trie3[cur][ind(buf[i])];
		if(nxt){
			cur=nxt;
			continue;
		}
		nxt=cnt3;
		cnt3++;
		trie3[cur][ind(buf[i])]=nxt;
		cur=nxt;
	}
}
int find(string s1,string s2){
	int ret1=0,ret2=0;
	int l=0,r=s1.size()-1;
	while(s1[l]==s2[l]) l++;
	while(s1[r]==s2[r]) r--;
	string buf=s1.substr(l,r-l+1)+' '+s2.substr(l,r-l+1);
	int len=buf.size();
	int cur=0;
	int jump1,jump2;
	for(int i=0;i<=len;i++){
		if(i==len){
			jump1=ans[cur].first;
			jump2=ans[cur].second;
			break;
		}
		int nxt=trie[cur][ind(buf[i])];
		if(nxt){
			cur=nxt;
			continue;
		}
		return 0;
	}
	buf=s1.substr(0,l);
	len=buf.size();
	cur=jump1;
	for(int i=0;i<=len;i++){
		ret1+=ans2[cur];
		int nxt=trie2[cur][ind(buf[i])];
		if(nxt){
			cur=nxt;
			continue;
		}
		break;
	}
	buf=s1.substr(r+1,s1.size()-r-1);
	len=buf.size();
	cur=jump2;
	for(int i=0;i<=len;i++){
		ret2+=ans3[cur];
		int nxt=trie3[cur][ind(buf[i])];
		if(nxt){
			cur=nxt;
			continue;
		}
		break;
	}
	return min(ret1,ret2);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		insert(s1,s2);
	}
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
		cout<<find(s1,s2)<<endl;
	}
	return 0;
}
