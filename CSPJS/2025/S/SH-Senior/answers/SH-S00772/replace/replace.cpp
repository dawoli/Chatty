#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define N 200005
#define L 2005
#define P 13331
#define fio(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define fclo() fclose(stdin);fclose(stdout);

ull ppow[N];
string s1,s2;
map<ull,vector<ull> > mp;

int main(){
	fio("replace");
	ppow[0]=1;
	for(int i=1;i<=P;i++)ppow[i]=ppow[i-1]*P;
	
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		ull hash1=0,hash2=0;
		for(int j=0;j<s1.size();j++){
			hash1+=(s1[j]-'a'+1)*ppow[s1.size()-j-1];
			hash2+=(s2[j]-'a'+1)*ppow[s2.size()-j-1];
		}// cout<<hash1<<' '<<hash2<<endl;
		mp[hash1].push_back(hash2);
	}
	
	while(q--){
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<endl;
			continue;
		}
		int len=s1.size();
		int maxl=0,minr=len-1,ans=0;
		while(s1[maxl]==s2[maxl])maxl++;
		while(s1[minr]==s2[minr])minr--;
		for(int j=minr;j<len;j++){
			ull hash1=0,hash2=0;
			for(int i=maxl+1;i<=j;i++){
				hash1+=(s1[i]-'a'+1)*ppow[j-i];
				hash2+=(s2[i]-'a'+1)*ppow[j-i];
			}
			for(int i=maxl;i>=0;i--){
				hash1+=(s1[i]-'a'+1)*ppow[j-i];
				hash2+=(s2[i]-'a'+1)*ppow[j-i];
//				cout<<i<<' '<<j<<' '<<hash1<<' '<<hash2<<endl; 
				for(ull k:mp[hash1]){
					if(k==hash2){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	
	fclo();
	return 0;
}
