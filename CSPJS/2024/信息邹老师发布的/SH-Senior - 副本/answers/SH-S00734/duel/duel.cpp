#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x) {
    x=0;bool f=0;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')f=1;ch=getchar();}
    while(ch>='0'&&ch<='9') {x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    f?x=-x:0;
}
template<typename type, typename ...T>
inline void read(type &x,T &...y) {
    read(x);
    read(y...);
}
const int N=1e5+10;
int n,a[N],cnt[N];
bool used[N];

int findnxt(int x) {
    int l=x,r=n;
    while(l<r) {
        int mid=(l+r)>>1;
        if (a[mid]>a[x]) {
			if(!used[mid])r=mid;
			else r=mid+1;
        } else {
        	if (!used[mid+1]) l=mid+2;
            else l=mid+1;
            if (l>n) return -1;
        }
    }
    return l;
}

int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
    read(n);
    for (int i=1;i<=n;i++){
        read(a[i]);
        cnt[a[i]]++;
    }
    sort(a+1,a+n+1);
    int ans=n;
    if (n<=50) {
		for(int i=1;i<=n;i++) {
			for (int j=i+1;j<=n;j++) {
				if (used[j]==0&&a[j]>a[i]) {
					ans--;
					used[j]=1;
					break;
				}
			}
		}
		printf("%d\n",ans);
		return 0;
    } else {
    	cout<<cnt[2]<<" "<<cnt[1]<<endl;
		ans=n-min(cnt[2],cnt[1]);
		printf("%d\n",ans);
		return 0;
    }

}
