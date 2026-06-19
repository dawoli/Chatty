#include<bits/stdc++.h>
using namespace std;
const int N=200009;
int n,q;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)cin>>s1[i]>>s2[i];
	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		int si1=t1.size(),si2=t2.size();
		if(si1>=200000||si2>=200000){
			cout<<"0\n";
			continue;
		}
		for(int i=0;i<n;i++){
			int ss=s1[i].size();
			for(int j=0;j<=si1-ss;j++){
				string s3,s4;
				for(int k=0;k<j;k++)s3+=t1[k];
				s3+=s2[i];
				for(int k=j+ss;k<si1;k++)s3+=t1[k];
				if(s3==t2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
