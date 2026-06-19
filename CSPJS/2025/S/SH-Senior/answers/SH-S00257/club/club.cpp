#include<bits/stdc++.h>
using namespace std;

int t,n,x[100009],y[100009],z[100009],topx=1,topy=1,topz=1,ans;

struct Node {
	int a,b,c;
} a[100009];

bool cmpx(int x1,int x2){
	return a[x1].a-max(a[x1].b,a[x1].c)>a[x2].a-max(a[x2].b,a[x2].c);
}

bool cmpy(int y1,int y2){
	return a[y1].b-max(a[y1].a,a[y1].c)>a[y2].b-max(a[y2].a,a[y2].c);
}

bool cmpz(int z1,int z2){
	return a[z1].c-max(a[z1].b,a[z1].a)>a[z2].c-max(a[z2].b,a[z2].a);
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1; i<=t; i++) {
		scanf("%d",&n);
		topx=1;
		topy=1;
		topz=1;
		ans=0;
		for(int j=1; j<=n; j++) {
			scanf("%d%d%d",&a[j].a,&a[j].b,&a[j].c);
			if(a[j].a>a[j].b&&a[j].a>a[j].c){
				ans+=a[j].a;
				x[topx]=j;
				topx++;
			}else if(a[j].b>a[j].a&&a[j].b>a[j].c){
				ans+=a[j].b;
				y[topy]=j;
				topy++;
			}else if(a[j].c>a[j].a&&a[j].c>a[j].b){
				ans+=a[j].c;
				z[topz]=j;
				topz++;
			}else if(a[j].a==a[j].b&&a[j].a>a[j].c){
				ans+=a[j].a;
				x[topx]=j;
				topx++;
			}else if(a[j].a==a[j].c&&a[j].a>a[j].b){
				ans+=a[j].a;
				x[topx]=j;
				topx++;
			}else if(a[j].b==a[j].c&&a[j].b>a[j].a){
				ans+=a[j].b;
				y[topy]=j;
				topy++;
			}else if(a[j].a==a[j].b&&a[j].a==a[j].c){
				ans+=a[j].a;
				x[topx]=j;
				topx++;
			}
		}
		while(topx>n/2+1||topy>n/2+1||topz>n/2+1){
			if(topx>n/2+1){
				sort(x+1,x+topx,cmpx);
				for(int j=topx-1;j>n/2;j--){
					if(a[x[j]].b>=a[x[j]].c&&topy<=n/2){
						ans-=a[x[j]].a;
						ans+=a[x[j]].b;
						y[topy]=x[j];
						topy++;
					}else{
						ans-=a[x[j]].a;
						ans+=a[x[j]].c;
						z[topz]=x[j];
						topz++;
					}
				}
				topx=n/2+1;
			}
			if(topy>n/2+1){
				sort(y+1,y+topy,cmpy);
				for(int j=topy-1;j>n/2;j--){
					if(a[y[j]].a>=a[y[j]].c&&topx<=n/2){
						ans-=a[y[j]].b;
						ans+=a[y[j]].a;
						x[topx]=y[j];
						topx++;
					}else{
						ans-=a[y[j]].b;
						ans+=a[y[j]].c;
						z[topz]=y[j];
						topz++;
					}
				}
				topy=n/2+1;
			}
			if(topz>n/2+1){
				sort(z+1,z+topz,cmpz);
				for(int j=topz-1;j>n/2;j--){
					if(a[z[j]].a>=a[z[j]].b&&topx<=n/2){
						ans-=a[z[j]].c;
						ans+=a[z[j]].a;
						x[topx]=z[j];
						topx++;
					}else{
						ans-=a[z[j]].c;
						ans+=a[z[j]].b;
						y[topy]=z[j];
						topy++;
					}
				}
				topz=n/2+1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
作为一名7年级的xxs(?)我成功使用2.5h做完了这题
发现似乎没有一道别的题可以不可以总司令 
算了把样例总司令了吧，经典之《样例全过但0分》 
话说这压缩包密码又是谁想出来的？上午是上善若水，下午是人杰地灵 
*/ 
