#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e5+10;
int n,m,a[N],l1,l2,left1,right1,cnt;
string s1,s2,t1,t2,t,s,tp,sp;
map<string,string> mp;

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	for(int i=1;i<=m;++i){
		left1=right1=cnt=0;
		cin>>t1>>t2;
		t1=' '+t1,t2=' '+t2;
		l1=t1.size(),l2=t2.size();
		for(int j=1;j<=l1;++j){
			if(t1[j]!=t2[j]){
				t+=t1[j],s+=t2[j];
				if(left1==0) left1=j;
				right1=j;
			}
		}
		if(mp[t]==s) cnt++;
		for(int j=right1;j<=l1;++j){
			if(i!=right1) t=t1[j]+t;
			tp=t,sp=s;
			for(int j=left1;j>=1;--j){
				if(j!=left1){
					t+=t1[j];
					s+=t2[j];
				}
				if(mp[t]==s) cnt++;
				t=tp,s=sp;
			}
		}
		cout<<cnt<<endl;
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int t=1;
	while(t--){
		solve();
	}
	return 0;
} 
