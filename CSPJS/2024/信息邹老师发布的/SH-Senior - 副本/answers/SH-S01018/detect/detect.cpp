#include<bits/stdc++.h>
using namespace std;
int n,m,L,V,d[100005],v[100005],a[100005];
int p[100005],top=0;
int fast(){
	int n=0,neg=1;
	char c;
	scanf("%c",&c);
	while(c<'0'||c>'9'){
		if(c=='-') neg=-1;
		scanf("%c",&c);
	}
	while('0'<=c&&c<='9'){
		n=n*10+c-'0';
		scanf("%c",&c);
	}
	return neg*n;
}
struct lr{
	int left,right;
}q[100005];
bool cmp(const lr&a, const lr&b){
	return a.right<b.right;
}
bool check(int p,int d,int v,int a){
	if (p<d) return 0;
	if (p==d&&v>V) return 1;
	if (p==d) return 0;
	if (v*v+2*a*(p-d)>V*V)return 1;
	return 0;
}
int upper_bound(double x,int* arr,int n){
	//在a与b中寻找第一个p>=x
	//*a<x , *b>=x
	int a=1,b=n;
	int mid=(a+b)/2;
	while(a<b){
		if(arr[mid]>=x) b=mid;
		else a=mid+1;
		mid=(a+b)/2; 
	}
	//*玄学输出*/
	if(arr[a]>=x&&arr[a-1]<x)return a;
	if(arr[b]>=x&&arr[b-1]<x)return b;
	return mid;
}
//int get_ans2(int t)
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	T=fast();
	//printf("%d",T);
	while(T--){
		top=0;
		//scanf("%d%d%d%d",&n,&m,&L,&V);
		n=fast();m=fast();L=fast();V=fast();
		int ans1=0,ans2=m;
		for(int i=1;i<=n;i++)
			d[i]=fast(),v[i]=fast(),a[i]=fast();
		bool always_p=1;bool always_n=1;
		for(int i=1;i<=m;i++)
			p[i]=fast();
		for(int i=1;i<=n;i++)
			if(a[i]>0) always_n=0;
			else if(a[i]<0) always_p=0;
		double min_ai=0;
		for(int i=1;i<=n;i++){
			//寻找他们经过的第一个测速仪
			int start=upper_bound(d[i],p,n);
			bool f=1;
			if(a[i]<=0&&check(p[start],d[i],v[i],a[i])){
				if(!always_p){
					q[++top].left=start;
					double r;
					r=(V*V-v[i]*v[i])/2.0/a[i];
					q[top].right=upper_bound(r,p,n);
					if(p[q[top].right-1]>=r) q[top].right--;
				}
				ans1++;
			}
			else if(a[i]>=0&&check(p[m],d[i],v[i],a[i])){
				ans1++;
				if (!always_p)
				min_ai=max(min_ai,double(V*V-v[i]*v[i])/2/a[i]);
			}
		}
		if (!always_p){
			int g=upper_bound(min_ai,p,n);
			sort(q+1,q+top+1,cmp);
			int last=0;
			for(int i=1;i<=top;i++){
				//if(q[i].right>=m) break;
				if(q[i].left>last){
					ans2--;//必须保留
					last=q[i].right; 
				}
			}
		}
		else ans2-=(ans1==0?0:1);
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
