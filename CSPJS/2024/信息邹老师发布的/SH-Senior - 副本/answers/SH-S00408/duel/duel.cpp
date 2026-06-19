#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD=998244353;
const int MN=100005;
const int INF=0x3f3f3f3f;

int Read() {
	int t=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9') {
		t=t*10+c-'0';
		c=getchar();
	}
	return t*f;
}
void Print(int x) {
	if(x<0) {
		putchar('-');
		x=-x;
	} 
	if(x<10) {
		putchar((char)(x%10+'0')); 
	    return;
	}
	Print(x/10);
	putchar((char)(x%10+'0')); 
	return;
}

int n,a[MN],num[MN],ans;
int find(int l,int r,int x) {
	while((r-l)>=3) {
		int mid=(l+r)/2;
		if(a[mid]<=x) l=mid;
		else r=mid;
	}
	for(int i=l;i<=r;++i) {
		if(a[i]>x) return i;
	}
	return -1;
}

int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
//    scanf("%d",&n);
    n=Read();
    for(int i=1;i<=n;++i) {
//    	scanf("%d",&a[i]);
	    a[i]=Read();
	}
    sort(a+1,a+n+1);
//    for(int i=1;i<=n;++i) {
//    	printf("%3d",a[i]);
//	}
//	cout<<endl;
    for(int i=1;i<=n;++i) {
    	int nxt=find(i+1,n,a[i]);
//    	cout<<nxt<<endl;
        if(nxt==-1) continue;
        int fff=0;
        if(num[nxt]==0) fff=1;
        while(num[nxt]) {
            nxt++;
			if(nxt>n) break;
			if(num[nxt]==0) {
				fff=1;
				break;
			}	
		}
		//可以在这里优化 省略往后一步一步跳的过程！！！！！！ 
		if(fff==1) {
			num[nxt]=1;
			num[i]=2;
			ans++;
		}
//		for(int j=1;j<=n;++j) {
//    	printf("%3d",num[j]);
//		}
//		cout<<endl;
	}
//	printf("%d\n",n-ans);
	Print(n-ans);
	return 0; 
} 
