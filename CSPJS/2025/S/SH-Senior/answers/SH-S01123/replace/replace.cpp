#include<cstdio>
#include<cstring>
const int L = 10005;
const int N = 10005;
struct change{
	char fr[L];
	char to[L];
	int frlen;
	int tolen;
};
change a[N];
char t1[L],t2[L];
int n,q,len1,len2,ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",a[i].fr,a[i].to);
		a[i].frlen=strlen(a[i].fr);
		a[i].tolen=strlen(a[i].to);
	}
	while(q--){
		scanf("%s%s",t1,t2);
		len1=strlen(t1);len2=strlen(t2);ans=0;
		if(len1!=len2){
			printf("0\n");
			continue;
		}
		for(int i=1;i<=n;i++){
			if(len2-len1!=a[i].tolen-a[i].frlen || len1<a[i].frlen){
				continue;
			}
			for(int j=0;j<=len1-a[i].frlen;j++){
				int ok=1;
				for(int k=j;k<=j+a[i].frlen-1;k++){
					if(t1[k]!=a[i].fr[k-j]){
						ok=0;break;
					}
				}
				if(ok==0)continue;
				for(int k=0;k<j;k++){
					if(t1[k]!=t2[k]){
						ok=0;break;
					}
				}
				if(ok==0)break;
				for(int k=j;k<=j+a[i].tolen-1;k++){
					if(t2[k]!=a[i].to[k-j]){
						ok=0;break;
					}
				}
				if(ok==0)break;
				for(int k=j+a[i].frlen,k2=j+a[i].tolen;k<len1;k++,k2++){
					if(t1[k]!=t2[k2]){
						ok=0;break;
					}
				}
				if(ok==1){
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
