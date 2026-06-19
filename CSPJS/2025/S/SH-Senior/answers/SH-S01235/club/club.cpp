
#include<bits/stdc++.h>
using namespace std;
int n,t,ansa,ansb,ansc,aa,bb,cc;
struct node{
	int a1,a2,a3;
}a[100005];
bool cmpa(node x, node y){
	return x.a1>y.a1;
}
bool cmpb(node x, node y){
	return x.a2>y.a2;
}
bool cmpc(node x, node y){
	return x.a3>y.a3;
}
int main(){
	freopen("club.in.txt","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		ansa = 0;ansb = 0;ansc = 0;aa= 0;bb=0;cc=0;
		cin >> n;
		int maxx = n/2;
		for(int i = 1; i <= n; i++)cin >> a[i].a1>>a[i].a2>>a[i].a3;
		sort(a+1,a+n+1,cmpa);
		for(int i = 1; i <=n; i++){
			if(a[i].a2>a[i].a1||a[i].a3>a[i].a1)continue;
			if(a[i].a1==-1)break;
			ansa+=a[i].a1;
			aa++;
			a[i].a1 = -1;
			a[i].a2 = -1;
			a[i].a3 = -1;
			if(aa>=maxx)break;
		}
		
		sort(a+1,a+n+1,cmpb);
		for(int i = 1; i <=n; i++){
			if(a[i].a3>a[i].a2)continue;
			if(a[i].a2==-1)break;
			ansb+=a[i].a2;
			a[i].a3 = -1;
			a[i].a2 = -1;
			a[i].a1 = -1;
			bb++;
			if(bb>=maxx)break;
		}
		
		sort(a+1,a+n+1,cmpc);
		for(int i = 1; i <=n; i++){
			
			ansc+=a[i].a3;
			a[i].a3 = -1;
			a[i].a2 = -1;
			a[i].a1 = -1;
			cc++;
			if(cc+bb+aa>=n)break;
		}
		cout << ansa+ansb+ansc<<endl;
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3
4
4 2 1 (1 4
3 2 4 (3 4
5 3 4 (1 5
3 5 1 (2 3
4
0 1 0 (3 0
0 1 0 (3 0
0 2 0 (2 2
0 2 0 (2 2
2
10 9 8 (2 9
4 0 0  (1 4
out ::
18
4
13
*/
