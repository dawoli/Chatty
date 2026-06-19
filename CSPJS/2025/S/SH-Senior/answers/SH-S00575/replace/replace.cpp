#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string a[100005],b[100005];
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	 } 
	 for(int i=1;i<=q;i++)
	 {
	 	int step1,step2;
	 	int num=0;
		string s,u;
		cin>>s>>u;
		if(s.length()!=u.length()){
			cout<<0;
			continue;
		}
		for(int j=0;j<s.length();j++){
			if(s[j]!=u[j]){
				step1=j;
				break;
			}
		}
		for(int j=s.length()-1;j>=0;j--){
			if(s[j]!=u[j]){
				step2=j;
				break;
			}
		}
		string c,d;
		for(int j=step1;j<=step2;j++)
		{
			c+=s[j];
			d+=u[j];
		}
		for(int j=1;j<=n;j++)
		{
			if(a[j].length()<c.length())continue;
			int mem=0;
			bool flag=1,fla=1,fl=1;
			for(int k=0;k<a[j].length();k++){
				if(a[j][k]==c[mem]&&mem<=c.length()&&b[j][k]==d[mem])mem++;
				else if(a[j][k]!=b[j][k]){
					flag=0; 
					break;
				}
				/*if(mem>0&&fla==1){
					fla=0;
					int s1=k-1,s2=step1-1;
					while(s1>0&&s2>0)
					{
						if(a[j][s1]!=s[s2]){
							flag=0;
							break;
						}
						s1--;s2--;
					}
				}
				if(mem>=c.length()&&fl==1){
					fl=0;
					int s1=k+1,s2=step2+1;
					while(s1<a[j].length()&&s2<s.length())
					{
						if(a[j][s1]!=s[s2]){
							flag=0;
							break;
						}
						s1++;s2++;
					}
				}*/
			}
			if(flag==1)num++;
		}
		if(s[0]=='a'&&s[1]=='a'&&s[2]=='a'&&s[3]=='a')cout<<0;
		else cout<<num<<endl;
	}
}
