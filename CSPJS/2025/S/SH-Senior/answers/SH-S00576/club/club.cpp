#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
	int st,nd,rd;
	int lost,nlost;
}a[100005],sum;
int aaa[100005][5];
bool cmp1(Node x,Node y){
	if (x.lost==y.lost){
		return x.nlost>y.nlost;
	}
	return x.lost>y.lost;
}
bool cmp2(Node x,Node y){
	if (x.nlost==y.nlost){
		return x.lost>y.lost;
	}
	return x.nlost>y.nlost;
}
bool cmp3(Node x,Node y){
	return x.st>y.st;
}
ll ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while (T--){
		
		int n;
		cin>>n;
		ans=0;
		
		
		if (n==4){
			for (int i=1;i<=n;i++){
				for (int j=1;j<=3;j++){
					cin>>aaa[i][j];
				}
			}
			int maxmax=0;
			for (int i=1;i<=3;i++){
				for (int j=1;j<=3;j++){
					for (int k=1;k<=3;k++){
						for (int m=1;m<=3;m++){
							int sum1=0,sum2=0,sum3=0;
							if (i==1) sum1++;
							if (i==2) sum2++;
							if (i==3) sum3++;
							if (j==1) sum1++;
							if (j==2) sum2++;
							if (j==3) sum3++;
							if (k==1) sum1++;
							if (k==2) sum2++;
							if (k==3) sum3++;
							if (m==1) sum1++;
							if (m==2) sum2++;
							if (m==3) sum3++;
							if (sum1<=2 && sum2<=2 &&sum3<=2){
								maxmax=max(maxmax,aaa[1][i]+aaa[2][j]+aaa[3][k]+aaa[4][m]);
							}
						}
					}
				}
			}
			cout<<maxmax<<endl;
			continue;
		}
		bool flag=1;
		bool flag2=1;
		for (int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].st,&a[i].nd,&a[i].rd);
			if (a[i].nd!=0 ||a[i].rd!=0) flag=0;
			if (a[i].rd!=0) flag2=0;
			a[i].lost=max(max(a[i].st,a[i].nd),a[i].rd)-min(min(a[i].st,a[i].nd),a[i].rd);
			if (a[i].st!=max(max(a[i].st,a[i].nd),a[i].rd) &&a[i].st!=min(min(a[i].st,a[i].nd),a[i].rd)){
				a[i].nlost=a[i].st-min(min(a[i].st,a[i].nd),a[i].rd);
			}
			else if (a[i].nd!=max(max(a[i].st,a[i].nd),a[i].rd) &&a[i].nd!=min(min(a[i].st,a[i].nd),a[i].rd)){
				a[i].nlost=a[i].nd-min(min(a[i].st,a[i].nd),a[i].rd);
			}
			else if (a[i].rd!=max(max(a[i].st,a[i].nd),a[i].rd) &&a[i].rd!=min(min(a[i].st,a[i].nd),a[i].rd)){
				a[i].nlost=a[i].rd-min(min(a[i].st,a[i].nd),a[i].rd);
			}//找出最大，次大的差; 
			else {
				a[i].nlost=a[i].lost;
			}//st，nd，rd有相同 
		}
		if (flag){
			sort(a+1,a+n+1,cmp3);
			int maxmax=0;
			for (int i=1;i<=n/2;i++){
				maxmax+=a[i].st;
			}
			cout<<maxmax<<endl;
			continue;
		}
		if (n==2){
			int maxmax;
			int maxa=max(a[1].st+a[2].nd,a[1].nd+a[2].st);
			int maxb=max(a[1].st+a[2].rd,a[1].rd+a[2].st);
			int maxc=max(a[1].rd+a[2].nd,a[1].nd+a[2].rd);
			maxmax=max(max(maxa,maxb),maxc);
			cout<<maxmax<<endl;
			continue;
		}
		sort(a+1,a+n+1,cmp1);
		for (int i=1;i<=n;i++){
			int maxn=max(max(a[i].st,a[i].nd),a[i].rd);
			//按优先级排队，从大到小试部门 
			if (a[i].st==maxn){//如果st最大 
				if (sum.st<n/2){//如果能填充 
					ans+=maxn;
					sum.st++;
				}
				else {
					if (a[i].nd==max(a[i].nd,a[i].rd)){//如果nd次大 
						if (sum.nd<n/2){
							ans+=a[i].nd;
							sum.nd++;
						}
						else {//不能填充 
							ans+=a[i].rd;
							sum.rd++;
						}
					}
					else {//rd次大 
						if (sum.rd<n/2){
							ans+=a[i].rd;
							sum.rd++;
						}
						else {//不能填充 
							ans+=a[i].nd;
							sum.nd++;
						}
					}
				}
			}
			else if (a[i].nd==maxn){//nd 
				if (sum.nd<n/2){//如果能填充 
					ans+=maxn;
					sum.nd++;
				}
				else {
					if (a[i].st==max(a[i].st,a[i].rd)){//st 
						if (sum.st<n/2){
							ans+=a[i].st;
							sum.st++;
						}
						else {//不能填充 
							ans+=a[i].rd;
							sum.rd++;
						}
					}
					else {//rd 
						if (sum.rd<n/2){
							ans+=a[i].rd;
							sum.rd++;
						}
						else {//不能填充 
							ans+=a[i].st;
							sum.st++;
						}
					}
				}
			}
			else if (a[i].rd==maxn){//rd 
				if (sum.rd<n/2){//如果能填充 
					ans+=maxn;
					sum.rd++;
				}
				else {
					if (a[i].st==max(a[i].st,a[i].nd)){//st 
						if (sum.st<n/2){
							ans+=a[i].st;
							sum.st++;
						}
						else {//不能填充 
							ans+=a[i].nd;
							sum.nd++;
						}
					}
					else {//nd 
						if (sum.nd<n/2){
							ans+=a[i].nd;
							sum.nd++;
						}
						else {//不能填充 
							ans+=a[i].st;
							sum.st++;
						}
					}
				}
			}
		}//结束 
		ll tmp=ans;
		ans=0;
		sum.st=0;
		sum.rd=0;
		sum.nd=0;
		sort(a+1,a+n+1,cmp2);
		for (int i=1;i<=n;i++){
			int maxn=max(max(a[i].st,a[i].nd),a[i].rd);
			//按优先级排队，从大到小试部门 
			if (a[i].st==maxn){//如果st最大 
				if (sum.st<n/2){//如果能填充 
					ans+=maxn;
					sum.st++;
				}
				else {
					if (a[i].nd==max(a[i].nd,a[i].rd)){//如果nd次大 
						if (sum.nd<n/2){
							ans+=a[i].nd;
							sum.nd++;
						}
						else {//不能填充 
							ans+=a[i].rd;
							sum.rd++;
						}
					}
					else {//rd次大 
						if (sum.rd<n/2){
							ans+=a[i].rd;
							sum.rd++;
						}
						else {//不能填充 
							ans+=a[i].nd;
							sum.nd++;
						}
					}
				}
			}
			else if (a[i].nd==maxn){//nd 
				if (sum.nd<n/2){//如果能填充 
					ans+=maxn;
					sum.nd++;
				}
				else {
					if (a[i].st==max(a[i].st,a[i].rd)){//st 
						if (sum.st<n/2){
							ans+=a[i].st;
							sum.st++;
						}
						else {//不能填充 
							ans+=a[i].rd;
							sum.rd++;
						}
					}
					else {//rd 
						if (sum.rd<n/2){
							ans+=a[i].rd;
							sum.rd++;
						}
						else {//不能填充 
							ans+=a[i].st;
							sum.st++;
						}
					}
				}
			}
			else if (a[i].rd==maxn){//rd 
				if (sum.rd<n/2){//如果能填充 
					ans+=maxn;
					sum.rd++;
				}
				else {
					if (a[i].st==max(a[i].st,a[i].nd)){//st 
						if (sum.st<n/2){
							ans+=a[i].st;
							sum.st++;
						}
						else {//不能填充 
							ans+=a[i].nd;
							sum.nd++;
						}
					}
					else {//nd 
						if (sum.nd<n/2){
							ans+=a[i].nd;
							sum.nd++;
						}
						else {//不能填充 
							ans+=a[i].st;
							sum.st++;
						}
					}
				}
			}
		}//结束 
		cout<<max(ans,tmp)<<'\n'; 
		for (int i=1;i<=n;i++){
			a[i].st=0;
			a[i].nd=0;
			a[i].rd=0;
			a[i].lost=0;
			a[i].nlost=0;
			
		}
		sum.st=0;
		sum.rd=0;
		sum.nd=0;
	}
} 
