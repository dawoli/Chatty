#include<cstdio>
const int N = 1e6 + 1e4;
const int K = 1<<21;
int n,k,a[N],s[N],ss[N],tong[K],pos,last,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
		ss[i]=s[i]^k;
	}
	for(int i=0;i<=1<<20;i++){
		tong[i]=-1;
	}
	tong[0]=0;last=0;ans=0;
	for(int i=1;i<=n;i++){
		pos=tong[ss[i]];
		if(pos>=last){
			ans++;
			last=i;
		}
		tong[s[i]]=i;
	}
	printf("%d\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
