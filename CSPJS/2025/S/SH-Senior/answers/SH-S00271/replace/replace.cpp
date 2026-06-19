#include<bits/stdc++.h>
#define ll long long
#define a first
#define b second
using namespace std;
int trie1[5000010][30];
int f1[5000010];
int sz1;
int isend1[200010];
int endsz1[5000010];
int trie2[5000010][30];
int f2[5000010];
int sz2;
int isend2[200010];
int endsz2[5000010];
int n,q;
string s[200010][4];
string t[200010][4];
map<pair<int,int>,int>m;
void read(string *s){
	bool flag=0;
	while(1){
		char a=getchar();
		if(a>='a' && a<='z')*s+=a,flag=1;
		else if(flag) return;
	}
}
void bfs1(){
	queue<ll>q;
	for(ll i=0;i<=25;i++){
		if(trie1[0][i]){
			q.push(trie1[0][i]);
			f1[trie1[0][i]]=0;
		}
	}
	while(!q.empty()){
		ll tmp=q.front();
		q.pop();
		for(ll i=0;i<=25;i++){
			if(!trie1[tmp][i]){
				trie1[tmp][i]=trie1[f1[tmp]][i];
			}
			else{
				f1[trie1[tmp][i]]=trie1[f1[tmp]][i];
				q.push(trie1[tmp][i]);
			}
		}
	}
}
void bfs2(){
	queue<ll>q;
	for(ll i=0;i<=25;i++){
		if(trie2[0][i]){
			q.push(trie2[0][i]);
			f1[trie2[0][i]]=0;
		}
	}
	while(!q.empty()){
		ll tmp=q.front();
		q.pop();
		for(ll i=0;i<=25;i++){
			if(!trie2[tmp][i]){
				trie2[tmp][i]=trie2[f2[tmp]][i];
			}
			else{
				f2[trie2[tmp][i]]=trie2[f2[tmp]][i];
				q.push(trie2[tmp][i]);
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	for(int i=0;i<=25;i++)trie1[0][i]=0;
	for(int i=0;i<=25;i++)trie2[0][i]=0;
	sz1=1;
	sz2=1;
	
	scanf("%d%d",&n,&q);
	for(ll i=1;i<=n;i++){
		read(&s[i][1]);
		read(&s[i][2]);
	}
	for(ll i=1;i<=n;i++){
		ll pos=0;
		for(ll j=0;j<s[i][1].size();j++){
			if(trie1[pos][s[i][1][j]-'a']==0){
				trie1[pos][s[i][1][j]-'a']=sz1;
				pos=sz1;
				sz1++;
				endsz1[pos]=j+1;
			}
			else pos=trie1[pos][s[i][1][j]-'a'];
			if(j==s[i][1].size()-1){
				isend1[i]=pos;
			}
		}
	}
	bfs1();
	//
//	for(int i=0;i<sz1;i++){
//		cout << f1[i] << ' ';
//	}
//	cout << endl;
	//
	for(ll i=1;i<=n;i++){
		ll pos=0;
		for(ll j=0;j<s[i][2].size();j++){
			if(trie2[pos][s[i][2][j]-'a']==0){
				trie2[pos][s[i][2][j]-'a']=sz2;
				pos=sz2;
				sz2++;
				endsz2[pos]=j+1;
			}
			else pos=trie2[pos][s[i][2][j]-'a'];
			if(j==s[i][2].size()-1){
				isend2[i]=pos;
			}
		}
	}
	bfs2();
	//
//	for(int i=0;i<sz2;i++){
//		cout << f2[i] << ' ';
//	}
//	cout << endl;
	//
	for(int i=1;i<=n;i++){
		m[{isend1[i],isend2[i]}]++;;
	}
	for(ll i=1;i<=q;i++){
		long long ans=0;
		read(&t[i][1]);
		read(&t[i][2]);
		int fir=-1,lst=0;
		for(int j=0;j<t[i][1].size();j++){
			if(fir==-1 && t[i][1][j]!=t[i][2][j])fir=j;
			if(t[i][1][j]!=t[i][2][j])lst=j;
		}
		int pos1=0;
		int pos2=0;
		for(int j=0;j<t[i][1].size();j++){
			pos1=trie1[pos1][t[i][1][j]-'a'];
			pos2=trie2[pos2][t[i][2][j]-'a'];
			
			
			
			
			
			if(lst>j)continue;
			int tmp1=pos1;
			int tmp2=pos2;
			while(tmp1 && tmp2){
			//
//				cout << j << ':' << endsz1[tmp1] << ' ' << endsz2[tmp2] << endl;
			//
				if(endsz1[tmp1] && endsz2[tmp2] && endsz1[tmp1]==endsz2[tmp2]){
					if(fir>=j-endsz1[tmp1]+1)ans+=m[{tmp1,tmp2}];
					else break;
				}
				if(endsz1[tmp1] >= endsz2[tmp2])tmp1=f1[tmp1];
				else tmp2=f2[tmp2];
			}
			
		}
		cout << ans << endl;
	}
	return 0;
}

