#include<bits/stdc++.h>
using namespace std;
int t,i,j,k,p,n,m,ans,aim;
int club[4];
struct student{
	int a[4];
	int f,s,c,go;//first,second,cost
};
student stu[100005];
bool bmp(student s1, student s2){
	return s1.c<s2.c;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	for(i=1;i<=t;i++){
		club[1]=0;
		club[2]=0;
		club[3]=0;
		cin>>n;
		m=n/2;//max_member
		for(j=1;j<=n;j++){
			cin>>stu[j].a[1]>>stu[j].a[2]>>stu[j].a[3];
			//prepare
			stu[j].f=1;
			if(stu[j].a[2]>stu[j].a[stu[j].f])stu[j].f=2;
			if(stu[j].a[3]>stu[j].a[stu[j].f])stu[j].f=3;
			if(stu[j].f==1)stu[j].a[2]>stu[j].a[3]?stu[j].s=2:stu[j].s=3;
			if(stu[j].f==2)stu[j].a[1]>stu[j].a[3]?stu[j].s=1:stu[j].s=3;
			if(stu[j].f==3)stu[j].a[1]>stu[j].a[2]?stu[j].s=1:stu[j].s=2;
			stu[j].c=stu[j].a[stu[j].f]-stu[j].a[stu[j].s];
			//m1
			stu[j].go=stu[j].f;
			club[stu[j].go]++;
		}
		//m2
		for(k=1;k<=3;k++){
			if(club[k]>m){
				sort(stu+1,stu+n+1,bmp);
				aim=club[k]-m;
				for(p=1;p<=n;p++){
					if(stu[p].go==k){
						stu[p].go=stu[p].s;
						aim--;
					}
					if(aim==0)break;
				}
				break;
			}
		}
		//end
		ans=0;
		for(k=1;k<=n;k++)ans+=stu[k].a[stu[k].go];
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
