#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,r[100010],cnt[100010],ans,minpos=0,rcnt=0;//r存储武力值、cnt做计数器,minpos记录存活怪物最小生命对应r下标 
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	ans=n;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		if(cnt[x]==0) r[rcnt++]=x;
		++cnt[x];
	}
	sort(r,r+rcnt);
	for(int i=1;i<rcnt;++i){
		if(cnt[r[minpos]]>cnt[r[i]]){//没杀干净 
			ans-=cnt[r[i]];
			cnt[r[minpos]]-=cnt[r[i]];
			continue;
		}
		int killcnt=0;
		while(killcnt<cnt[r[i]]&&minpos!=i){
			//开始轮换杀小的
			if(cnt[r[minpos]]>(cnt[r[i]]-killcnt)){//没杀干净 
				ans-=(cnt[r[i]]-killcnt);
				cnt[r[minpos]]-=(cnt[r[i]]-killcnt);
				continue;
			}
			killcnt+=cnt[r[minpos]];
			ans-=cnt[r[minpos]];
			++minpos;//全灭了 
		}
	}
	cout<<ans<<endl;
	return 0;
}
