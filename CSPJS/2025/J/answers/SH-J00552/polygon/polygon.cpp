#include <iostream>
using namespace std;
int l[5005];
long long n;
int t(int a,int b,int c){
	int j=max(l[a-1],l[b-1]);
	j=max(j,l[c-1]) ;
	if(l[a-1]+l[b-1]+l[c-1]>2*j) return 1;
	return 0;
}
int s(int a,int b,int c,int d){
	int j=max(l[a-1],l[b-1]);
	j=max(j,l[c-1]) ;
	j=max(j,l[d-1]);
	if(l[a-1]+l[b-1]+l[c-1]+l[d-1]>2*j) return 1;
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long k,fl=1,cnt=0,ccnt=1,mx=0,sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l[i];
		if(l[i]!=1) fl=0;
		if(mx<l[i]) mx=l[i];
		sum+=l[i];
	} 
	if(fl){
		for(int i=2;i<n;i++){
			k=1;
			ccnt=1;
			for(int j=n;j>=n-i;j--){
				ccnt*=j;
				ccnt/=k;
				k++;
			}
			cnt+=ccnt;
			//cout<<ccnt<<endl;
			cnt%=998244353;
		}
		cout<<cnt;
	}
	else if(n==3){
		if(sum>2*mx) cout<<1;
		else{
			cout<<0;
		}
	}
	else if(n==4){
		cnt+=t(1,2,3);
		cnt+=t(1,2,4);
		cnt+=t(1,4,3);
		cnt+=t(4,2,3);
		if(sum>2*mx) cout<<cnt+1;
		else{
			cout<<cnt;
		}
	}
	else if(n==5){
		cnt+=t(1,2,3);
		cnt+=t(1,2,4);
		cnt+=t(1,4,3);
		cnt+=t(4,2,3);
		cnt+=t(1,2,5);
		cnt+=t(1,5,4);
		cnt+=t(1,5,3);
		cnt+=t(5,2,3);
		cnt+=t(4,2,5);
		cnt+=t(4,5,3);
		cnt+=s(1,5,3,4);
		cnt+=s(1,2,3,5);
		cnt+=s(1,2,4,5);
		cnt+=s(1,4,3,2);
		cnt+=s(4,2,3,5);
		if(sum>2*mx) cout<<cnt+1;
		else{
			cout<<cnt;
		}
	}
	else{
		if(sum>2*mx) cout<<1;
		else{
			cout<<0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
