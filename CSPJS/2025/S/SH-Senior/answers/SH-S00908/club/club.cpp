#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
struct node{
	int score,num;
	int cidazhi;
};
bool cmp(node b1,node b2){
	return b1.score>b2.score;
}
void solve(){
	int n,ans=0;
	int people[4]={0};//已入职人员 
	node rec[maxn];//存储最大与次大值
	bool cha[maxn]={0};
	cin>>n;
	int celling=n/2;
	for(int i=1;i<=n;i++){
		node a[4];//a是输入变量 
		a[1].num=1;a[2].num=2;a[3].num=3;
		for(int j=1;j<=3;j++){
			cin>>a[j].score;
		}
		sort(a+1,a+n+1,cmp);//找出最大和次大 
		
		rec[i].score=a[1].score;
		rec[i].num=a[1].num;
		rec[i].cidazhi=a[2].score;//存储 
//		cout<<"最大："<<rec[i].score<<" "; 
//		cout<<"次大"<<rec[i].cidazhi<<endl;
	}
	sort(rec+1,rec+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(people[rec[i].num]<celling){//如果有空间，直接加 
			ans+=rec[i].score;
			people[rec[i].num]++;
//			cout<<rec[i].num<<"有空间，压入"<<rec[i].score<<endl;
		}
		else{//没空间，加次大值 
			bool we=0;
			for(int j=1;j<i;j++){
				if(rec[j].cidazhi+rec[i].score>rec[j].score&&!cha[j]&&rec[i].num==rec[j].num){
					cha[j]=1;we=1;
					ans-=rec[j].score;
					ans+=(rec[j].cidazhi+rec[i].score);
					break;
				}
			}
			if(!we){
				ans+=rec[i].cidazhi;
//				cout<<rec[i].num<<"无空间，压入"<<rec[i].cidazhi<<endl;
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		solve();
	}
	return 0;
}
