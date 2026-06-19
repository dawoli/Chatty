#include<bits/stdc++.h>
using namespace std;
int n,q,cnt,h[200010][30],d,a[30];
string s[400010][4],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=n;i++){
		for(int j=0;j<s[i][1].size();j++){
			h[i*2+1][s[i][1][j]-'a']++;
			h[i*2+2][s[i][2][j]-'a']++;
		}
	}
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		for(int i=0;i<26;i++)h[1][i]=h[2][i]=0;
		for(int i=0;i<t1.size();i++){
			h[1][t1[i]-'a']++;
			h[2][t2[i]-'a']++;
		}
		d=0;
		for(int i=0;i<26;i++)d+=abs(h[1][i]-h[2][i]);
		for(int i=1;i<=n;i++){
			if(d>2*s[i][1].size())continue;
			bool flag=1;
			for(int j=0;j<26;j++){
				a[j]=h[1][j]-h[i*2+1][j]+h[i*2+2][j];
				if(a[j]!=h[2][j]){
					flag=0;break;
				}
			}
			if(!flag)continue;
			for(int j=0;j+s[i][1].size()-1<t1.size();j++){
					bool flag=1;
					for(int k=j;k<j+s[i][1].size();k++){
						if(t1[k]!=s[i][1][k-j]){
							flag=0;
							break;
						}
					}
					if(!flag)continue;
					if(t1.substr(0,j)+s[i][2]+t1.substr(j+s[i][1].size())==t2){
					//	cout<<t1.substr(0,j)+s[i][2]+t1.substr(j+s[i][1].size())<<'\n';
						cnt++;
					}
				}
		}
		cout<<cnt<<'\n';cnt=0;
	}
	return 0;
}
