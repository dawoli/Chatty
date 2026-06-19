#include<bits/stdc++.h>
using namespace std;
/*
int num[]= {1,7,4,2,3,5,0,6,9,8};
int Nnum[]= {-1,-1,0,1,2,5,8,9};
int Dnum[]= {6,2,5,5,4,5,6,3,7,6};
#define LENGTH 100005
struct Status {
	int prev;
	int length;
	int digit;
} dp[LENGTH];
void dp_reinit(int n) {
	for(int i=0; i<n; i++) {
		dp[i] = Status {-1,1,0};
	}
}
#define likely(x) __builtin_expect(x,1)
#define unlikely(x) __builtin_expect(x,0)
int dp_cmp(const Status& i,const Status& j) {
	// Compare dp[i] and dp[j]
	// -1 if i<j
	// 0 if i==j
	// 1 if i>j
	if(unlikely((&i)==(&j))) {
		return 0;
	} else if(unlikely(i.prev<0)) {
		return 1;
	} else if(i.length>j.length) {
		return 1;
	} else if(i.length<j.length) {
		return -1;
	} else {
		switch(dp_cmp(dp[i.prev],dp[j.prev])) {
			case -1:
				return -1;
			case 0:
				if(i.digit<j.digit) {
					return -1;
				} else if(unlikely(i.digit==j.digit)) {
					return 0;
				} else {
					return 1;
				}
			case 1:
				return 1;
		}
	}
}
#define dp_access(i) dp[i]
#define dp_nextIndex current+Dnum[digit]
#define dp_first dp[0]
void updateStatus(int current,int digit) {
	if(likely(dp_access(current).prev!=-1)) {
		Status dp_current = Status {current,dp_access(current).length+1,digit};
		if(likely(dp_cmp(dp_access(dp_nextIndex),dp_current)>0)) {
			dp_access(dp_nextIndex) = dp_current;
		}
	}
}
void dp_output(int l,int i) {
	if(unlikely(dp[i].prev<0)) {
		if(unlikely(!l)) {
			printf("-1\n");
		}
	} else {
		dp_output(1,dp[i].prev);
		printf("%d",dp[i].digit);
		if(unlikely(!l)) {
			printf("\n");
		}
	}
}
void ddddpppp(int n) {
	dp_reinit(n+1);
	dp_first=Status {-2,0,0};
	for(int i=0; i<=n+1; i++) {
		for(int j=9; j>=0; j--) {
			if(unlikely(j==0&&i==0)) {
				continue;
			}
			updateStatus(i,j);
		}
	}
	dp_output(0,n);
}*/
int starting[] = {-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88};
int ending[] = {108,188,200,208,288,688,888};
void calculateDirect(int n){
	if(n<=14){
		printf("%d\n",starting[n]);
	}else{
		printf("%d",ending[(n-15)%7]);
		while(n>=22){
			printf("8");
			n-=7;
		}
		printf("\n");
	}
}
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	for(int i=0; i<T; i++) {
		int n;
		scanf("%d",&n);
		calculateDirect(n);
	}
}
