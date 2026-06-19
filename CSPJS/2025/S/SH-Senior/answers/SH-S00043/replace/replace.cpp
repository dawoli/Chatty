#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=1e3+10;
int n,q;
struct node{
	ull x,y;
	int len1,len2;
} exchan[N];
string s1,s2;
ull t1[N],t2[N],p[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	p[0]=1;
	for(int i=1;i<N;i++){
		p[i]=p[i-1]*13331;
	}
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int len1=s1.size(),len2=s2.size();
		ull x=0,y=0;
		for(int j=1;j<=len1;j++){
			x=x*13331+(s1[j-1]-'a'+1);
		}
		for(int j=1;j<=len2;j++){
			y=y*13331+(s2[j-1]-'a'+1);
		}
		exchan[i]={x,y,len1,len2};
	}
	while(q--){
		
		cin>>s1>>s2;
		ull goal=0;
		int m=s1.size();
		for(int j=1;j<=m;j++){
			t1[j]=t1[j-1]*13331+(s1[j-1]-'a'+1);
			
		}
		for(int j=1;j<=s2.size();j++){
			goal=goal*13331+(s2[j-1]-'a'+1);
		}
		int ans=0;
		for(int i=1;i<=m;i++){
			for(int k=1;k<=n;k++){
				int len1=exchan[k].len1,len2=exchan[k].len2;
				ull x=exchan[k].x,y=exchan[k].y;
				int j=i-len1+1;
				if(j<1)	continue;
				ull temp=t1[i]-t1[j-1]*p[len1];
				if(temp!=x)	continue;
				ull pre=t1[j-1],suf=t1[m]-t1[i]*p[m-i];
				ull newt1=suf+y*p[m-i]+pre*p[m-i+len2];
				if(newt1==goal)	ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
