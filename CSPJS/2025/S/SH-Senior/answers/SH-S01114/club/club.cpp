//#include<bits/stdc++.h>
//using namespace std;
//struct node{
//	int a,b,c;
//}p[100005];
//struct no{
//	int p1,p2,p3;
//	long long su;
//	int ip;
//};
//bool cmp1(node x,node y){
//	return  x.a > y.a;
//}
//long long sum = 0,n;
////int is[100005];
//void solve(){
//	sum = 0;
//	for(int i=1;i<=100004;i++){
//		p[i].a=p[i].b=p[i].c=0;
//	}
//	cin>>n;
//	int f = 1;
//	for(int i=1;i<=n;i++){
//		cin>>p[i].a>>p[i].b>>p[i].c;
//		if(p[i].b != 0 && p[i].c != 0){
//			f = 0;
//		}
//	}
//	
//	if(f){
//		sort(p+1,p+n+1,cmp1);
//		for(int i=1;i<=2/n;i++){
//			sum+= p[i].a;
//		}
//		cout<<sum<<endl;
//		return ;
//	}
//	queue<no>q;
//	q.push({0,0,0,0,0});
//	while(q.size()){
//		no r = q.front();
//		q.pop();
//		if(r.ip >n){
//			sum = max(sum,r.su);
//			continue;
//		}
//		r.ip++;
//		if(r.p1<n/2){
//			q.push({r.p1++,r.p2,r.p3,r.su+p[r.ip].a,r.ip});
//		}
//		if(r.p2<n/2){
//			q.push({r.p1,r.p2++,r.p3,r.su+p[r.ip].b,r.ip});
//		}
//		if(r.p3<n/2){
//			q.push({r.p1,r.p2,r.p3++,r.su+p[r.ip].c,r.ip});
//		}
//	}
//	cout<<sum<<endl;
//}
//int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
//	int q;
//	cin>>q;
//	while(q--){
//		solve();
//	}
//	fclose(stdin);
//	fclose(stdout);
//	return 0;
//}
////3
////4
////4 2 1
////3 2 4
////5 3 4
////3 5 1
////4
////0 1 0
////0 1 0
////0 2 0
////0 2 0
////2
////10 9 8
////4 0 0
//#include<bits/stdc++.h>
//using namespace std;
//struct node{
//	int a,b,c,id,su;
//}p[100005];
//bool cmp(node x,node y){
//	return x.su>y.su;
//}
//bool is[100005];
//int p1,p2,p3;
//long long sum;
//void solve(){
//	int n;
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>p[i].a>>p[i].b>>p[i].c;
//		p[i].id = i;
//		p[i].su = p[i].a+p[i].b+p[i].c;
//	}
//	p1=p2=p3=sum=0;
//	sort(p+1,p+n+1,cmp);
//	for(int i=1;i<=n;i++){
//		int u = p[i].a;
//		int v = p[i].b;
//		int w = p[i].c;
//		if(u>v && u>w && p1<n/2){
//			sum +=u;
//			p1++;
//		}else if(v>u && v>w && p2<n/2){
//			sum +=v;
//			p2++;
//		}else if(w>u && w>v && p3<n/2){
//			sum +=w;
//			p3++;
//		}
//	}
//	cout<<sum<<endl;
//}
//int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
//	int q;
//	cin>>q;
//	while(q--){
//		solve();
//	}
//	fclose(stdin);
//	fclose(stdout);
//}
#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,id,su=0;
}p[100005];
bool cmp(node x,node y){
	return max({abs(x.a-x.b),abs(x.a-x.c),abs(x.c-x.b)}) > max({abs(y.a-y.b),abs(y.a-y.c),abs(y.c-y.b)});
}
int p1,p2,p3;
long long sum;
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].a>>p[i].b>>p[i].c;
		p[i].id = i;
		p[i].su = p[i].a+p[i].b+p[i].c;
	}
	p1=p2=p3=sum=0;
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++){
		int u = p[i].a;
		int v = p[i].b;
		int w = p[i].c;
		int f = 0;
		int o = max({u,v,w});
		int k = min({u,v,w});
		if(o==u && p1<n/2){
			sum +=u;
			p1++;
			f=1;
		}
		if(o==v&& p2<n/2){
			sum +=v;
			p2++;
			f=2;
		}
		if(o==w && p3<n/2){
			sum +=w;
			p3++;
			f=3;
		}
		if(f)continue;
		if(o!=u && k!=u && p1<n/2){
			sum +=u;
			p1++;
			f=1;
		}
		if(o!=v && k!=v && p2<n/2){
			sum +=v;
			p2++;
			f=2;
		}
		if(o!=w && k!=w && p3<n/2){
			sum +=w;
			p3++;
			f=3;
		}
		if(f)continue;
		if(k==u && p1<n/2){
			sum +=u;
			p1++;
			f=1;
		}
		if(k==v&& p2<n/2){
			sum +=v;
			p2++;
			f=2;
		}
		if(k==w && p3<n/2){
			sum +=w;
			p3++;
			f=3;
		}
	}
	cout<<sum<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int q;
	cin>>q;
	while(q--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	
}
