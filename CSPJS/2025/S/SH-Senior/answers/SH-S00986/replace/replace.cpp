#include<bits/stdc++.h>
using namespace std;
const int L=4e3+9,N=2e5+9;
int trie[L][26][26],cnt[L],ntrie,n,q;
string strin1[N],strin2[N];
void build_trie(int u,string s1,string s2){
	if(s1.length()==0){
		cnt[u]++;
		return;
	}
	int u1=s1[0]-'A',u2=s2[0]-'A';
	if(!trie[u][u1][u2]) trie[u][u1][u2]=++ntrie;
	build_trie(trie[u][u1][u2],s1.substr(1),s2.substr(1));
}
int cntans(int u,string s1,string s2,int dpth){
//	cout<<u<<" "<<s1<<" "<<s2<<" "<<dpth<<" "<<cnt[u]<<"\n";
	int ret=0;
	if(dpth<=0) ret=cnt[u];
	if(s1.length()==0) return ret;
	int u1=s1[0]-'A',u2=s2[0]-'A';
	if(trie[u][u1][u2])
		ret+=cntans(trie[u][u1][u2],s1.substr(1),s2.substr(1),dpth-1);
	return ret;
}
void solveBF(){
	for(int i=1;i<=n;i++){
		string s1,s2;
		s1=strin1[i],s2=strin2[i];
		build_trie(0,s1,s2);
	}
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.length()!=s2.length()){
			cout<<0<<"\n";
			continue;
		}
		int mndif=-1,mxdif=1e9;
		for(int j=0;j<s1.length();j++) if(s1[j]!=s2[j]){
			if(mndif==-1) mndif=j;
			mxdif=j;
		}
//		cout<<mndif<<" "<<mxdif<<"\n";
		int ans=0;
		for(int j=0;j<=mndif;j++){
			ans+=cntans(0,s1.substr(j),s2.substr(j),mxdif-j+1);
		}
		cout<<ans<<"\n";
	}
}
int lb1[N],lb2[N];
void solveflag(){
	for(int i=1;i<=n;i++){
		string s1,s2;
		s1=strin1[i],s2=strin2[i];
		for(int j=0;j<s1.length();j++){
			if(s1[j]=='b') lb1[i]=j;
			if(s2[j]=='b') lb2[i]=j;
		}
	}
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.length()!=s2.length()){
			cout<<0<<"\n";
			continue;
		}
		int lb11=0,lb12=0;
		for(int j=0;j<s1.length();j++){
			if(s1[j]=='b') lb11=j;
			if(s2[j]=='b') lb12=j;
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			if(lb1[j]-lb2[j]!=lb11-lb12) continue;
			if(lb1[j]<=lb11&&strin1[j].length()-lb1[j]<=s1.length()-lb11)
				ans++;
		}
		cout<<ans<<"\n";
	}
}
signed main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	int alllen=0;
	for(int i=1;i<=n;i++){
		cin>>strin1[i]>>strin2[i];
		alllen+=strin1[i].length();
	}
	if(alllen>2000){
		solveflag();
		return 0;
	}
	if(n<=1e3){
		solveBF();
		return 0;
	}
	return 0;
}

