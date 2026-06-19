#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long c=1,f=0;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			c=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		f=f*10+ch-'0';ch=getchar();
	}
	return c*f;
}
inline void write(long long x){
	if(x<0){
		putchar('-');write(-1*x);return;
	}
	if(x>=10){
		write(x/10);
	}
	putchar('0'+x%10);return;
}
const long long B1=29;
const long long P1=998244353;
const long long B2=37;
const long long P2=1000000007;
const long long N=200005;
const long long M=5000005;
struct node{
	long long pre1;
	long long pre2;
	long long ne1;
	long long ne2;
	long long hpre1;
	long long hpre2;
	long long hne1;
	long long hne2;
}a[N];
long long n,q;
map<long long,long long>m1,m2;
char s[M],t[M];
inline bool cmp_my(node x,node y){
	if(x.pre1==y.pre1){
		if(x.pre2==y.pre2){
			if(x.ne2==y.ne2){
				return x.ne2<y.ne2;
			}
			return x.ne1<y.ne1;
		}
		return x.pre2<y.pre2;
	}
	return x.pre1<y.pre1;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	for(int i=1;i<=n;i++){
		scanf("%s%s",&s,&t);long long len=strlen(s),l=-1,r=-1;
		for(int j=0;j<len;j++){
			if(s[j]!=t[j]){
				if(l==-1){
					l=j;
				}
				r=j;
			}
		}
		if(l==-1&&r==-1){
			continue;
		}
		for(int j=l;j<=r;j++){
			a[i].pre1=(a[i].pre1*B1+s[j]-'a'+1)%P1;a[i].pre2=(a[i].pre2*B2+s[j]-'a'+1)%P2;
			a[i].ne1=(a[i].ne1*B1+t[j]-'a'+1)%P1;a[i].ne2=(a[i].ne2*B2+t[j]-'a'+1)%P2;
		}
		for(int j=l-1;j>=0;j--){
			a[i].hpre1=(a[i].hpre1*B1+s[j]-'a'+1)%P1;a[i].hpre2=(a[i].hpre2*B2+s[j]-'a'+1)%P2;
		}
		for(int j=r+1;j<len;j++){
			a[i].hne1=(a[i].hne1*B1+s[j]-'a'+1)%P1;a[i].hne2=(a[i].hne2*B2+s[j]-'a'+1)%P2;
		}
	}
//	if(n*q<=1000000){
		while(q--){
			scanf("%s%s",&s,&t);long long len=strlen(s),l=-1,r=-1,ans=0;
			for(int j=0;j<len;j++){
				if(s[j]!=t[j]){
					if(l==-1){
						l=j;
					}
					r=j;
				}
			}
			if(l==-1&&r==-1){
				continue;
			}
			for(int j=l;j<=r;j++){
				a[0].pre1=(a[0].pre1*B1+s[j]-'a'+1)%P1;a[0].pre2=(a[0].pre2*B2+s[j]-'a'+1)%P2;
				a[0].ne1=(a[0].ne1*B1+t[j]-'a'+1)%P1;a[0].ne2=(a[0].ne2*B2+t[j]-'a'+1)%P2;
			}
			m1.clear();m2.clear();m1[0]=m2[0]=1;
			for(int j=l-1;j>=0;j--){
				a[0].hpre1=(a[0].hpre1*B1+s[j]-'a'+1)%P1;a[0].hpre2=(a[0].hpre2*B2+s[j]-'a'+1)%P2;
				m1[a[0].hpre1*P2+a[0].hpre2]=1;
			}
			for(int j=r+1;j<len;j++){
				a[0].hne1=(a[0].hne1*B1+s[j]-'a'+1)%P1;a[0].hne2=(a[0].hne2*B2+s[j]-'a'+1)%P2;
				m2[a[0].hne1*P2+a[0].hne2]=1;
			}
			for(int j=1;j<=n;j++){
				if(a[0].pre1!=a[j].pre1||a[0].pre2!=a[j].pre2){
					continue;
				}
				if(a[0].ne1!=a[j].ne1||a[0].ne2!=a[j].ne2){
					continue;
				}
				if(m1[a[j].hpre1*P2+a[j].hpre2]&&m2[a[j].hne1*P2+a[j].hne2]){
					ans++;
				}
			}
			write(ans);putchar('\n');
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
//	}
//	fclose(stdin);
//	fclose(stdout);
//	return 0;
}
