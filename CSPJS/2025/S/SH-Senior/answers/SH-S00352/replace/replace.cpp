#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
void sync(){
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL);
}
const ll N=2e5+10,base=131;
int q,n;
string s[N][3],t[N][3];
ull h1[N][3],h2[N][3],pw1[N],p[N];
vector<int> loc;
ull hash1(string x){
	int l=x.length();
	long long res=0;
	for(int i=0;i<l;i++) res=x[i]-'a'+1+res*base;
	return res;
}
ull get1(int l,int r,int x){
	return h1[x][1]*pw1[r-l+1];
}
ull get2(int l,int r,int x){
	return h1[x][2]*pw1[r-l+1];
}
void profix(string x){
	int l=x.length();
	p[0]=1;
	for(int i=1;i<l;i++){
		int j=p[i-1];
		while(j>0 && x[i]!=s[j]) j=p[j];
		if(x[i]==x[j]) p[i]++;
		p[i]=j;
	}
}
void kmp(string x1,string x2){
	int l1=x1.length(),l2=x2.length();
	string k=x1+"#"+x2;
	int cur=k.length();
	profix(k);
	for(int i=l1+1;i<cur;i++){
		if(p[i]==l1) loc.push_back(cur-2*i);
	}
}
void clear(){
	
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	sync();
	pw1[0]=1;
	for(int i=1;i<=N-1;i++){
		pw1[i]=(pw1[i-1]*base1)%mod;
	}
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>s[i][1]>>s[i][2];
		h1[i][1]=hash1(s[i][1]);
		h1[i][2]=hash1(s[i][2]);
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
		h2[i][1]=hash1(t[i][1]);
		h2[i][2]=hash1(t[i][2]);
		clear();
		for(int j=1;j<=n;j++){
			kmp(s[j][1],t[i][1]);
			for(auto u:loc){
				int v=u+
			}
		}
		cout<<h3[i]<<" ";
	}
	cout<<"\n";
	
	return 0;
}

