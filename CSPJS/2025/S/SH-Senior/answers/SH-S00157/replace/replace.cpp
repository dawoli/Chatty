#include<bits/stdc++.h>
using namespace std;
string a[200010][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1];
	for(int i=1;i<=q;i++){
		string s1,s2,s3;
		int ans=0;
		cin>>s1>>s2;
		for(int j=1;j<=n;j++){
			s3=s1;
			int t=s1.find(a[j][0]);
			if(t<0)break;
			for(int k=t;k<a[j][0].size()+t;k++)s3[k]=a[j][1][k-t];
			if(s3==s2)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
