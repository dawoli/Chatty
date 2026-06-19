#include<bits/stdc++.h>
using namespace std;
struct node{
	string s1,s2;
}s[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s[i].s1>>s[i].s2;
	}
	while(q--){
		int ans=0;
		string k1,k2;
		cin>>k1>>k2;
		int flag=0;
		for(int i=0;i<n;i++){
			if(s[i].s1.length()>k1.length())continue;
			int r=0;
			for(int l=0;l<k1.length()-s[i].s1.length();l++)
			{
				if(k1[l]==s[i].s1[r]&&k2[l]==s[i].s2[r]){
					string k3=k1;
					k3[l]=s[i].s2[r];
					while(l<k1.length()&&r<s[i].s1.length()-1){
						l++,r++;
						if(k1[l]==s[i].s1[r]&&k2[l]==s[i].s2[r])
							k3[l]=s[i].s2[r];
					}
					
					if(k3==k2)
					{
						ans++;
						flag=1;
						break;	
					}
				}
				if(flag)break;
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
