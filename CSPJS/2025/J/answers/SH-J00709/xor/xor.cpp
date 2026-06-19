#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],b[N],ans;
set<int> s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i]^b[i-1];
	s.insert(0);
	for(int i=1;i<=n;i++){
		int t=b[i]^k;
        if(s.count(t)) ans++,s.clear();
        s.insert(b[i]);
	}
	printf("%d\n",ans); 
	return 0;
}
