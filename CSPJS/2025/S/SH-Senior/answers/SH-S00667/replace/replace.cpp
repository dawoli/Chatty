#include <bits/stdc++.h>
using namespace std;
int n,o;
string s1[200010],s2[200010],t1,t2;
int p[200010],q[200010],l1[200010],l2[200010];
int c(string s){
	int f=0,a,t=s.size();
	for(int i=0;i<t;++i){
		if(s[i]!='a'&&s[i]!='b')
			return -1;
		if(s[i]=='b'){
			++f;
			a=i;
		}
		if(f==2)
			return -1;
	}
	if(f==0)
		return -1;
	return a;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>o;
	for(int i=1;i<=n;++i){
		cin>>s1[i]>>s2[i];
		l1[i]=s1[i].size();
		l2[i]=s2[i].size();
		if(c(s1[i])==-1)
			p[i]=-1;
		if(c(s2[i])==-1)
			q[i]=-1;
		if(p[i]!=-1&&q[i]!=-1){
			p[i]=c(s1[i]);
			q[i]=c(s2[i]);
		}
	}
	for(int x=1;x<=o;++x){
		int ans=0;
		cin>>t1>>t2;
		int l=t1.size();
		if(t1.size()!=t2.size()){
			printf("0\n");
			continue;
		}
		if(c(t1)!=-1&&c(t2)!=-1){
			int u=c(t1),v=c(t2);
			for(int i=1;i<=n;++i)
				if(u-v==p[i]-q[i]&&l>=l1[i]&&l-u>=l1[i]-p[i])
					++ans; 
			printf("%d\n",ans);
		}else{
			for(int i=1;i<=n;++i){
				if(l<l1[i])
					continue;
				for(int j=0;j<=l-l1[i];++j)
					if(t1.substr(j,l1[i])==s1[i])
						if(t1.substr(0,j)+s2[i]+t1.substr(j+l1[i],l-j-l1[i])==t2){
							++ans;
							break;
						}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
