#include<iostream>
#include<cstring>
using namespace std;
int n,q,tmp,ans;char s[200001][3][101],t[200001][3][101],te[301];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
	for(int j=1;j<=q;j++)cin>>t[j][1]>>t[j][2];
	for(int j=1;j<=q;j++){
		ans=0;
		for(int k=1;k<=n;k++){
			strcpy(te,s[k][1]);
		    for(int ii=0;ii<=strlen(s[k][1])-strlen(t[j][1]);ii++){
		        tmp=0;
		        for(int jj=0;jj<strlen(s[k][1]);jj++)if(t[j][1][jj]==s[k][1][ii+jj])tmp++;
		        if(tmp==strlen(s[k][1])){
			        for(int jj=0;jj<strlen(t[j][1]);jj++)s[k][1][ii+jj]=t[j][1][jj];
			        if(strcmp(s[k][1],s[k][2]))ans++;
		        }
	        }
	        strcpy(s[k][1],te);
		}
		cout<<ans<<endl;
	}
	return 0;
}
