#include<bits/stdc++.h>
using namespace std;
int n,q;
int s[5000005][2][2];
struct u{
	int p[2];
};
vector<u> ss[10000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	string s1,s2;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		bool flag1=0,flag2=0;
		for(int j=0;j<s1.length();j++){
			if(s1[j]=='a'){
				if(flag1)s[i][0][1]++;
				else s[i][0][0]++;
			}
			else flag1=1;
			if(s2[j]=='a'){
				if(flag2)s[i][1][1]++;
				else s[i][1][0]++;
			}
			else flag2=1;
		}
		ss[s[i][0][0]-s[i][1][0]+5000002].push_back({s[i][0][0],s[i][0][1]});
	}
	while(q--){
		int si[2][2]={{0,0},{0,0}},ans=0;
		cin>>s1>>s2;
		if(s1.length()!=s2.length()){
			continue;
		}
		bool flag1=0,flag2=0;
		for(int j=0;j<s1.length();j++){
			if(s1[j]=='a'){
				if(flag1)si[0][1]++;
				else si[0][0]++;
			}
			else flag1=1;
			if(s2[j]=='a'){
				if(flag2)si[1][1]++;
				else si[1][0]++;
			}
			else flag2=1;
		}
		int z=si[0][0]-si[1][0]+5000002;
		for(int i=0;i<ss[z].size();i++){
			if(ss[z][i].p[0]<=si[0][0]&&ss[z][i].p[1]<=si[0][1])ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

