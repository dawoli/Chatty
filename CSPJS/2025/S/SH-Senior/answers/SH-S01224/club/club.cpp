#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int a,b,c,d;
}s[N];
struct tmp{
	int id,val;
}t[5];
bool cmp(tmp l,tmp r){
	return l.val>r.val;
}
node get(int a,int b,int c){
	t[1].id=1;t[1].val=a;
	t[2].id=2;t[2].val=b;
	t[3].id=3;t[3].val=c;
	sort(t+1,t+4,cmp);
	node ret;
	ret.a=t[1].val;
	ret.b=t[1].id;
	ret.c=t[2].val;
	ret.d=t[2].id;
	return ret;
}
int cnt[5];
int can[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int mx=0;
		int mxi=0;
		int n;
		cin>>n;
		cnt[1]=cnt[2]=cnt[3]=0;
		int tot=0;
		int idx=0;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			s[i]=get(a,b,c);
			cnt[s[i].b]++;
			tot+=s[i].a;
			if(cnt[s[i].b]>mx){
				mx=cnt[s[i].b];
				mxi=s[i].b;
			}
		}
		if(mx<=n/2){
			cout<<tot;
		}else{
			for(int i=1;i<=n;i++){
				if(s[i].b==mxi){
					idx++;
					can[idx]=s[i].a-s[i].c;
				}
			}
			sort(can+1,can+1+idx);
			for(int i=1;i<=mx-n/2;i++){
				tot-=can[i];
			}
			cout<<tot;
		}
		cout<<'\n';
	}
	return 0;
} 
