#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e7+5;
int n,ans;
struct Node{
	int a;
	bool st;
}a[N]; 
bool cmp(Node a,Node b){
	return a.a<b.a;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	ans=n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i].a);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[j].a>a[i].a && !a[j].st){
				ans--;
				a[j].st=true;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
