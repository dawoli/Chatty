#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-'0');ch=getchar();}
	return x*w;
}
int n,a[100010];
priority_queue<int,vector<int>,greater<int> > q;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	q.push(a[1]);
	for(int i=2;i<=n;i++){
		if(q.empty()){
			q.push(a[i]);continue; 
		} 
		if(q.top()<a[i]){
			q.pop();
//			cout<<i<<endl;
			q.push(a[i]); 
		}else q.push(a[i]); 
	}
	printf("%d\n",q.size());
	return 0;
} 
