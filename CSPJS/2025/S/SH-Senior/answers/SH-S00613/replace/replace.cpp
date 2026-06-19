#include<bits/stdc++.h>
using namespace std;
int read(){
	char ch=getchar();
	int x=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x;
}
void write(long long x){
	if(x/10) write(x/10);
	putchar(x%10+'0');
}
void we(int x){
	write(x);
	putchar('\n');
}
int n,q;
unsigned long long a1[200010],b1[200010],c1[200010],d1[200010],a2[200010],b2[200010],c2[200010],d2[200010],l1[200010],l2[200010],l3[200010],aa1[5000010],dd1[5000010],aa2[5000010],dd2[5000010];
const int h1=73,h2=79;
char ss[5000010],ss2[5000010];
unsigned long long ha1(char *s,int st,int en,int haxi,bool rev){
	unsigned long long now=1,ret=0;
	if(!rev){
		for(int i=st;i<=en;i++){
			ret+=now*(s[i]-'a');
			now*=haxi;
		}
	}
	else{
		for(int i=en;i>=st;i--){
			ret+=now*(s[i]-'a');
			now*=haxi;
		}
	}
	return ret;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();
	q=read();
	for(int i=1;i<=n;i++){
		scanf("%s%s",ss+1,ss2+1);
		int len=strlen(ss+1);
		int st=0,en=-1;
		for(int j=1;j<=len;j++){
			if(ss[j]!=ss2[j]){
				if(st==0) st=j;
				en=j;
			}
		}
		if(st!=0){
			a1[i]=ha1(ss,1,st-1,h1,1);
			b1[i]=ha1(ss,st,en,h1,0);
			c1[i]=ha1(ss2,st,en,h1,0);
			d1[i]=ha1(ss,en+1,len,h1,0);
			a2[i]=ha1(ss,1,st-1,h2,1);
			b2[i]=ha1(ss,st,en,h2,0);
			c2[i]=ha1(ss2,st,en,h2,0);
			d2[i]=ha1(ss,en+1,len,h2,0);
			l1[i]=st-1;
			l2[i]=en-st+1;
			l3[i]=len-en;
//			cout<<a1[i]<<" "<<a2[i]<<endl;
		}
	}
	while(q--){
		scanf("%s%s",ss+1,ss2+1);
		if(strlen(ss+1)!=strlen(ss2+1)){
			we(0);
			continue;
		}
		int len=strlen(ss+1);
		int st=0,en=-1;
		for(int i=1;i<=len;i++){
			if(ss[i]!=ss2[i]){
				if(st==0) st=i;
				en=i;
			}
		}
		unsigned long long bb1=ha1(ss,st,en,h1,0),cc1=ha1(ss2,st,en,h1,0);
		unsigned long long bb2=ha1(ss,st,en,h2,0),cc2=ha1(ss2,st,en,h2,0);
		unsigned long long nww1=1,nww2=1;
		for(int i=st-1;i>=1;i--){
			aa1[st-i]=aa1[st-i-1]+nww1*(ss[i]-'a');
			aa2[st-i]=aa2[st-i-1]+nww2*(ss[i]-'a');
			nww1*=h1,nww2*=h2;
		}
		nww1=nww2=1;
		for(int i=en+1;i<=len;i++){
			dd1[i-en]=dd1[i-en-1]+nww1*(ss[i]-'a');
			dd2[i-en]=dd2[i-en-1]+nww2*(ss[i]-'a');
			nww1*=h1,nww2*=h2;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(l1[i]<=st-1&&l2[i]==en-st+1&&l3[i]<=len-en){
				if(b1[i]==bb1&&b2[i]==bb2&&c1[i]==cc1&&c2[i]==cc2&&a1[i]==aa1[l1[i]]&&a2[i]==aa2[l1[i]]&&d1[i]==dd1[l3[i]]&&d2[i]==dd2[l3[i]]) ++ans;
			}
		}
		we(ans);
	}
	return 0;
}
