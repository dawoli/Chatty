#include<bits/stdc++.h>
using namespace std;
int nxt[2100000],n,q;
string s[210000][2],t[210000][2];
namespace subBF{
	void func(){
		for(int i=1;i<=q;i++){
			int cnt=0;
			for(int j=2;j<t[i][0].length();j++){
				int k=nxt[j-1];
				while(t[i][0][j]!=t[i][0][k+1] and k>0)k=nxt[k];
				if(t[i][0][j]==t[i][0][k+1])k++;
				nxt[j]=k;
			}
			for(int j=1;j<=n;j++){
				int st=-1;
				for(int k=1,l=0;k<t[i][0].length();k++){
					while(t[i][0][k]!=s[j][0][l+1] and l>0)l=nxt[l];
					if(t[i][0][k]==s[j][0][l+1])l++;
					if(l==s[j][0].length()-1){
						st=k-l+1;
						break;
					}
				}
				if(st==-1)continue;
				int flag=1;
				for(int k=1;flag and k<t[i][0].length();k++){
					if(k>=st and k<=st+s[j][0].length()-2){
						if(t[i][1][k]!=s[j][1][k-st+1])flag=0;
					}
					else if(t[i][1][k]!=t[i][0][k])flag=0;
				}
				cnt+=flag;
			}
			printf("%d\n",cnt);
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		s[i][0]=" "+s[i][0];
		s[i][1]=" "+s[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1];
		t[i][0]=" "+t[i][0];
		t[i][1]=" "+t[i][1];
	}
	subBF::func();
	return 0; 
}
