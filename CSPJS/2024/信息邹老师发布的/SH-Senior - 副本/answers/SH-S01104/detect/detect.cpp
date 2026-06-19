#include<bits/stdc++.h>
using namespace std;
int st[100005],ed[100005],p[100005],n,m,L,V;
bool ok[100005];
struct car{
	int stt;
	int end;
}q[100005];
int efst(int x){
	int a=1,b=m;
	while(b-a>1){
		//cout<<"@"<<a<<" "<<b<<endl;
		int mid=(a+b)/2;
		//cout<<mid<<" "<<p[mid]<<" "<<x<<endl;
		if(p[mid]==x){
			a=mid,b=mid;
			break;
		}
		else if(p[mid]<x){
			a=mid+1;
		}
		else{
			b=mid;
		}
	}
	if(p[a]>=x)	return a;
	if(p[b]>=x) return b;
	return -1;
}
int efed(int x){
	int a=1,b=m;
	while(b-a>1){
		//cout<<"&"<<a<<" "<<b<<endl;
		int mid=(a+b)/2;
		if(p[mid]==x){
			a=mid,b=mid;
			break;
		}
		else if(p[mid]<x){
			a=mid;
		}
		else{
			b=mid-1;
		}
	}
	if(p[b]<=x)	return b;
	if(p[a]<=x) return a;
	return -1;
}
bool cmp(car a,car b){
	return a.stt<b.stt;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	for(int TT=1;TT<=T;TT++){
		memset(st,0,sizeof(st));
		memset(ed,0,sizeof(ed));
		memset(p,0,sizeof(p));
		memset(ok,0,sizeof(ok));
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			int d,v,a;
			cin>>d>>v>>a;
			if(a==0){
				if(v>V){
					st[i]=d;
					ed[i]=L;
				}
				else{
					st[i]=-1;
					ed[i]=-1;
				}
			}
			if(a>0){
				if(v>V){
					st[i]=d;
					ed[i]=L;
				}
				else{
					int s=(V*V-v*v)/(2*a)+1;
					st[i]=d+s;
					ed[i]=L;
				}
			}
			if(a<0){
				if(v>V){
					int s=(V*V-v*v+1)/(2*a);
					st[i]=d;
					ed[i]=d+s;
				}
				else{
					st[i]=-1;
					ed[i]=-1;
				}
			}
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		for(int i=1;i<=n;i++){
			//cout<<"!"<<i<<endl;
			//cout<<"@"<<i<<" "<<st[i]<<" "<<ed[i]<<endl;
			st[i]=efst(st[i]);
			ed[i]=efed(ed[i]);
			//cout<<"!"<<i<<" "<<st[i]<<" "<<ed[i]<<endl;
		}
		//cout<<"!";
		int cnt=0;
		for(int i=1;i<=n;i++){
			if((st[i]!=-1) && (ed[i]!=-1) && (st[i]<=ed[i])){
				cnt++;
				//cout<<"!"<<i<<" "<<st[i]<<" "<<ed[i]<<endl;
				q[cnt].stt=st[i];
				q[cnt].end=ed[i];
				//cout<<i<<" "<<q[i].stt<<" "<<q[i].end<<endl;
			}
		}
		//for(int i=0;i<=cnt;i++){
			//cout<<i<<" "<<q[i].stt<<" "<<q[i].end<<endl;
		//}
		cout<<cnt<<" ";
		sort(q+1,q+cnt+1,cmp);
		q[0].stt=0;
		q[0].end=0;
		//for(int i=0;i<=cnt;i++){
		//	cout<<"!"<<i<<" "<<q[i].stt<<" "<<q[i].end<<endl;
		//}
		int ans=0;
		for(int i=1;i<=cnt;i++){
			if(q[i-1].end<q[i].stt){
				ans++;
			}
			else{
				q[i].end=min(q[i-1].end,q[i].end);
			}
			//cout<<"$"<<i<<" "<<ans<<" "<<q[i].stt<<" "<<q[i].end<<endl;
		}
		cout<<m-ans<<endl;
	}
	return 0;
}

