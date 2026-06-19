#include<bits/stdc++.h>
using namespace std;
struct stu{
	long long a,b,c;
}s[1000010];
long long z[20];
long long l[12][1000010];
int f[10010];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
bool cmp(stu x,stu y){
	return x.c<=y.c;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m,k,cnt=0;
	long long sum=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>s[i].a>>s[i].b>>s[i].c;
	}
	for(int i=1;i<=k;i++){
		cin>>z[i];
		for(int j=1;j<=n;j++){
			cin>>l[i][j];
		}
	}
	sort(s+1,s+1+m,cmp);
	long long mins,mini;
	for(int i=1;i<=m;i++){
		if(cnt==n-1) break;
		if(find(s[i].a)!=find(s[i].b)){
			mins=s[i].c;
			mini=0;
			for(int j=1;j<=k;j++){
				if(l[j][s[i].a]+z[j]+l[j][s[i].b]<mins){
					mins=l[j][s[i].a]+z[j]+l[j][s[i].b];
					mini=j;
				}
			}
			int r1=find(s[i].a);
			int r2=find(s[i].b);
			f[r2]=r1;
			cnt++;
			sum+=mins;
			z[mini]=0;
		}
	}
	cout<<sum;
	return 0;
}
