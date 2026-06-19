#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N=2e5+9,L=5e6+9;
int n,numq;
string s[2][N],t[2][N];
int cnts=0;
unordered_map<ull,int> mp;
vector<int> vec[N];
//vector<int> to[L];
//bool ex[N][709];
//int cntnode=0;
ull hsh[L];
int l[2*N],r[2*N];
int hshl[2*N],hshr[2*N];
ull pdc[L];

void solvebf(){
	int loc=0;
	for(int i=1;i<=n;i++){
		if(s[0][i]==s[1][i])continue;
		hshl[i]=loc+1;
		for(int j=0;j<l[i];j++)
			hsh[loc+1]=hsh[loc]*26+s[0][i][j]-'a',loc++;
		for(int j=r[i]+1;j<s[0][i].size();j++)
			hsh[loc+1]=hsh[loc]*26+s[0][i][j]-'a',loc++;
		hshr[i]=loc;
	}
	for(int i=1;i<=numq;i++){
		l[i+n]=0;
		while(t[0][i][l[n+i]]==t[1][i][l[n+i]]&&l[n+i]<t[0][i].size())l[n+i]++;
		r[i+n]=t[0][i].size()-1;
		while(t[0][i][r[n+i]]==t[1][i][r[n+i]]&&r[n+i]>=0)r[n+i]--;
		ull hsh0=0;
		for(int j=l[n+i];j<=r[n+i];j++)hsh0=26*hsh0+t[0][i][j]-'a';
		for(int j=l[n+i];j<=r[n+i];j++)hsh0=26*hsh0+t[1][i][j]-'a';
		hshl[n+i]=loc+1;
		for(int j=0;j<l[i];j++)
			hsh[loc+1]=hsh[loc]*26+t[0][i][j]-'a',loc++;
		for(int j=r[i]+1;j<s[0][i].size();j++)
			hsh[loc+1]=hsh[loc]*26+t[0][i][j]-'a',loc++;
		hshr[n+i]=loc;
//		cout<<i<<" "<<hsh0<<endl;
		if(!mp[hsh0]){
			cout<<0<<endl;continue;
		}
		int id=mp[hsh0],ans=0;
		for(int j=0;j<vec[id].size();j++){
			int u=vec[id][j];
			if(l[u]>l[n+i] || (int)s[0][u].size()-r[u]-1 > (int)t[0][i].size()-r[n+i]-1)continue;
			if(hsh[hshr[u]]-hsh[hshl[u]-1] == 
					hsh[hshl[n+i]+l[u]+s[0][u].size()-1-r[u]]
				 - hsh[hshl[n+i]-1]){
				 ans++;
			}
//			cout<<hsh[hshl[n+i]+l[u]+s[0][u].size()-1-r[u]]<<" "<<hsh[hshr[u]]<<endl;
//			cout<<hsh[hshl[n+i]-1]<<" "<<hsh[hshl[u]-1]<<endl;
			
		}
		cout<<ans<<endl;
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pdc[0]=1;for(int i=1;i<=2e6;i++)pdc[i]=pdc[i-1]*26;
	cin>>n>>numq;
	for(int i=1;i<=n;i++){
		cin>>s[0][i]>>s[1][i];
		if(s[0][i]==s[1][i])continue;
		l[i]=0;
		while(s[0][i][l[i]]==s[1][i][l[i]]&&l[i]<s[0][i].size())l[i]++;
		r[i]=s[0][i].size()-1;
		while(s[0][i][r[i]]==s[1][i][r[i]]&&r[i]>=0)r[i]--;
		ull hsh0=0;
		for(int j=l[i];j<=r[i];j++)hsh0=26*hsh0+s[0][i][j]-'a';
		for(int j=l[i];j<=r[i];j++)hsh0=26*hsh0+s[1][i][j]-'a';
		if(mp[hsh0])vec[mp[hsh0]].push_back(i);
		else{mp[hsh0]=++cnts;vec[mp[hsh0]].push_back(i);}
//		cout<<i<<" "<<hsh0<<endl;
//		add(mp[hsh],s[0][i],l,r);
	}
	for(int i=1;i<=numq;i++)cin>>t[0][i]>>t[1][i];
	if(n*numq<=2e6+9)solvebf();
	
	return 0;
}
