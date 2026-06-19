#include <bits/stdc++.h>
using namespace std;
int a[100001][3];
int c[100001],d0[100001],d1[100001],d2[100001];
int n,t,i,p,ans,flag,fn,ld0,ld1,ld2;
int work1(int n1,int n2,int n3){
	if (max(n1,max(n2,n3))==n1) return 0;
	else if(max(n1,max(n2,n3))==n2) return 1;
	else{
		return 2;
	}
}
int work2(int ns[3]){
	int mn=0;
	int mi=0;
	int n1=ns[0],n2=ns[1],n3=ns[2];
	if (max(n1,max(n2,n3))==n1) ;
	else if(max(n1,max(n2,n3))==n2) mn=1;
	else{
		mn=2;
	}
	if (min(n1,min(n2,n3))==n1) ;
	else if(min(n1,min(n2,n3))==n2) mi=1;
	else{
		mi=2;
	}
	return ns[mn]-ns[3-mi-mn];
}

int count11(int l[100001],int pm,int nu){
	int cnt=0;
	for (int pp=0;pp<pm;pp++){
		if (l[pp]==nu) cnt++;
	}
	return cnt;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(i=0;i<t;i++){
		cin >> n;
		ld0=0;ld1=0;ld2=0;
		for (p=0;p<n;p++){
			cin >> a[p][0] >> a[p][1] >> a[p][2];
			c[p]=work1(a[p][0],a[p][1],a[p][2]);//choice
			if (c[p]==0){d0[ld0]=work2(a[p]);ld0++;} 
			else if(c[p]==1){d1[ld1]=work2(a[p]);ld1++;}
			else {d2[ld2]=work2(a[p]);ld2++;}
		}
		//check 1,2,3
		flag=-1;
		for (p=0;p<3;p++){
			if (count11(c,n,0)>(n/2)){flag=0;fn=count11(c,n,0)-(n/2);}
			else if(count11(c,n,1)>(n/2)){flag=1;fn=count11(c,n,1)-(n/2);}
			else if(count11(c,n,2)>(n/2)){flag=2;fn=count11(c,n,2)-(n/2);}
		}
		ans=0;
		for (p=0;p<n;p++)ans+=a[p][c[p]];
		if (flag==-1){
			cout << ans << endl;
			continue;
		}
		
		if (flag==0){
			sort(d0,d0+ld0);
			for (p=0;p<fn;p++){
				ans-=d0[p];
			}
		}
		else if (flag==1){
			sort(d1,d1+ld1);
			for (p=0;p<fn;p++){
				ans-=d1[p];
			}
		}
		else if (flag==2){
			sort(d2,d2+ld2);
			for (p=0;p<fn;p++){
				ans-=d2[p];
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

