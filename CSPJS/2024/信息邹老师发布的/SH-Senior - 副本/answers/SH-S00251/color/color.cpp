#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=2e5+1;
int t,n,a[maxn],c[maxn],ans;
string color;
int score() {
	ans=0;
	for(int i=0;i<(1<<(n-1));i++) {
		int b=i;
		color="";
		while(b) {
			color=(char)(b%2+'0')+color;
			b>>=1;
		}
		while(color.size()<n) {
			color+='0';
		}
		color="0"+color;
		for(int j=1;j<=n;j++) {
			bool flag=0;
			for(int k=j-1;k>0;k--) {
				if(color[j]==color[k]&&a[j]==a[k]) {
					flag=1;
					c[j]=a[j];
				}
			}
			if(!flag) {
				c[j]=0;
			}
		}
		int s=0;
		for(int j=1;j<=n;j++) {
			s+=c[j];
		}
		ans=max(s,ans);
	}
	return ans;
}
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
		cout<<score()<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
