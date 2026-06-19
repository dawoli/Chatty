#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int cnt[MAXN][3];
int size[MAXN][3];
vector<pair<string,string> > s;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s1,s2;
	cin>>s1>>s2;
	char c1,c2;
	int num1=1,num2=0;
	c1=s1[0];
	for(int i=1;i<s1.size();i++){
		if(s1[i]!=c1){
		    c2=s1[i];
		    num2++;
		}
		else
		    num1++;
	}
	if(num2==1){
		char c3=c2;
		c2=c1;
		c1=c3;
	}
	for(int i=0;i<s1.size();i++){
		if(s1[i]==c1)
		    cnt[1][1]=i;
	}
	for(int i=0;i<s2.size();i++){
		if(s2[i]==c1)
		    cnt[1][2]=i;
	}
	size[1][1]=s1.size();
	size[1][2]=s2.size();
	for(int i=2;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		for(int j=0;j<s1.size();j++)
		    if(s1[j]==c1)
		        cnt[i][1]=j;
		for(int j=2;j<s2.size();j++)
		    if(s2[j]==c1)
		        cnt[i][2]=j;
		size[i][1]=s1.size();
		size[i][2]=s2.size();
	}
	while(q--){
		string s1,s2;
		int idx1,idx2,sum=0;
		cin>>s1>>s2;
		for(int i=0;i<s1.size();i++)
		    if(s1[i]==c1)
		        idx1=i;
		for(int i=0;i<s2.size();i++)
		    if(s2[i]==c1)
		        idx2=i;
		for(int i=1;i<=n;i++){
			if(cnt[i][1]<=s1[i]&&size[i][1]<=s1.size()&&cnt[i][2]<=s2[i]&&size[i][2]<=s2.size())
			    sum++;
		}
		cout<<sum<<endl;
		/*int sum=0;
		for(int i=0;i<s.size();i++){
			if(!s1.find(s[i].first)||!s2.find(s[i].second))
			    continue;
			for(int l=0,r=s[i].first.size()-1;r<s1.size();l++,r++){
				bool flag=0;
				for(int j=l;j<=r;j++){
					if(s1[j]!=s[i].first[j]){
						flag=1;
						break;
					}
				}
				if(flag==0){
					int fflag=0;
					for(int j=l;j<=r;j++){
						if(s2[j]!=s[i].second[j])
						fflag=1;
						break;
					}
					if(fflag=0)
					    sum++;
				}
			}
		}
		cout<<sum<<endl;*/
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
