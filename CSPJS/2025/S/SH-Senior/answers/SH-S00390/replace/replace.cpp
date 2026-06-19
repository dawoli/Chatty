#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=2e5+5;
int n,q;
string s[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		int len1=t1.size(),len2=t2.size(),ans=0;
		for(int j=1;j<=n;j++){
			int qwe=1;
			for(int x=0,y=0;;x++,y++){
				if(x==len1-1&&y==len2-1){
					ans++;
					break;
				}
				int flag=1;
				if(t1[x]==s[j][0][0]&&qwe){
					for(int k=0;k<s[j][0].size();k++){
						if(s[j][0][k]!=t2[y+k]){
							flag=0;
							break;
						}
					}
					for(int k=0;k<s[j][1].size();k++){
						if(s[j][1][k]!=t2[y+k]){
							flag=0;
							break;
						}
					}
					if(flag){
						x+=(s[j][0].size()-1);
						y+=(s[j][1].size()-1);
						qwe=0;
					}
				} 
				if(t1[x]!=t2[x]&&(!flag))	break;
			}
		}
		cout<<0<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

