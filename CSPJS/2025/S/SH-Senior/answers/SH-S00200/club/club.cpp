#include<bits/stdc++.h>
using namespace std;
int t;
struct member{
	int a,b,c,cl;
}m[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>m[i].a>>m[i].b>>m[i].c;
		}
		int x=0,y=0,z=0;
		for(int i=1;i<=n;i++){
			if(m[i].a>=m[i].b&&m[i].a>=m[i].c){
				m[i].cl=1;
				x++;
				if(x>n/2){
					int bst,bstid,bstn=1e9;
					for(int j=1;j<=n;j++){
						if(m[j].cl==1&&(m[j].a-max(m[j].b,m[j].c))<=bstn){
							bstn=m[j].a-max(m[j].b,m[j].c);
							bstid=j;
							if(m[j].b>m[j].c){
								bst=2;
							}else{
								bst=3;
							}
						}
					}m[bstid].cl=bst;
				}
			}
			//----------------------------------------------------------------
			if(m[i].b>=m[i].a&&m[i].b>=m[i].c){
				m[i].cl=2;
				y++;
				if(y>n/2){
					int bst,bstid,bstn=1e9;
					for(int j=1;j<=n;j++){
						if(m[j].cl==2&&(m[j].b-max(m[j].a,m[j].c))<=bstn){
							bstn=m[j].b-max(m[j].a,m[j].c);
							bstid=j;
							if(m[j].a>m[j].c){
								bst=1;
							}else{
								bst=3;
							}
						}
					}m[bstid].cl=bst;
				}
			}
			//----------------------------------------------------------------
			if(m[i].c>=m[i].b&&m[i].c>=m[i].a){
				m[i].cl=3;
				z++;
				if(x>n/2){
					int bst,bstid,bstn=1e9;
					for(int j=1;j<=n;j++){
						if(m[j].cl==3&&(m[j].c-max(m[j].b,m[j].a))<=bstn){
							bstn=m[j].c-max(m[j].b,m[j].a);
							bstid=j;
							if(m[j].b>m[j].a){
								bst=2;
							}else{
								bst=1;
							}
						}
					}m[bstid].cl=bst;
				}
			}
		}
		int res=0;
		for(int i=1;i<=n;i++){
			if(m[i].cl==1){
				res+=m[i].a;
			}
			if(m[i].cl==2){
				res+=m[i].b;
			}
			if(m[i].cl==3){
				res+=m[i].c;
			}
		}
		cout<<res<<endl;
	}
} 
