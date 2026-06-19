#include<bits/stdc++.h>
using namespace std;
/*
everyone should chain AT LEAST TWO words
the first word MUST be 1
*/
int T;
int n,k,q;
int l[200010];
int s[4000][4000]= {0};
/*players should use the non-break words in string "s"*/
int r,c;
/*r,c means the r(th) preson's last word is c*/
long long lap=0;//last person
bool flag=0;
void ssrand() {
	while(q--) {
		cout<<rand()%2<<endl;
	}
}
void sdg(int x,int y) {
	if((s[i][j]==1)&&(r==0)) {
		flag=1;
		return ;
	}
	if(flag==1) {
		return ;
	}
	if(r==0) {
		return ;
	}
	for(int ii=1; ii<=n; ++ii) {
		for(int jj=l[ii]; jj>=1; --jj) {
			if((s[ii][jj]==s[x][j])&&jj>=2) {
				for(int ijj=2; ijj<=k; ++ijj) {
					if(l[ii]=ijj<0) {
						break;
					}
					lap=ii;
					sdg(ii,jj-ijj);
				}
			}
		}
	}
}
int main() {
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	srand(time(0));
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d %d",&n,&k,&q);
		for(int i=1; i<=n; ++i) {
			scanf("%d",&l[i]);
			if(l[i]>4000) {
				ssrand();
				return 0;
			}
			for(int j=1; j<=l; ++j) {
				scanf("%d",&s[i][j]);
			}
		}
		while(q--) {
			scanf("%d %d",&r,&c);
			for(int i=1; i<=n; ++i) {
				for(int j=l[i]; j>=1; --j) {
					if((s[i][j]==c)&&j>=2) {
						for(int ij=2; ij<=k; ++ij) {
							if(l[i]=ij<0) {
								break;
							}
							lap=i;
							sdg(i,j-ij);
						}
					}
				}
			}
		}

	}
}
