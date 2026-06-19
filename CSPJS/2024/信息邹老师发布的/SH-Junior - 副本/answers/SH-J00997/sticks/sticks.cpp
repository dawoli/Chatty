#include<bits/stdc++.h>
using namespace std;
int T,n,b[100010];
int a[10]= {6,2,5,5,4,5,6,3,7,6};
struct node {
	int id,num;
} p[10];
bool cmp(node x,node y) {
	if(x.num!=y.num)
		return x.num>y.num;
	return x.id<y.id;
}
bool cmp2(int x,int y){
	return p[x].id<p[y].id;
} 
void work(){
	int cnt=0,z=n%7;
	if(n>=8){
		b[1]=0;
		for(int i=0;i<=9;i++){
			if(p[i].num>=z && ((n-p[i].num)>=2 || (n-p[i].num)==0)){
				if(p[i].id!=0&&p[i].id<p[b[1]].id){
					b[1]=i;
				}
			}	
		}	
		n-=p[b[1]].num;cnt++;
	}
	while(n>0){
		for(int i=0;i<=9;i++)
			if((n-p[i].num)>=2||(n-p[i].num)==0){
				cnt++;b[cnt]=i;n-=p[i].num;
				break;}
	}
	sort(b+1,b+cnt+1,cmp2);
	if(b[1]==1){
		if(cnt==1) b[1]=2;
		else swap(b[1],b[2]);
	}
	for(int i=1;i<=cnt;i++)
		cout<<p[b[i]].id;
	cout<<"\n";
	return;
} 
int main() {
	freopen("sticks1.in","r",stdin);
	freopen("sticks.out","w",stdout);
	for(int i=0; i<=9; i++) {
		p[i].id=i;
		p[i].num=a[i];
	}
	sort(p,p+10,cmp);
	cin>>T;
	while(T--){
		cin>>n;
		if(n==1) {
			printf("-1\n");
			continue;
		}
		if(n%7==0) {
			for(int i=1; i<=n/7; i++)
				printf("8");
			cout<<"\n";
			continue;
		}
		if(n%7==1) {
			printf("10");
			for(int i=1; i<n/7; i++)
				printf("8");
			cout<<"\n";
			continue;
		}
		work();
	}
	return 0;
}
