#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
int n,ans;
int a[100010][10];
struct P{
	int i,val;
}s1[100010],s2[100010],s3[100010];
int s21[100010];
int t1,t2,t3,t21;
bool cmp(const P &a,const P &b){
	return a.val>b.val; 
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int _=1;_<=t;++_){
		ans=0;
		n=0;
		t1=0;
		t2=0;
		t3=0;
		t21=0;
		memset(a,0,sizeof(a));
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		memset(s3,0,sizeof(s3));
		memset(s21,0,sizeof(s21));
		cin>>n;
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				s1[++t1].i=i,s1[t1].val=a[i][1];
			}else{
				if(a[i][2]>=a[i][3]){
					s2[++t2].i=i,s2[t2].val=a[i][2];
				}else{
					s3[++t3].i=i,s3[t3].val=a[i][3];
				}
			}
		}
		sort(s1+1,s1+t1+1,cmp);
		sort(s2+1,s2+t2+1,cmp);
		sort(s3+1,s3+t3+1,cmp);
		ans=0;
		for(int i=1;i<=t1;++i){
			ans+=s1[i].val;
		}
		for(int i=1;i<=t2;++i){
			ans+=s2[i].val;
		}
		for(int i=1;i<=t3;++i){
			ans+=s3[i].val;
		}
		if(t1>=t2&&t1>=t3){
			if(t1>n/2){
				for(int i=1;i<=t1;++i){
					if(a[s1[i].i][2]>=a[s1[i].i][3]){
						s21[++t21]=a[s1[i].i][1]-a[s1[i].i][2];
					}else{
						s21[++t21]=a[s1[i].i][1]-a[s1[i].i][3];
					}
				}
			}
		}else {
			if(t2>=t3){
				if(t2>n/2){
					for(int i=1;i<=t2;++i){
						if(a[s2[i].i][1]>=a[s2[i].i][3]){
							s21[++t21]=a[s2[i].i][2]-a[s2[i].i][1];
						}else{
							s21[++t21]=a[s2[i].i][2]-a[s2[i].i][3];
						}
					}
				}
			}else{
				if(t3>n/2){
					for(int i=1;i<=t3;++i){
						if(a[s3[i].i][1]>=a[s3[i].i][2]){
							s21[++t21]=a[s3[i].i][3]-a[s3[i].i][1];
						}else{
							s21[++t21]=a[s3[i].i][3]-a[s3[i].i][2];
						}
					}
				}
			}
		}
		sort(s21+1,s21+t21+1);
		if(t1>=t2&&t1>=t3){
			for(int i=1;i<=t1-n/2;++i){
				ans-=s21[i];
			}
		}else{
			if(t2>=t3){
				for(int i=1;i<=t2-n/2;++i){
					ans-=s21[i];
				}
			}else{
				for(int i=1;i<=t3-n/2;++i){
					ans-=s21[i];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
