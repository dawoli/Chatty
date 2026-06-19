#include<bits/stdc++.h>
using namespace std;
int t,n;
struct s{
	long long x,y,z,num;
}a[100010];
bool cmp(s p,s q){
	return p.x>q.x;
}
bool cmp1(s p,s q){
	if(p.x!=q.x) return p.x>q.x;
	else if(p.y!=q.y)return p.y>q.y;
	else return p.z>q.z;
}
bool cmp2(s p,s q){
	if(p.y!=q.y) return p.y>q.y;
	else if(p.x!=q.x)return p.x>q.x;
	else return p.z>q.z;
}
bool cmp3(s p,s q){
	if(p.z!=q.z) return p.z>q.z;
	else if(p.y!=q.y)return p.y<q.y;
	else return p.x<q.x;
}
bool cmp11(s p,s q){
	if(p.x!=q.x) return p.x<q.x;
	else if(p.y!=q.y)return p.y<q.y;
	else return p.z<q.z;
}
bool cmp12(s p,s q){
	if(p.y!=q.y) return p.y<q.y;
	else if(p.x!=q.x)return p.x<q.x;
	else return p.z<q.z;
}
bool cmp13(s p,s q){
	if(p.z!=q.z) return p.z<q.z;
	else if(p.y!=q.y)return p.y<q.y;
	else return p.x<q.x;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	scanf("%d",&t);
	for(int k=1;k<=t;k++){
		scanf("%d",&n);
		if(n>10){
		bool checka=1,checkb=1;
		long long maxn=n/2,cnt1=0,cnt2=0,cnt3=0;
		long long sum=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i].x);
			scanf("%lld",&a[i].y);
			scanf("%lld",&a[i].z);
			a[i].num=i;
			if(a[i].y!=0)checka=0;
			if(a[i].z!=0)checkb=0;
		}
		if(checka&&checkb){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=maxn;i++){
				sum+=a[i].x;
			}
			printf("%lld\n",sum);
		}
		else{
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++){
			if((a[i].x>a[i].y&&a[i].x>a[i].z)||(a[i].x==a[i].y&&a[i].x>a[i].z&&cnt1<=cnt2)||(a[i].x==a[i].z&&a[i].x>a[i].y&&cnt1<=cnt3)||(a[i].x==a[i].y&&a[i].x==a[i].z&&cnt1<=cnt2&&cnt1<=cnt3)){
				if(cnt1<maxn){
					cnt1++;
					sum+=a[i].x;
				}
				else if(a[i].y>=a[i].z&&cnt2<maxn){
					cnt2++;
					sum+=a[i].y;
				}
				else {
					cnt3++;sum+=a[i].z;
				}
			}
			else if((a[i].y>a[i].x&&a[i].y>a[i].z)||(a[i].y==a[i].x&&a[i].y>a[i].z&&cnt1>cnt2)||(a[i].y==a[i].z&&a[i].y>a[i].x&&cnt2<cnt3)||(a[i].x==a[i].y&&a[i].x==a[i].z&&cnt2<cnt1&&cnt2<cnt3)){
				if(cnt2<maxn){
					cnt2++;
					sum+=a[i].y;
				}
				else if(a[i].x>=a[i].z&&cnt1<maxn){
					cnt1++;
					sum+=a[i].x;
				}
				else {
					cnt3++;sum+=a[i].z;
				}
			}
			else if((a[i].z>a[i].x&&a[i].z>a[i].y)||(a[i].z==a[i].x&&a[i].z>a[i].y&&cnt3<cnt1)||(a[i].z==a[i].y&&a[i].z>a[i].x&&cnt2>cnt3)||(a[i].x==a[i].y&&a[i].x==a[i].z&&cnt3<cnt1&&cnt3<cnt2)){
				if(cnt3<maxn){
					cnt3++;
					sum+=a[i].z;
				}
				else if(a[i].x>=a[i].y&&cnt1<maxn){
					cnt1++;
					sum+=a[i].x;
				}
				else {
					cnt2++;sum+=a[i].y;
				}
			}
		}
		long long sum1=sum; 
		sum=0,cnt1=0,cnt2=0,cnt3=0;
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++){
			if((a[i].x>a[i].y&&a[i].x>a[i].z)||(a[i].x==a[i].y&&a[i].x>a[i].z&&cnt1<=cnt2)||(a[i].x==a[i].z&&a[i].x>a[i].y&&cnt1<=cnt3)||(a[i].x==a[i].y&&a[i].x==a[i].z&&cnt1<=cnt2&&cnt1<=cnt3)){
				if(cnt1<maxn){
					cnt1++;
					sum+=a[i].x;
				}
				else if(a[i].y>=a[i].z&&cnt2<maxn){
					cnt2++;
					sum+=a[i].y;
				}
				else {
					cnt3++;sum+=a[i].z;
				}
			}
			else if((a[i].y>a[i].x&&a[i].y>a[i].z)||(a[i].y==a[i].x&&a[i].y>a[i].z&&cnt1>cnt2)||(a[i].y==a[i].z&&a[i].y>a[i].x&&cnt2<cnt3)||(a[i].x==a[i].y&&a[i].x==a[i].z&&cnt2<cnt1&&cnt2<cnt3)){
				if(cnt2<maxn){
					cnt2++;
					sum+=a[i].y;
				}
				else if(a[i].x>=a[i].z&&cnt1<maxn){
					cnt1++;
					sum+=a[i].x;
				}
				else {
					cnt3++;sum+=a[i].z;
				}
			}
			else if((a[i].z>a[i].x&&a[i].z>a[i].y)||(a[i].z==a[i].x&&a[i].z>a[i].y&&cnt3<cnt1)||(a[i].z==a[i].y&&a[i].z>a[i].x&&cnt2>cnt3)||(a[i].x==a[i].y&&a[i].x==a[i].z&&cnt3<cnt1&&cnt3<cnt2)){
				if(cnt3<maxn){
					cnt3++;
					sum+=a[i].z;
				}
				else if(a[i].x>=a[i].y&&cnt1<maxn){
					cnt1++;
					sum+=a[i].x;
				}
				else {
					cnt2++;sum+=a[i].y;
				}
			}
		}
		long long sum2=sum; 
		sum=0,cnt1=0,cnt2=0,cnt3=0;
		sort(a+1,a+n+1,cmp3);
		for(int i=1;i<=n;i++){
			if((a[i].x>a[i].y&&a[i].x>a[i].z)||(a[i].x==a[i].y&&a[i].x>a[i].z&&cnt1<=cnt2)||(a[i].x==a[i].z&&a[i].x>a[i].y&&cnt1<=cnt3)||(a[i].x==a[i].y&&a[i].x==a[i].z&&cnt1<=cnt2&&cnt1<=cnt3)){
				if(cnt1<maxn){
					cnt1++;
					sum+=a[i].x;
				}
				else if(a[i].y>=a[i].z&&cnt2<maxn){
					cnt2++;
					sum+=a[i].y;
				}
				else {
					cnt3++;sum+=a[i].z;
				}
			}
			else if((a[i].y>a[i].x&&a[i].y>a[i].z)||(a[i].y==a[i].x&&a[i].y>a[i].z&&cnt1>cnt2)||(a[i].y==a[i].z&&a[i].y>a[i].x&&cnt2<cnt3)||(a[i].x==a[i].y&&a[i].x==a[i].z&&cnt2<cnt1&&cnt2<cnt3)){
				if(cnt2<maxn){
					cnt2++;
					sum+=a[i].y;
				}
				else if(a[i].x>=a[i].z&&cnt1<maxn){
					cnt1++;
					sum+=a[i].x;
				}
				else {
					cnt3++;sum+=a[i].z;
				}
			}
			else if((a[i].z>a[i].x&&a[i].z>a[i].y)||(a[i].z==a[i].x&&a[i].z>a[i].y&&cnt3<cnt1)||(a[i].z==a[i].y&&a[i].z>a[i].x&&cnt2>cnt3)||(a[i].x==a[i].y&&a[i].x==a[i].z&&cnt3<cnt1&&cnt3<cnt2)){
				if(cnt3<maxn){
					cnt3++;
					sum+=a[i].z;
				}
				else if(a[i].x>=a[i].y&&cnt1<maxn){
					cnt1++;
					sum+=a[i].x;
				}
				else {
					cnt2++;sum+=a[i].y;
				}
			}
		}
		int sumx=max(sum,max(sum1,sum2));
		sum=0,cnt1=0,cnt2=0,cnt3=0;
		sort(a+1,a+n+1,cmp11);
		for(int i=1;i<=n;i++){
			if((a[i].x>a[i].y&&a[i].x>a[i].z)||(a[i].x==a[i].y&&a[i].x>a[i].z&&cnt1<=cnt2)||(a[i].x==a[i].z&&a[i].x>a[i].y&&cnt1<=cnt3)||(a[i].x==a[i].y&&a[i].x==a[i].z&&cnt1<=cnt2&&cnt1<=cnt3)){
				if(cnt1<maxn){
					cnt1++;
					sum+=a[i].x;
				}
				else if(a[i].y>=a[i].z&&cnt2<maxn){
					cnt2++;
					sum+=a[i].y;
				}
				else {
					cnt3++;sum+=a[i].z;
				}
			}
			else if((a[i].y>a[i].x&&a[i].y>a[i].z)||(a[i].y==a[i].x&&a[i].y>a[i].z&&cnt1>cnt2)||(a[i].y==a[i].z&&a[i].y>a[i].x&&cnt2<cnt3)||(a[i].x==a[i].y&&a[i].x==a[i].z&&cnt2<cnt1&&cnt2<cnt3)){
				if(cnt2<maxn){
					cnt2++;
					sum+=a[i].y;
				}
				else if(a[i].x>=a[i].z&&cnt1<maxn){
					cnt1++;
					sum+=a[i].x;
				}
				else {
					cnt3++;sum+=a[i].z;
				}
			}
			else if((a[i].z>a[i].x&&a[i].z>a[i].y)||(a[i].z==a[i].x&&a[i].z>a[i].y&&cnt3<cnt1)||(a[i].z==a[i].y&&a[i].z>a[i].x&&cnt2>cnt3)||(a[i].x==a[i].y&&a[i].x==a[i].z&&cnt3<cnt1&&cnt3<cnt2)){
				if(cnt3<maxn){
					cnt3++;
					sum+=a[i].z;
				}
				else if(a[i].x>=a[i].y&&cnt1<maxn){
					cnt1++;
					sum+=a[i].x;
				}
				else {
					cnt2++;sum+=a[i].y;
				}
			}
		}
		long long sum11=sum; 
		sum=0,cnt1=0,cnt2=0,cnt3=0;
		sort(a+1,a+n+1,cmp12);
		for(int i=1;i<=n;i++){
			if((a[i].x>a[i].y&&a[i].x>a[i].z)||(a[i].x==a[i].y&&a[i].x>a[i].z&&cnt1<=cnt2)||(a[i].x==a[i].z&&a[i].x>a[i].y&&cnt1<=cnt3)||(a[i].x==a[i].y&&a[i].x==a[i].z&&cnt1<=cnt2&&cnt1<=cnt3)){
				if(cnt1<maxn){
					cnt1++;
					sum+=a[i].x;
				}
				else if(a[i].y>=a[i].z&&cnt2<maxn){
					cnt2++;
					sum+=a[i].y;
				}
				else {
					cnt3++;sum+=a[i].z;
				}
			}
			else if((a[i].y>a[i].x&&a[i].y>a[i].z)||(a[i].y==a[i].x&&a[i].y>a[i].z&&cnt1>cnt2)||(a[i].y==a[i].z&&a[i].y>a[i].x&&cnt2<cnt3)||(a[i].x==a[i].y&&a[i].x==a[i].z&&cnt2<cnt1&&cnt2<cnt3)){
				if(cnt2<maxn){
					cnt2++;
					sum+=a[i].y;
				}
				else if(a[i].x>=a[i].z&&cnt1<maxn){
					cnt1++;
					sum+=a[i].x;
				}
				else {
					cnt3++;sum+=a[i].z;
				}
			}
			else if((a[i].z>a[i].x&&a[i].z>a[i].y)||(a[i].z==a[i].x&&a[i].z>a[i].y&&cnt3<cnt1)||(a[i].z==a[i].y&&a[i].z>a[i].x&&cnt2>cnt3)||(a[i].x==a[i].y&&a[i].x==a[i].z&&cnt3<cnt1&&cnt3<cnt2)){
				if(cnt3<maxn){
					cnt3++;
					sum+=a[i].z;
				}
				else if(a[i].x>=a[i].y&&cnt1<maxn){
					cnt1++;
					sum+=a[i].x;
				}
				else {
					cnt2++;sum+=a[i].y;
				}
			}
		}
		long long sum12=sum; 
		sum=0,cnt1=0,cnt2=0,cnt3=0;
		sort(a+1,a+n+1,cmp13);
		for(int i=1;i<=n;i++){
			if((a[i].x>a[i].y&&a[i].x>a[i].z)||(a[i].x==a[i].y&&a[i].x>a[i].z&&cnt1<=cnt2)||(a[i].x==a[i].z&&a[i].x>a[i].y&&cnt1<=cnt3)||(a[i].x==a[i].y&&a[i].x==a[i].z&&cnt1<=cnt2&&cnt1<=cnt3)){
				if(cnt1<maxn){
					cnt1++;
					sum+=a[i].x;
				}
				else if(a[i].y>=a[i].z&&cnt2<maxn){
					cnt2++;
					sum+=a[i].y;
				}
				else {
					cnt3++;sum+=a[i].z;
				}
			}
			else if((a[i].y>a[i].x&&a[i].y>a[i].z)||(a[i].y==a[i].x&&a[i].y>a[i].z&&cnt1>cnt2)||(a[i].y==a[i].z&&a[i].y>a[i].x&&cnt2<cnt3)||(a[i].x==a[i].y&&a[i].x==a[i].z&&cnt2<cnt1&&cnt2<cnt3)){
				if(cnt2<maxn){
					cnt2++;
					sum+=a[i].y;
				}
				else if(a[i].x>=a[i].z&&cnt1<maxn){
					cnt1++;
					sum+=a[i].x;
				}
				else {
					cnt3++;sum+=a[i].z;
				}
			}
			else if((a[i].z>a[i].x&&a[i].z>a[i].y)||(a[i].z==a[i].x&&a[i].z>a[i].y&&cnt3<cnt1)||(a[i].z==a[i].y&&a[i].z>a[i].x&&cnt2>cnt3)||(a[i].x==a[i].y&&a[i].x==a[i].z&&cnt3<cnt1&&cnt3<cnt2)){
				if(cnt3<maxn){
					cnt3++;
					sum+=a[i].z;
				}
				else if(a[i].x>=a[i].y&&cnt1<maxn){
					cnt1++;
					sum+=a[i].x;
				}
				else {
					cnt2++;sum+=a[i].y;
				}
			}
		}
		int sumy=max(sum,max(sum11,sum12));
		printf("%lld\n",max(sumx,sumy));
	}
		}
		else{
			if(n==2){
				long long a1145[7];
				for(int i=1;i<=6;i++){
					cin>>a1145[i];
				}
				long long maxn=0;
				for(int i=1;i<=3;i++){
					for(int j=4;j<=6;j++){
						if(i!=j-3){
							maxn=max(maxn,a1145[i]+a1145[j]);
						}
					}
				}
				cout<<maxn;
			}
			if(n==4){
				long long a1145[13];
				long long maxn=0;
				for(int i=1;i<=12;i++){
					cin>>a1145[i];
				}
				for(int i=1;i<=3;i++){
					for(int j=4;j<=6;j++){
						for(int l=7;l<=9;l++){
							for(int m=10;m<=12;m++){
								if((i==j-3&&i==l-6)||(i==j-3&&i==m-9)||(i==l-6&&i==m-9)||(j-3==l-6&&j-3==m-9)){
									continue;
								}
								else{
									maxn=max(maxn,a1145[i]+a1145[j]+a1145[l]+a1145[m]);
								}
							}
						}
					}
				}
				cout<<maxn<<endl;
			}
			if(n==10){
				long long a114[11][4];
				long long maxn=0;
				for(int i=1;i<=10;i++){
					scanf("%lld",&a114[i][1]);
					scanf("%lld",&a114[i][2]);
					scanf("%lld",&a114[i][3]);
				}
				int i[11];
				for(i[1]=1;i[1]<=3;i[1]++){
					for(i[2]=1;i[2]<=3;i[2]++){
						for(i[3]=1;i[3]<=3;i[3]++){
							for(i[4]=1;i[4]<=3;i[4]++){
								for(i[5]=1;i[5]<=3;i[5]++){
									for(i[6]=1;i[6]<=3;i[6]++){
										for(i[7]=1;i[7]<=3;i[7]++){
											for(i[8]=1;i[8]<=3;i[8]++){
												for(i[9]=1;i[9]<=3;i[9]++){
													for(i[10]=1;i[10]<=3;i[10]++){
														int cnt[10];
														bool check=0;
														for(int j=1;j<=3;j++){
															cnt[j]=0;
														}
														for(int j=1;j<=10;j++){
															cnt[i[j]]++;
														}
														if(cnt[1]>5||cnt[2]>5||cnt[3]>5)check=1;
														if(check)continue;
														else{
															long long sum=0;
															for(int j=1;j<=10;j++){
																sum+=a114[j][i[j]];
															}
															maxn=max(maxn,sum);
														}
													}
												}
											}
										}	
									}
								}
							}
						}
					}
				}
				printf("%lld\n",maxn);
			}
		}
	}
	return 0;
}
