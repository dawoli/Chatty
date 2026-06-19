#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
#define M 
#define fio(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define fclo() fclose(stdin);fclose(stdout);

int a[N][5];
int c[N][5];
int b[5];
int d[N],cnt;

int now;
bool cmp(int x,int y){
	return a[now][x]>a[now][y];
}

int read(){
	int x=0,w=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+(ch^48);
		ch=getchar();
	}
	return w*x;
}

void mian(){
	b[1]=b[2]=b[3]=0;
	cnt=0;
	
	int n,ans=0;n=read();
	for(int i=1;i<=n;i++){
		now=i;
		a[i][1]=read();a[i][2]=read();a[i][3]=read();
		c[i][1]=1;c[i][2]=2;c[i][3]=3;
		sort(c[i]+1,c[i]+4,cmp);
		b[c[i][1]]++;ans+=a[i][c[i][1]];
	}
	for(int i=1;i<=3;i++){
		if(b[i]>n/2){
			for(int j=1;j<=n;j++){
				if(c[j][1]==i){
					d[++cnt]=a[j][c[j][2]]-a[j][i];
				}
			}
			sort(d+1,d+1+cnt);//cout<<i<<endl;
			for(int j=n/2+1;j<=cnt;j++){
				ans+=d[j];
			}
		}
	}
	cout<<ans<<endl;
}

int main(){
	fio("club");
	int T=1;T=read();
	while(T--)mian();
	fclo();
	return 0;
}
