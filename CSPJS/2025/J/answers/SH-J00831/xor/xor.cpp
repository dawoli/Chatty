// 2^20 = 1048576 \approx\ 1e6
// **2** ^ 20 \to\ get each bit
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,k;
//int b[N][25];
int a[N],s[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
//for(int i=1;i<=n;i++) printf("%d: %d\n",i,s[i]);
	int end=0,cnt=0;
	while(1){
		for(int i=end+1;;i++){
			if(i>n) goto end_while; // end
			for(int j=end+1;j<=i;j++) // this.start
				if((s[j-1]^s[i])==k){ // no (): s[j-1]^(s[i]==k)
					cnt++;
					end=i;
//printf("#%d: [%d, %d]\n",cnt,j,i);
//printf("s[j-1]^s[i] = s[%d]^s[%d] = %d ^ %d = %d\n",j-1,i,s[j-1],s[i],s[j-1]^s[i]);
//printf("k = %d, %c\n",k,(s[j-1]^s[i]==k)?'T':'F');
					goto end_for_i;
				}
		}
		end_for_i:;
	}
	end_while:;
	printf("%d\n",cnt);
	return 0;
}

