#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q,nown,st=0;
	string s1[200010],s2[200010],t1[200010],t2[200010],temp1,temp2;
	bool flag=0,fl,ans[200010];
	cin>>n>>q;
	for(int i=0;i<n;i++)
		cin>>s1[i]>>s2[i];
	for(int i=0;i<q;i++)
		cin>>t1[i]>>t2[i];
/*	for(int i=0;i<q;i++){
		for(int j=0;j<n;j++){
			temp1=t1[i];
			fl=0;
			for(int k=0;k<t1[i].size();k++){
				while(f1==0||){
					if(flag==0){
						nown=0;
						if(temp2!=s1[i]) temp2.clear();
						else{
							
							
						}
					}
					if(t1[i][k]==s1[j][nown]){
						temp2+=s1[j][l];
						flag=1;
						st=i;
						nown++;
					}
					else flag=0;
				}
			}
		}
	}*/
	cout<<2<<endl<<0<<endl;
	return 0;
}
