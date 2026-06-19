#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned __int128

const int N=2e5+5;
int n,q;
string s1[N],s2[N];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);ios::sync_with_stdio(0);
	
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=0;i<q;i++){
		int res=0;
		string t1,t2;cin>>t1>>t2;
		for(int j=0;j<n;j++){
			auto f1=t1.find(s1[j]),f2=t2.find(s2[j]);
			if(f1==string::npos)continue;
			bool f=true;
			for(int k=0;k<t1.size();k++){
				if(f1<=k&&k<f1+s1[j].size())continue;
				if(t1[k]!=t2[k])f=0;
			}
			if(f&&f1==f2)res++;
		}
		cout<<res<<'\n';
	}
	
	cout<<flush;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

