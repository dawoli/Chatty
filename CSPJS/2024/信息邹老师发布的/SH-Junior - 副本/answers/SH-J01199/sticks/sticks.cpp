#include<cstring>
#include<cstdio>
const int N=100010;
const int cnt[10]={6,2,5,5,4,5,6,3,7,6};
int _,n;
int f[N][10],sum[N];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	memset(f,0,sizeof f);
	memset(sum,-1,sizeof sum);
	f[2][1]=1;
	sum[2]=1;
	f[5][2]=1;
	sum[5]=1;
	f[4][4]=1;
	sum[4]=1;
	f[6][6]=1;
	sum[6]=1;
	f[3][7]=1;
	sum[3]=1;
	f[7][8]=1;
	sum[7]=1;
	for(int i=8;i<N;i++)
		for(int j=0;j<10;j++){
			int k=i-cnt[j];
			if(sum[k]==-1)
				continue;
			if((sum[i]==-1)||(sum[k]+1<sum[i])){
//				printf("%d->%d\n",k,i);
				sum[i]=sum[k]+1;
				memcpy(f[i],f[k],sizeof f[i]);
				f[i][j]++;
				continue;
			}
			if(sum[k]+1>sum[i])
				continue;
			int min_i,min_k;
			for(int d=1;d<10;d++)
				if(f[i][d]){
					min_i=d;
					break;
				}
			f[k][j]++;
			for(int d=1;d<10;d++)
				if(f[k][d]){
					min_k=d;
					break;
				}
			f[k][j]--;
			if(min_i>min_k){
//				printf("%d->%d\n",k,i);
				memcpy(f[i],f[k],sizeof f[i]);
				f[i][j]++;
				continue;
			}
			if(min_i<min_k)
				continue;
			f[k][j]++;
			bool flag=true;
			for(int d=0;d<10;d++){
				if(f[i][d]>f[k][d]){
					flag=false;
					break;
				}
				if(f[i][d]<f[k][d]){
					flag=true;
					break;
				}
			}
			f[k][j]--;
			if(!flag)
				continue;
//			printf("%d->%d\n",k,i);
			memcpy(f[i],f[k],sizeof f[i]);
			f[i][j]++;
		}
//	output for all n:
//	for(int n=1;n<N;n++){
//		if(sum[n]==-1){
//			puts("-1");
//			continue;
//		}
//		printf("%d ",sum[n]);
//		int minv=0;
//		for(int i=1;i<10;i++)
//			if(f[n][i]){
//				minv=i;
//				break;
//			}
//		f[n][minv]--;
//		putchar(minv+'0');
//		for(int i=0;i<10;i++){
//			int cnt=f[n][i];
//			while(cnt--)
//				putchar(i+'0');
//		}
//		f[n][minv]++;
//		puts("");
//	}
//	return 0;
	scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		if(sum[n]==-1){
			puts("-1");
			continue;
		}
		int minv=0;
		for(int i=1;i<10;i++)
			if(f[n][i]){
				minv=i;
				break;
			}
		f[n][minv]--;
		putchar(minv+'0');
		for(int i=0;i<10;i++){
			int cnt=f[n][i];
			while(cnt--)
				putchar(i+'0');
		}
		f[n][minv]++;
		puts("");
	}
	return 0;
}
/*
0 6 (Y)
1 2 (Y)
2 5 (Y)
4 4 (Y)
6 6 (Y)
7 3 (Y)
8 7 (Y)
*/
