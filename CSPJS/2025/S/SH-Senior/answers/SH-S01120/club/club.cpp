#include<bits/stdc++.h>
using namespace std;
const int MAXN=100000+5;
int a1[MAXN];int a2[MAXN];int a3[MAXN];//初始值 
int a[MAXN/4+1]; int b[MAXN/2+1];int c[MAXN/2+1];// 最后去的地方 
int t;int n;int ans[5];int sum;int d[3];int min1;int max1;int mid1; 
int p[MAXN][3];int temp[2][MAXN];int cnt[MAXN];//热门社团人的编号及其贡献 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	
	for(int k=0;k<t;k++){
		cin>>n;
		//cout<<n; 
		for(int i=0;i<n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			//cout<<a1[i]<<a2[i]<<a3[i];
				if(a1[i]>a2[i]&&a2[i]>=a3[i]){
					p[i][0]=a1[i];
					p[i][1]=a2[i];
					p[i][2]=a3[i];
					d[0]+=1;
					
				}
				if(a2[i]>a1[i]&&a1[i]>=a3[i]){
					p[i][0]=a2[i];
					p[i][1]=a1[i];
					p[i][2]=a3[i];
					d[1]+=1;
				}
				if(a3[i]>a1[i]&&a1[i]>=a2[i]){
					p[i][0]=a3[i];
					p[i][1]=a1[i];
					p[i][2]=a2[i];
					d[2]+=1;
				}
				
				if(a1[i]>a3[i]&&a3[i]>=a2[i]){
					p[i][0]=a1[i];
					p[i][1]=a3[i];
					p[i][2]=a2[i];
					d[0]+=1;
				}
				
				if(a2[i]>a3[i]&&a3[i]>=a1[i]){
					p[i][0]=a2[i];
					p[i][1]=a3[i];
					p[i][2]=a1[i];
					d[1]+=1;
				}
				
				if(a3[i]>a2[i]&&a2[i]>=a1[i]){
					p[i][0]=a3[i];
					p[i][1]=a2[i];
					p[i][2]=a1[i];
					d[2]+=1;
				}
			}//cout<<d[0]<<d[1]<<d[2]<<"fws";//录入
			min1=min(min(d[0],d[1]),min(d[0],d[2]));
			max1=max(max(d[0],d[1]),max(d[0],d[2]));
			if(max1==d[0]&&min1==d[2]||max1==d[2]&&min1==d[0]){
				mid1=d[1];
			}
			if(max1==d[1]&&min1==d[2]||max1==d[2]&&min1==d[1]){
				mid1=d[0];
			}
			if(max1==d[0]&&min1==d[1]||max1==d[1]&&min1==d[0]){
				mid1=d[2];
			}//给部门热度排序 
			//最热门的社团也就是max1所对应的社团。 
			//cout<<mid1<<max1<<min1<<"fws";
			int t1=0;int t2=0;int t3=0;
			//人数 
			int sum1=0;int sum2=0;int sum3=0;
			int flag=4;
			for(int i=0;i<n;i++){
			//cout<<p[i][0]<<" ";
		}
		for(int i=0;i<n;i++){
			//0,1,2对应很小众，一般和大众。 
			if((p[i][0]==a1[i]&&min1==d[0])||(p[i][0]==a2[i]&&min1==d[1])||(p[i][0]==a3[i]&&min1==d[2])){
				flag=0;
			}
			if((p[i][0]==a1[i]&&mid1==d[0])||(p[i][0]==a2[i]&&mid1==d[1])||(p[i][0]==a3[i]&&mid1==d[2])){
				flag=1;
			}
			if((p[i][0]==a1[i]&&max1==d[0])||(p[i][0]==a2[i]&&max1==d[1])||(p[i][0]==a3[i]&&max1==d[2])){
				flag=2;
			}
			if(flag==0){
				//cout<<"fws0";
				t1++;a[t1]=i;if(min1==d[0]){
					sum1+=a1[i];
				}if(min1==d[1]){
					sum1+=a2[i];
				}if(min1==d[2]){
					sum1+=a3[i];
				}
				
			}
			if(flag==1){
					//cout<<"fws1";
				t2++;b[t2]=i;if(mid1==d[0]){
					sum2+=a1[i];
				}if(mid1==d[1]){
					sum2+=a2[i];
				}if(mid1==d[2]){
					sum2+=a3[i];
				}
			}
			if(flag==2){
					//cout<<"fws2";
				temp[t3][0]=i;
				 //cout<<p[i][0];
				if ((p[i][0]==a1[i]&&max1==d[0])){temp[1][t3]=a1[i];}//cout<<1<<"\n";}
				if ((p[i][0]==a2[i]&&max1==d[1])){temp[1][t3]=a2[i];}//cout<<2<<"\n";}
				if ((p[i][0]==a3[i]&&max1==d[2])){temp[1][t3]=a3[i];}//cout<<a3[i]<<"\n";}
				t3++;
			}
			flag=4;
		}
		//cout<<t1<<t2<<t3;
		//for(int i=0;i<t3;i++){
		//	cout<<temp[1][i]<<" ";
		//}
		sort(temp[1]-1,temp[1]+t3);
		//for(int i=0;i<t3;i++){
		//	cout<<temp[1][i]<<" ";
		//} 
	if(t3<=n/2){
		for(int i=0;i<n;i++){
			ans[k]+=p[i][0];
		}
		continue;
	}
	int f=0;
	if(sum1==sum2&&sum2==0){
		f=1;
	}
	if(t3>n/2){//大部门踢人 
	
		for(int i=0;i<t3-n/2;i++){
			int tmp;
				if (max1==d[0]){
					tmp=max(a2[i],a3[i]);
					if(a2[i]==tmp&&min1==d[1]){
						sum1+=tmp;//cout<<"1++"<<tmp;
					}
					if(a3[i]==tmp&&min1==d[2]){
						sum1+=tmp;//cout<<"1++"<<tmp;
					}
					if(a2[i]==tmp&&mid1==d[1]){
						sum2+=tmp;
					}
					if(a3[i]==tmp&&mid1==d[2]){
						sum2+=tmp;
					}
				}
				if (max1==d[1]){
					tmp=max(a1[i],a3[i]);
					if(a1[i]==tmp&&min1==d[0]){
						sum1+=tmp;//cout<<"1++"<<tmp;
					}
					if(a3[i]==tmp&&min1==d[2]){
						sum1+=tmp;//cout<<"1++"<<tmp;
					}
					if(a1[i]==tmp&&mid1==d[0]){
						sum2+=tmp;
					}
					if(a3[i]==tmp&&mid1==d[2]){
						sum2+=tmp;
					}
				}
				if (max1==d[2]){
					tmp=max(a2[i],a1[i]);
					if(a2[i]==tmp&&min1==d[1]){
						sum1+=tmp;//cout<<"1++"<<tmp;
					}
					if(a1[i]==tmp&&min1==d[0]){
						sum1+=tmp;//cout<<"1++"<<tmp;
					}
					if(a2[i]==tmp&&mid1==d[1]){
						sum2+=tmp;
					}
					if(a1[i]==tmp&&mid1==d[0]){
						sum2+=tmp;
					}
				}
			temp[1][i]=0;
		}

		
	}
	for(int i=0;i<t3;i++){
		sum3+=temp[1][i];
	}
		
	//	cout<<k<<"\n";
		//cout<<sum1<<"\n";
		//cout<<sum2<<"\n";
		//cout<<sum3<<"\n";
		
		
	sum=sum1+sum2+sum3;
		ans[k]=sum;if(f==1){
			ans[k]-=sum1;
		}
	}
	for(int i=0;i<t;i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
}
/*
3 
4
4 2 1
3 2 4
5 3 4
3 5 1
1
4 
0 1 0
0 1 0
0 2 0
0 2 0
1
2
10 9 8
4 0 0*/
