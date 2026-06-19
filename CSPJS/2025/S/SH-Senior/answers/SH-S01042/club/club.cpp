#include<bits/stdc++.h>
using namespace std;
struct person{
	int a,b,c;
	char x;
}p[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>p[i].a>>p[i].b>>p[i].c;
		int cnt[4]={0,0,0,0};
		long long sum=0;
		for(int i=1;i<=n;i++){
			sum+=max(max(p[i].a,p[i].b),p[i].c);
			if(p[i].a>p[i].b and p[i].a>p[i].c) cnt[1]++,p[i].x='a';
			else if(p[i].b>p[i].c) cnt[2]++,p[i].x='b';
			else cnt[3]++,p[i].x='c';
		}
		if(cnt[1]>n/2){
			int c[100005];
			memset(c,0,sizeof(c));
			for(int i=1;i<=n;i++){
				if(p[i].x=='a'){
					c[i]=p[i].a-max(p[i].b,p[i].c);
				}
			}
			sort(c+1,c+n+1);
			int tmp=cnt[1]-n/2;
			int nsum=0;
			for(int i=1;i<=n;i++){
				if(c[i]!=0){
					nsum+=c[i];
					tmp--;
				}
				if(tmp==0) break;
			}
			cout<<sum-nsum<<endl;
		}
		else if(cnt[2]>n/2){
			int c[100005];
			memset(c,0,sizeof(c));
			for(int i=1;i<=n;i++){
				if(p[i].x=='b'){
					c[i]=p[i].b-max(p[i].a,p[i].c);
				}
			}
			sort(c+1,c+n+1);
			int tmp=cnt[2]-n/2;
			int nsum=0;
			for(int i=1;i<=n;i++){
				if(c[i]!=0){
					nsum+=c[i];
					tmp--;
				}
				if(tmp==0) break;
			}
			cout<<sum-nsum<<endl;
		}
		else if(cnt[3]>n/2){
			int c[100005];
			memset(c,0,sizeof(c));
			for(int i=1;i<=n;i++){
				if(p[i].x=='c'){
					c[i]=p[i].c-max(p[i].b,p[i].a);
				}
			}
			sort(c+1,c+n+1);
			int tmp=cnt[3]-n/2;
			int nsum=0;
			for(int i=1;i<=n;i++){
				if(c[i]!=0){
					nsum+=c[i];
					tmp--;
				}
				if(tmp==0) break;
			}
			cout<<sum-nsum<<endl;
		}
		else cout<<sum<<endl;
	}
}
