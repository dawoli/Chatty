#include<bits/stdc++.h>
using namespace std;
int p[100005][2];
struct Node{
	int v,num;
}a[100005],b[100005];
bool cmp(Node x,Node y){
	return x.v>y.v;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int x;
			cin>>p[i][0]>>p[i][1]>>x;
			if(p[i][0]>p[i][1]){
				a[++a[0].v].v=p[i][0];
				a[a[0].v].num=i;
			}else{
				b[++b[0].v].v=p[i][1];
				b[b[0].v].num=i;
			}
		}
		if(a[0].v>n/2){
			sort(a+1,a+a[0].v+1,cmp);
			for(int i=1;i<=n/2;i++){
				sum+=a[i].v;
			}
			for(int i=n/2+1;i<=a[0].v;i++){
				sum+=p[a[i].num][1];
			}
			for(int i=1;i<=b[0].v;i++){
				sum+=b[i].v;
			}
		}else if(b[0].v>n/2){
			sort(b+1,b+b[0].v+1,cmp);
			for(int i=1;i<=n/2;i++){
				sum+=b[i].v;
			}
			for(int i=n/2+1;i<=b[0].v;i++){
				sum+=p[b[i].num][0];
			}
			for(int i=1;i<=a[0].v;i++){
				sum+=a[i].v;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
