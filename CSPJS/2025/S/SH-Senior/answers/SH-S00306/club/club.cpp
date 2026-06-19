#include<bits/stdc++.h>
using namespace std;
int T,n,ans,tans,joined[4];
struct club{
	int a1,a2,a3;
} a[100000];
int middle(int a,int b,int c){
	if(c>a&&a>b||b>a&&a>c) return a;
	if(a>b&&b>c||c>b&&b>a) return b;
	if(a>c&&c>b||b>c&&c>a) return c;
}
int maxp(int a,int b,int c){
	if(a>b&&a>c) return 1;
	if(b>a&&b>c) return 2;
	if(c>a&&c>b) return 3;
}
int middlep(int a,int b,int c){
	if(c>a&&a>b||b>a&&a>c) return 1;
	if(a>b&&b>c||c>b&&b>a) return 2;
	if(a>c&&c>b||b>c&&c>a) return 3;
}
int minp(int a,int b,int c){
	if(a<b&&a<c) return 1;
	if(b<a&&b<c) return 2;
	if(c<a&&c<b) return 3;
}
bool cmp(club x,club y){
	if(max(x.a1,max(x.a2,x.a3))>max(y.a1,max(y.a2,y.a3))) return max(x.a1,max(x.a2,x.a3))>max(y.a1,max(y.a2,y.a3));
	if(middle(x.a1,x.a2,x.a3)>middle(y.a1,y.a2,y.a3)) return middle(x.a1,x.a2,x.a3)>middle(y.a1,y.a2,y.a3);
	if(min(x.a1,min(x.a2,x.a3))>min(y.a1,min(y.a2,y.a3))) return min(x.a1,min(x.a2,x.a3))>min(y.a1,min(y.a2,y.a3));
}
void dfs(int i){
	if(joined[maxp(a[i].a1,a[i].a2,a[i].a3)]<n/2){
		joined[maxp(a[i].a1,a[i].a2,a[i].a3)]++;
		tans+=max(a[i].a1,max(a[i].a2,a[i].a3));
		if(i<n) dfs(i+1);
		else ans=max(ans,tans);
		joined[maxp(a[i].a1,a[i].a2,a[i].a3)]--;
		tans-=max(a[i].a1,max(a[i].a2,a[i].a3));
	}
	if(joined[middlep(a[i].a1,a[i].a2,a[i].a3)]<n/2){
		joined[middlep(a[i].a1,a[i].a2,a[i].a3)]++;
		tans+=middle(a[i].a1,a[i].a2,a[i].a3);
		if(i<n) dfs(i+1);
		else ans=max(ans,tans);
		joined[middlep(a[i].a1,a[i].a2,a[i].a3)]--;
		tans-=middle(a[i].a1,a[i].a2,a[i].a3);
	}
	if(joined[minp(a[i].a1,a[i].a2,a[i].a3)]<n/2){
		joined[min(a[i].a1,min(a[i].a2,a[i].a3))]++;
		tans+=min(a[i].a1,min(a[i].a2,a[i].a3));
		if(i<n) dfs(i+1);
		else ans=max(ans,tans);
		joined[min(a[i].a1,min(a[i].a2,a[i].a3))]--;
		tans-=min(a[i].a1,min(a[i].a2,a[i].a3));
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i].a1>>a[i].a2>>a[i].a3;
		sort(a,a+n,cmp);
		memset(joined,0,sizeof(joined));
		ans=0;
		tans=0;
		dfs(0);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
