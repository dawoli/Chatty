#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s1[10005],s2[100005];
	for(int i=0;i<n;i++)cin>>s1[i]>>s2[i];
	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		for(int i=0;i<n;i++){
			for(int j=0;j<t1.length();j++){
				int flag=1;
				string t3,t4;
				if(t1[j]==s1[i][0]){
					flag=j;
					for(int k=j;k<j+s1[i].length();k++){
						if(t1[k]!=s1[i][k])flag=0;
					}
				}
				if(flag!=0){
					for(int x=0;x<flag;x++){
						t3+=t1[x];
					}
					t3+=s2[i]; 
					if(t3==t2)ans++;
				}
			}
		}
	cout<<ans<<endl;
	}
	return 0;
}
