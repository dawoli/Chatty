#include<bits/stdc++.h>
using namespace std;
int n,m,c[509],p[509];char s[509];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;++i)p[i]=i,scanf("%d",&c[i]);
	int l=0,r=0;
	do{
		r=0;
		for(int i=1;i<=n;++i){
			if(s[i]=='0'||r>=c[p[i]])++r;
		}
		l+=(n-r>=m);
	}while(next_permutation(p+1,p+n+1));
	printf("%d\n",l);
	return 0;
}
// Break free we chased our dreams beneath the starry night
// In the face of god we rose as one

