#include <bits/stdc++.h>
using namespace std;
int t,n,res,cnt[4];
bool dif=1;
struct mem{
	int a1;
	int a2;
	int a3;
	int am;  //最大值 
	int ami;  //最大值编号 
	int an;  //次大值
	int ani;  //次大值编号 
}a[100005];

bool cmp(mem x,mem y){  // 按最大值从大到小排序 
	return x.am>y.am;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int j=1;j<=t;j++){
		res=0;
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a[i].am=max(a[i].a1,max(a[i].a2,a[i].a3));
				if (a[i].am==a[i].a1){
					a[i].ami=1;
					if (a[i].a2>a[i].a3){
						a[i].an=a[i].a2;
						a[i].ani=2;
					}
					else{
						a[i].an=a[i].a3;
						a[i].ani=3;
					}
				}
				else if (a[i].am==a[i].a2){
					a[i].ami=2;
					if (a[i].a1>a[i].a3){
						a[i].an=a[i].a1;
						a[i].ani=1;
					}
					else{
						a[i].an=a[i].a3;
						a[i].ani=3;
					}
				}
				else if (a[i].am==a[i].a3){
					a[i].ami=3;
					if (a[i].a1>a[i].a2){
						a[i].an=a[i].a1;
						a[i].ani=1;
					}
					else{
						a[i].an=a[i].a2;
						a[i].ani=2;
					}
				} 
		}
		sort(a+1,a+n+1,cmp);
		// 测试点1
		if (n==2){ 
			res+=a[1].am;
			if (a[2].ami!=a[1].ami){
				res+=a[2].am;
			}
			else{
				if (a[2].ami==1){
					res+=max(a[2].a2,a[2].a3);
				}
				if (a[2].ami==2){
					res+=max(a[2].a1,a[2].a3);
				}
				if (a[2].ami==3){
					res+=max(a[2].a1,a[2].a2);
				}
			}
			cout<<res<<endl;
		}
		//特殊性质A 
		else if (a[1].a2==0&&a[2].a2==0&&a[3].a2==0&&a[n].a2==0&&a[1].a3==0&&a[2].a3==0&&a[3].a3==0&&a[n].a3==0){
			for (int i=1;i<=n/2;i++){
				res+=a[i].a1;
			}
			cout<<res<<endl;
		}
		//特殊性质C
		else {
			for (int i=1;i<=n;i++){
				if (cnt[a[i].ami]<n/2){  //最大值可满足 
					res+=a[i].am;
					cnt[a[i].ami]++;
				}
				else {  //次大值可满足
					res+=a[i].an;
					cnt[a[i].ani]++;
				}
			}
			cout<<res<<endl; 
		} 
	}
	return 0;
}
