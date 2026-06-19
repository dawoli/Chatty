#include<cstdio>
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out", "w",stdout);
	int n, m, le=0, a[501];
	long long s=0;
	char b[501];
	bool b1_2=0;
	scanf("%d%d", &n, &m);
	scanf(" %s", b+1);
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]);
	}
	for(int i=1;i<=n;i++){
		if(b[i]!='1'){
			b1_2=1;
			break;
		}
	}
	if(!b1_2){
		s=1;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				le++;
			}
		}
		for(int i=le;i<=n;i++){
			s*=i;
			s%=998244353;
		}
		printf("%lld", s);
		return 0;
	}
}
