#include<iostream>
#include<cstdio>
using namespace std;

int n;
int a[100005][2]; 

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    int cnt=n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i][1]);//输入数据
        a[i][2]=1;//标记当前数据是否可以继续使用，可以为1，不可以为0
    }
    for(int i=1;i<=n;i++){//外层循环控制第一个想要比较的数字
        for(int j=1;j<=n;j++){//内层循环控制第二个想要比较的数字
            if(a[i][1]>a[j][1] && a[i][2]==1 && a[i][2]==1){//满足可以攻击且攻受都可以使用
            	//测试代码 
            	//cout<<"i="<<i;
            	//cout<<" j="<<j<<endl;
            	//cout<<"a[i][1]="<<a[i][1];
            	//cout<<" a[j][1]="<<a[j][1]<<endl;
            	//cout<<"a[i][2]="<<a[i][2];
            	//cout<<" a[j][2]="<<a[j][2]<<endl;
            	//cout<<"a[i][3]="<<a[i][3];
            	//cout<<" a[j][3]="<<a[j][3]<<endl<<endl;
				//只能攻击一次，且如果攻>受则受淘汰 
            	a[i][2]=0;
            	a[j][2]=0;//将攻受都标记为不能使用 
                cnt--;//计算变量自减，表示有一个卡牌淘汰出局
            }
        }
    }
    printf("%d",cnt);//输出结果

    return 0;
}
