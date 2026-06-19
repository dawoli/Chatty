#include<bits/stdc++.h>
using namespace std;
const int N=114514;
int t,ans[N]={};
struct stu{
	int first,second,third;
};
stu score[114514];
//bool cmp(stu x){
//	return x.first<x.second;
//}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int q=1;q<=t;q++){
		int n,x[N]={},y[N]={},max1[N]={},max2[N]={},max3[N]={};//,sum1=0,sum2=0,sum3=0
		cin>>n;
		int maxn=n/2;
		for(int i=1;i<=n;i++){
			cin>>score[i].first>>score[i].second>>score[i].third;
			x[i]=max(score[i].first,score[i].second);   //12部门之间的最大值
			y[i]=max(score[i].first,score[i].third);	//13部门之间的最大值
			max1[i]=max(x[i],y[i]);		//三个部门的最大值 我怎么就把结构体排序忘了呢 :( 
			//cout<<max1[i]<<endl;
			if(score[i].first>score[i].second&&score[i].first<score[i].third){
				max2[i]=score[i].first;
			}
			else if(score[i].second>score[i].first&&score[i].second<score[i].third){
				max2[i]=score[i].second;
			}
			else if(score[i].third>score[i].first&&score[i].third<score[i].second){
				max2[i]=score[i].third;													//变相的求一下第二大的值，实在没想带有哪个函数可以求这个的 
			}
			max3[i]=min(x[i],y[i]);		//三个部门的最小值  QWQ 
		}
		
		//sort(score+1,score+n+1,cmp);
		
		for(int i=1;i<=n;i++){
			ans[i]+=max1[i];	
		}
	}
	for(int i=1;i<=t;i++){
		cout<<ans[i]<<endl; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
	____
	 |
	 0
	/|\
	/\
*/
