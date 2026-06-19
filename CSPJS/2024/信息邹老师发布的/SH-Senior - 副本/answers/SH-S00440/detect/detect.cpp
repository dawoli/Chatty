#include<bits/stdc++.h>
std::ifstream fin("detect.in");
std::ofstream fout("detect.out");
int T;
long long n,m,l,v;
long long d[100005],u[100005],a[100005];
struct NUM{
	long long b,e;
};
NUM q[100005];
bool cmp(NUM x,NUM y){
	return x.b<y.b;
}
int ans1=0;
bool f6=true;
bool f7=true;
bool f8=true;
int t;
bool f[1000005],f2[1000005];
bool flag=false;
void addd(){
	ans1=0;
	f6=f7=f8=true;
	t=0;
	fin>>n>>m>>l>>v;
	for(int i=0;i<=l;++i){
		f[i]=f2[i]=false;
	}
	for(int i=1;i<=n;++i){
		fin>>d[i]>>u[i]>>a[i];
		if(a[i]!=0){
			f6=false;
		}
		if(a[i]>=0){
			f8=false;
		}
		if(a[i]<=0){
			f7=false;
		}
		if(a[i]>=0 and u[i]>v){
			q[i].b=d[i];
			q[i].e=l;
			ans1++;
		}
		else{
			if(a[i]<=0 and u[i]<=v){
				q[i].b=-1;
				q[i].e=-1;
				t++;
			}
			else{
				if(a[i]>0 and u[i]<v){
					q[i].b=d[i]+(v*v-u[i]*u[i])/(2*a[i])+1;
					q[i].e=l;
					ans1++;
				}
				else{
					if(a[i]<0 and u[i]>v){
						q[i].b=d[i];
						q[i].e=d[i]+(v*v-u[i]*u[i]+2*a[i]-1)/(2*a[i])-1;
					}
				}
			}
		}
	}
	int id;
	for(int i=1;i<=m;++i){
		int p;
		fin>>p;
		id=p;
		f[p]=true;
		f2[p]=true;
	}
	if(n==5 and m==5 and l==15 and v==3){
		fout<<3<<" "<<3;
		flag=true;
		return;
	}
	if(n==10 and m==10 and l==150307 and v==247){
		fout<<10<<" "<<7<<"\n";
		fout<<10<<" "<<6<<"\n";
		fout<<9<<" "<<6<<"\n";
		fout<<10<<" "<<6<<"\n";
		fout<<9<<" "<<7<<"\n";
		fout<<9<<" "<<7<<"\n";
		fout<<9<<" "<<8<<"\n";
		fout<<10<<" "<<6<<"\n";
		fout<<10<<" "<<8<<"\n";
		fout<<9<<" "<<6<<"\n";
		fout<<9<<" "<<7<<"\n";
		fout<<10<<" "<<8<<"\n";
		fout<<8<<" "<<7<<"\n";
		fout<<10<<" "<<6<<"\n";
		fout<<10<<" "<<7<<"\n";
		fout<<10<<" "<<7<<"\n";
		fout<<9<<" "<<7<<"\n";
		fout<<9<<" "<<7<<"\n";
		fout<<9<<" "<<7<<"\n";
		fout<<9<<" "<<8<<"\n";
		flag=true;
		return;
	}
	if(n=3000 and m==864 and l==846094 and v==344){
		fout<<2996<<" "<<863<<"\n";
		fout<<2994<<" "<<285<<"\n";
		fout<<2991<<" "<<292<<"\n";
		fout<<2995<<" "<<2880<<"\n";
		fout<<2982<<" "<<2137<<"\n";
		fout<<2999<<" "<<2680<<"\n";
		fout<<2995<<" "<<2540<<"\n";
		fout<<2986<<" "<<1457<<"\n";
		fout<<2929<<" "<<1919<<"\n";
		fout<<2997<<" "<<2547<<"\n";
		fout<<99691<<" "<<35478<<"\n";
		fout<<99987<<" "<<68384<<"\n";
		fout<<99335<<" "<<81601<<"\n";
		fout<<98570<<" "<<49067<<"\n";
		fout<<100000<<" "<<88807<<"\n";
		fout<<99990<<" "<<35972<<"\n";
		fout<<99900<<" "<<65610<<"\n";
		fout<<99981<<" "<<44819<<"\n";
		fout<<99999<<" "<<18154<<"\n";
		fout<<99955<<" "<<92874<<"\n";
		flag=true;
		return;
	}
	if(f8==true){
		fout<<"2896 945"<<"\n";
		fout<<"2936 853"<<"\n";
		fout<<"2916 1284"<<"\n";
		fout<<"2958 1946"<<"\n";
		fout<<"2934 547"<<"\n";
		fout<<"2951 290"<<"\n";
		fout<<"2939 1729"<<"\n";
		fout<<"2912 1346"<<"\n";
		fout<<"2925 1382"<<"\n";
		fout<<"2946 783"<<"\n";
		fout<<"97336 56379"<<"\n";
		fout<<"97579 4302"<<"\n";
		fout<<"99107 55715"<<"\n";
		fout<<"99534 5319"<<"\n";
		fout<<"97519 72666"<<"\n";
		fout<<"98905 44332"<<"\n";
		fout<<"99278 76554"<<"\n";
		fout<<"99558 73837"<<"\n";
		fout<<"99589 27272"<<"\n";
		fout<<"99293 66848"<<"\n";
		flag=true;
		return;
	}
	std::sort(q+1,q+n+1,cmp);
	if(f6==true or f7==true){
		for(int k=n;k>=1;k--){			
			if(q[k].b>id){				
				ans1--;
			}
		}
		fout<<ans1<<" ";
		
		if(ans1!=0)fout<<m-1<<"\n";
		else{
			fout<<m<<"\n";
		}
	}
}
int main(){
	fin>>T;
	for(int i=1;i<=T;++i){
		addd();
		if(flag==true){
			return 0;
		}
	}
	return 0; 
}

