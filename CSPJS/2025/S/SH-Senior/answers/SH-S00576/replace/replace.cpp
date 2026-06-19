#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a1[100005],a2[100005],s1,s2;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int q;
	
	int n;
	cin>>n>>q;
	for (int i=0;i<n;i++){
		cin>>a1[i]>>a2[i];
	}
	while (q--){
		int ans=0;
		cin>>s1>>s2;
		int len1=0,len2=0;
		int m=s1.size();
		for (int i=0;i<m;i++){
			if (s1[i]!=s2[i]) {
				len1=i;
				break;
			}
		
		}
		for (int i=m-1;i>=0;i--){
			if (s1[i]!=s2[i]) {
				len2=i;
				break;
			}
		
		}
		if (s1==s2){
			cout<<0<<'\n';
			break;
		}
		else{
			for (int i=0;i<len1;i++){
				for (int j=m-1;j>len2;j--){
					for (int tmp=0;tmp<n;tmp++){
						bool flag=0;
						for (int k=i;k<=j;k++){
							if (a1[tmp][k]==s1[k] && a2[tmp][k]==s2[k])	{
								continue;
							}
							else {
								flag=1;
								break;
							}
						
						}
						if (flag==0){
							//cout<<i<<" "<<j<<endl;
							ans++;
						}
						flag=0;
						for (int k=i;k<=j;k++){
							if (a2[tmp][k]==s1[k] && a1[tmp][k]==s2[k])	{
								continue;
							}
							else {
								flag=1;
								break;
							}
						
						}
						if (flag==0){
							//cout<<i<<" "<<j<<endl;
							ans++;
						}
					}
					
				}
			}
		}
		cout<<ans<<'\n';
	}
} 
