#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e5+5;
int t,n;
int p[N][4];
int l[N],c[4];
bool s[N];
struct node{
	int pep;
	int v;
	int a;
}num[300015];
int cmp(node p1,node p2){
	return p1.a>p2.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0,cnt=0;
		memset(s,false,sizeof(s));
		memset(c,0,sizeof(c));
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>p[i][j];
				num[++cnt].pep=i;
				num[cnt].v=j;
				num[cnt].a=p[i][j];
			}
			int maxn;
			l[i]=max(max(p[i][1],p[i][2]),p[i][3]);
			if(p[i][1]>p[i][2]){
				maxn=1;
				if(p[i][1]<p[i][3])
					maxn=3;
			}
			else {
			maxn=2;
			if(p[i][2]<p[i][3])		maxn=3;
			}
			c[maxn]++;
		}
			sort(num+1,num+cnt+1,cmp);
		for(int i=1;i<=n;i++)
			ans+=l[i];
		bool p=false; 
		for(int i=1;i<=3;i++)	
			if(c[i]>n/2)	
				p=true;
		if(p){
			cout<<ans<<endl;
			return 0;
		}
		for(int i=1;i<=n;i++){
	 	if(!s[num[i].pep] && (c[num[i].v]+1<=n/2)){
				ans+=num[i].a;
				s[num[i].pep]=true;
				c[num[i].v]++;
			}
		}
		cout<<ans<<endl; 	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
