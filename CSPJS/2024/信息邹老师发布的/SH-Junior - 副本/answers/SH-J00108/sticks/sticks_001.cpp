#include <bits/stdc++.h>
using namespace std;
int cost[10]={6,2,5,5,4,5,6,3,7,6},n,T;
struct node{
	int cnt[10];
	bool operator<(const node&n) const{							//O(10)
		int f1=0,f2=0,s1=0,s2=0;
		for (int i=0;i<=9;++i) s1+=cnt[i],s2+=n.cnt[i]; 
		if (s1<s2) return true;
		if (s1>s2) return false;
		for (int i=1;i<=9;++i) if (cnt[i]!=0){f1=i;break;}
		for (int i=1;i<=9;++i) if (n.cnt[i]!=0){f2=i;break;}
		if (f1<f2&&f1!=0) return true;
		if (f1>f2||f1==0) return false;
		for (int i=0;i<=9;++i){
			if (cnt[i]<n.cnt[i]) return false;
			if (cnt[i]>n.cnt[i]) return true;
		}
		return false;
	}
};
void cpy(int *a,int *b){
	for (int i=0;i<=9;++i) a[i]=b[i];
}
node tmp;
node f[100009];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for (int i=1;i<=100000;++i) for (int k=0;k<=9;++k) f[i].cnt[k]=0;
	f[2].cnt[1]=1;f[3].cnt[7]=1;f[4].cnt[4]=1;f[5].cnt[2]=1;f[6].cnt[6]=1;f[7].cnt[8]=1;f[8].cnt[1]=1;f[8].cnt[0]=1;
	for (int i=9;i<=100000;++i){				//O(1e5)
		f[i].cnt[9]=1e7;
		for (int k=0;k<=9;++k){					//O(10)
			cpy(tmp.cnt,f[i-cost[k]].cnt);
			tmp.cnt[k]++;
			f[i]=min(f[i],tmp);					//O(20) 
		} 
	}
	for (int q=1;q<=T;++q){						//O(T)
		cin>>n;
		if (n==1) cout<<-1<<endl;
		else{
			int h=0;
			for (int i=1;i<=9;++i) if (f[n].cnt[i]!=0){h=i;break;}
			printf("%d",h);f[n].cnt[h]--;
			for (int i=0;i<=9;++i) for (int a=1;a<=f[n].cnt[i];++a) printf("%d",i);
			f[n].cnt[h]++;
			printf("\n");						//O(N/8)
		}
	}
	//O(NT/8+2e7)
	fclose(stdin);fclose(stdout);
	return 0;
}
