#include<bits/stdc++.h>
using namespace std;
int n,ans;
struct node{
	int r;
	bool use,out;
}a[100005];
bool check(){
	for(int i=0;i<n;i++){
		if(!a[i].use && !a[i].out) return 1;
	}
	return 0;
}
bool cmp(node x,node y){
	return x.r<y.r;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n,cmp);
	while(check()){
		int pos1=0,pos2=1;
		while(a[pos1].out && pos1<n) pos1++;
		pos2=pos1+1;
		while((a[pos2].r<=a[pos1].r || a[pos2].out || a[pos2].use) && pos2<n)pos2++;
		if(pos2<n){
			a[pos1].out=1;
			a[pos2].use=1;
		}
		else{
			pos2=0;
			while((a[pos2].out || a[pos2].use) && pos2<n || pos2==pos1) pos2++;
			if(pos2<n)a[pos2].use=1;
			else{
				pos2=pos1;
				while((a[pos1].out || pos2==pos1) && pos1<n) pos1++;
				a[pos2].use=1;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(!a[i].out) ans++;
	}
	printf("%d",ans);
	return 0;
}
