#include <bits/stdc++.h>
using namespace std;
int n,q;
char q1[200005],q2[200005],t1[200005];
char l1[1005][2005],l2[1005][2005];
int next[1005][2005];
int ss[200005],ls;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int j=1;j<=n;j++){
		string s1,s2;
		cin>>s1;
		cin>>s2;
		ss[j]=s1.size();
		for(int i=0;i<ss[j];i++){
			l1[j][i+1]=s1[i];
			l2[j][i+1]=s2[i];
		}
	}
	for(int k=1;k<=n;k++){
		int j=0;
		for(int i=2;i<=ss[k];i++){
			while(j!=0&&l1[k][i]!=l1[k][j+1]){
				j=next[k][j];
			}
			if(l1[k][i]==l1[k][j+1]){
				j++;
				next[k][i]=j;
			} 
		}
	}
	for(int re=1;re<=q;re++){
		string s1,s2;
		cin>>s1;
		cin>>s2;
		int ls=s1.size();
		for(int t=0;t<ls;t++){
			q1[t+1]=s1[t];
			t1[t+1]=s1[t];
			q2[t+1]=s2[t];
		}
		int ans=0;
		for(int k=1;k<=n;k++){
			int j=0;
			for(int i=1;i<=ls;i++){
				while(j>0&&q1[i]!=l1[k][j+1]){
					j=next[k][j];
				}
				if(q1[i]==l1[k][j+1]){
					j++;
				}
				if(j==ss[k]){
					//cout<<k<<endl;
					int tot=1;
					//cout<<i-ss[k]+1<<" "<<i<<endl;
					for(int p=i-ss[k]+1;p<=i;p++){
						q1[p]=l2[k][tot];
						tot++;
					}
					/*for(int r=1;r<=ls;r++){
						cout<<q1[r];
					}
					cout<<" ";
					for(int r=1;r<=ls;r++){
						cout<<q2[r];
					}
					cout<<endl;*/
					int flag=0;
					for(int df=1;df<=ls;df++){
						if(q1[df]!=q2[df]){
							flag=1;
							break;
						}
					}
					for(int qw=1;qw<=ls;qw++){
						q1[qw]=t1[qw];
					}
					if(flag==0){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
