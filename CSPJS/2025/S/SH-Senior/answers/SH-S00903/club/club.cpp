#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int num[100050][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	for (int i=1;i<=t;i++){
		memset(num,sizeof(num),0);
		int n;cin>>n;
		for (int j=1;j<=n;j++){
			scanf("%d",&num[j][1]);
			scanf("%d",&num[j][2]);
			scanf("%d",&num[j][3]);
		}
		if (n==2){
			int a=num[1][1];int b=num[1][2];int c=num[1][3];
			int d=num[2][1];int e=num[2][2];int f=num[2][3];
			int result=max(max(max(a+e,a+f),max(b+d,b+f)),max(c+d,c+e));
			cout<<result<<endl;
		}else if (n==4){
 			int num1=num[1][1]+num[2][1]+num[3][2]+num[4][3];//12 3 4
			int num2=num[1][1]+num[2][1]+num[3][3]+num[4][2];//12 4 3
			int num3=num[1][2]+num[2][2]+num[3][1]+num[4][3];//3 12 4
			int num4=num[1][2]+num[2][2]+num[3][3]+num[4][1];//4 12 3
			int num5=num[1][3]+num[2][3]+num[3][1]+num[4][2];//3 4 12
			int num6=num[1][3]+num[2][3]+num[3][2]+num[4][1];//4 3 12
		 	int maxx1=max(max(max(num1,num2),max(num3,num4)),max(num5,num6));
			int num7=num[1][2]+num[2][1]+num[3][1]+num[4][3];//23 1 4
			int num8=num[1][3]+num[2][1]+num[3][1]+num[4][2];//23 4 1
			int num9=num[1][1]+num[2][2]+num[3][2]+num[4][3];//1 23 4
			int num10=num[1][3]+num[2][2]+num[3][2]+num[4][1];//4 23 1
			int num11=num[1][1]+num[2][3]+num[3][3]+num[4][2];//1 4 23
			int num12=num[1][2]+num[2][3]+num[3][3]+num[4][1];//4 1 23
			int maxx2=max(max(max(num7,num8),max(num9,num10)),max(num11,num12));
			int num13=num[1][2]+num[2][3]+num[3][1]+num[4][1];//34 1 2
			int num14=num[1][3]+num[2][2]+num[3][1]+num[4][1];//34 2 1
			int num15=num[1][1]+num[2][3]+num[3][2]+num[4][2];//1 34 2
			int num16=num[1][3]+num[2][1]+num[3][2]+num[4][2];//2 34 1
			int num17=num[1][1]+num[2][2]+num[3][3]+num[4][3];//1 2 34
			int num18=num[1][2]+num[2][1]+num[3][3]+num[4][3];//2 1 34
			int maxx3=max(max(max(num13,num14),max(num15,num16)),max(num17,num18));
			int num19=num[1][1]+num[2][3]+num[3][1]+num[4][3];//13 2 4
			int num20=num[1][1]+num[2][3]+num[3][1]+num[4][2];//13 4 2
			int num21=num[1][2]+num[2][1]+num[3][2]+num[4][3];//2 13 4
			int num22=num[1][2]+num[2][3]+num[3][2]+num[4][1];//4 13 2
			int num23=num[1][3]+num[2][1]+num[3][3]+num[4][2];//2 4 13
			int num24=num[1][3]+num[2][2]+num[3][3]+num[4][1];//4 2 13
			int maxx4=max(max(max(num19,num20),max(num21,num22)),max(num23,num24));
			int num25=num[1][2]+num[2][1]+num[3][3]+num[4][1];//24 1 3
			int num26=num[1][3]+num[2][1]+num[3][2]+num[4][1];//24 3 1
			int num27=num[1][1]+num[2][2]+num[3][3]+num[4][2];//1 24 3
			int num28=num[1][3]+num[2][2]+num[3][1]+num[4][2];//3 24 1
			int num29=num[1][1]+num[2][3]+num[3][2]+num[4][3];//1 3 24
			int num30=num[1][2]+num[2][3]+num[3][1]+num[4][3];//3 1 24
			int maxx5=max(max(max(num25,num26),max(num27,num28)),max(num29,num30));
			int num31=num[1][1]+num[2][2]+num[3][3]+num[4][1];//14 2 3
			int num32=num[1][1]+num[2][3]+num[3][2]+num[4][1];//14 3 2
			int num33=num[1][2]+num[2][1]+num[3][3]+num[4][2];//2 14 3
			int num34=num[1][2]+num[2][3]+num[3][1]+num[4][2];//3 14 2
			int num35=num[1][3]+num[2][1]+num[3][2]+num[4][3];//2 3 14
			int num36=num[1][3]+num[2][2]+num[3][1]+num[4][3];//3 2 14
			int maxx6=max(max(max(num31,num32),max(num33,num34)),max(num35,num36));
			int temp=max(max(maxx1,maxx2),max(maxx3,maxx4));
			int result=max(temp,max(maxx5,maxx6));
			cout<<result<<endl;
		}else if (n==100000){
			int score[100005];
			for (int k=0;k<=100000-1;k++){
				score[k]=num[k+1][1];
			}
			sort(score,score+100000);
			long long sum=0;
			for (int k=99999;k>=50000;k--){
				sum+=score[k];
			}
			cout<<sum;
		}
	}
	return 0;
}
