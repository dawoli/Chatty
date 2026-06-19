#include <bits/stdc++.h>
using namespace std;
#define N 505
#define ll long long
#define fio(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define fclo() fclose(stdin);fclose(stdout);

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

int n,m;
string s;
int c[N],a[N];

int main(){
	fio("employ");
	n=read();m=read();
	cin>>s;s=' '+s;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)a[i]=i;
	
	int ans=0;
	do{
		int ref=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||ref>=c[a[i]])ref++;
		}
		ans+=(ref<=n-m);
	}while(next_permutation(a+1,a+1+n));
	cout<<ans<<endl;
	fclo();
	return 0;
}
