#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10,inf=1e10;
int T,n,ans;
struct dat{
	int d,e,id;
}a[N];
bool cmp(dat xx,dat yy){
	return xx.d-xx.e>yy.d-yy.e;
}
bool vis[N],out[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//cout<<18961+16178+19722+17976+9953+16322+5444+16615+16441+8769<<endl;
	cin>>T;
	while(T--){
		memset(vis,0,sizeof(vis));
		memset(out,0,sizeof(out));
		cin>>n;
		ans=0;
		for(int i=1,x;i<=n;i++){
			cin>>x>>a[i].d>>a[i].e;
			a[i].id=i;
			a[i].d-=x,a[i].e-=x;
			ans+=x;
		}
		sort(a+1,a+n+1,cmp);
		int cnt=0,totalcnt=0;
		priority_queue<pair<int,int> > pq,tb,ansc;
		for(int i=1;i<=n;i++){
		//	cout<<i<<" "<<a[i].d<<" "<<a[i].e<<endl;
			pair<int,int> now=make_pair(-a[i].d,i);
			cnt+=a[i].d;
			pq.push(now);
			vis[i]=1;
			if(pq.size()>n/2){
				cnt+=pq.top().first;
				vis[pq.top().second]=0;
				tb.push(make_pair(-pq.top().first,pq.top().second));
				pq.pop();
			}
		}
//		for(int i=1;i<=n;i++) cout<<a[i].d<<" "<<a[i].e<<" "<<a[i].id<<endl;
		
	//	cout<<endl;
	//	cout<<endl;
	//	for(int i=1;i<=n;i++) if(vis[i]) cout<<"LI"<<i<<" "<<a[i].d<<endl;
	//	cout<<cnt+ans<<endl;
		totalcnt=cnt;
		for(int i=n;i>=1;i--){
			if(a[i].e<0&&!vis[i]){
				continue;
			}
			pair<int,int> now=make_pair(-a[i].e,i);
			cnt+=a[i].e;
			ansc.push(make_pair(-a[i].e,i));
			if(vis[i]){
				cnt-=a[i].d;
				while(!tb.empty()&&tb.top().second>=i) tb.pop();
				if(!tb.empty()&&tb.top().first>0){
					cnt+=tb.top().first;
				//	cout<<tb.top().first<<" "<<tb.top().second<<endl;
					vis[tb.top().second]=1;
					pq.push(make_pair(-tb.top().first,tb.top().second));
					tb.pop();
				}
			}
			else{
				while(!pq.empty()&&pq.top().second>=i) pq.pop();
				if(!pq.empty()&&pq.top().first>0){
					cnt+=pq.top().first;
					vis[pq.top().second]=0;
					tb.push(make_pair(-pq.top().first,pq.top().second));
					pq.pop();
				} 
			}
			if(ansc.size()>n/2){
				cnt+=ansc.top().first;
				ansc.pop();
				tb.push(make_pair(-ansc.top().first,ansc.top().second));
				while(!tb.empty()&&tb.top().second>=i) tb.pop();
				if(!tb.empty()&&tb.top().first>0){
					cnt+=tb.top().first;
					vis[tb.top().second]=1;
					pq.push(make_pair(-tb.top().first,tb.top().second));
					tb.pop();
				}
			}
//			if(i==4){
//				priority_queue<pair<int,int> > lll=ansc;
//				while(!lll.empty()){
//					cout<<a[lll.top().second].id<<" ";
//					lll.pop();
//				}
//				cout<<endl;
//				lll=pq;
//				while(!lll.empty()){
//					cout<<a[lll.top().second].id<<" ";
//					lll.pop();
//				}
//				cout<<endl;
//			}
			totalcnt=max(totalcnt,cnt);
		}
		cout<<ans+totalcnt<<endl;
	}
	return 0;
}
/*
T1 理清思路
我们先假定一半a一半b
问题变为考虑c对a,b的影响
1.a->c
即为一个本来选A的改成c了 此时候A不足一半
可以考虑 ：c->a 或 b->a

探究 c->b b->a a->c 存不存在  不存在 前c不选 后c不可能上 不如换 
cnow bnow anow
anowid>bnowid>cnowid



2.b->c
a->b  


c->a a->b b->c
a->b b->c
b->c
1
4
0 -10 -11
0 -7 -2
0 -6 -4
0 -5 -4


1
30
6090 4971 4101
14495 19657 10011
6294 14948 17496
3266 18897 6963
3129 14412 12639
5331 7102 7590
12533 15635 16270
2339 16892 11211
6980 3113 19980
16859 13322 9404
16742 1573 8946
1285 5253 2697
18072 16412 5595
15870 17311 7711
19194 4644 11192
1306 6558 10317
11128 16814 5947
1603 6202 15251
4014 5797 2498
1557 4235 12431
1561 16149 16433
9399 1760 809
13383 18379 10169
7679 4131 17310
2900 8148 13627
14783 19510 17642
19717 4666 6335
9868 5451 19561
11196 1774 11436
10753 10148 6994 




18961 16178 19722 17976 9953
16322 5444 16615
16441 8769


18961 16178 19722 17976 9953
15344 10557 13424
8769 16441


18961+16178+19722+17976+9953+15344+10557+13424+8769+16441


18961+16178+19722+17976+9953+16322+5444+16615+16441+8769




1
7
8018 23091 20019
21883 25146 12008
8203 30536 8467
18145 5852 8679
4668 17803 13482
19039 9591 12087
12752 14248 30117

18145+ 19039 + 25146+30536+17803 + 20019+30117
*/
