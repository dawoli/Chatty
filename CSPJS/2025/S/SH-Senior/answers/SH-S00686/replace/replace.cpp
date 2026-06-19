#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct Node{
	string a;
	string b;
}s[200002];
int b[200002];
int cnt[5000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	bool B=true;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
		if(B){
			int posa=-1;
			int cntaa=0,cntab=0;
			for(int j=0;j<s[i].a.size();j++){
				if(s[i].a[j]=='a')cntaa++;
				if(s[i].a[j]=='b'){
					posa=j;
					cntab++;
				}
			}
			if(posa==-1)B=false;
			if(cntaa+cntab!=s[i].a.size() || cntab!=1)B=false;
			int posb=-1;
			int cntba=0,cntbb=0;
			for(int j=0;j<s[i].b.size();j++){
				if(s[i].b[j]=='a')cntba++;
				if(s[i].b[j]=='b'){
					posb=j;
					cntbb++;
				}
			}
			if(posb==-1)B=false;
			if(cntba+cntbb!=s[i].b.size() || cntbb!=1)B=false;
			b[i]=posb-posa;
		}
	}
	for(int i=1;i<=q;i++){
		bool flag=true;
		string ht,dy;
		cin>>ht>>dy;
		if(B){
			int posa=-1;
			int cntaa=0,cntab=0;
			for(int j=0;j<ht.size();j++){
				if(ht[j]=='a')cntaa++;
				if(ht[j]=='b'){
					posa=j;
					cntab++;
				}
			}
			if(posa==-1)flag=false;
			if(cntaa+cntab!=ht.size() || cntab!=1)flag=false;
			int posb=-1;
			int cntba=0,cntbb=0;
			for(int j=0;j<dy.size();j++){
				if(dy[j]=='a')cntba++;
				if(dy[j]=='b'){
					posb=j;
					cntbb++;
				}
			}
			if(posb==-1)flag=false;
			if(cntba+cntbb!=dy.size() || cntbb!=1)flag=false;
			if(!flag){
				cout<<"0"<<"\n";
			}else{
				int move=posb-posa;
				int ans=0;
				for(int k=1;k<=n;k++){
					if(move==b[k])ans++;
				}
				cout<<ans<<"\n";
			}
		}
	}
	return 0;
} 

/*

2 1
aba aab
ba ab
abaa aaba

*/
