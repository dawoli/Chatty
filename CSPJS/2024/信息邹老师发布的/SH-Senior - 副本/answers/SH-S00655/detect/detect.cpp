#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"
const int N=100005;
int T,n,m,L,V,p[N],ans1,ans2,mined=1e13;
struct node{
	int d,v,a;
	double end,vmax,cs_st,cs_ed;//分别为 驶离位置  最大速度  超速开始的位置   超速结束的位置 
};
bool cmp(const node x,const node y){
	if (x.cs_st != y.cs_st) return x.cs_st < y.cs_st;
	else return x.cs_ed > y.cs_ed;
} 
node car[N];
int panduan1(int d,int v,int a,int i){
	if (car[i].vmax <= V){
		return L+1;
	}
	else if (car[i].v > V){
		return car[i].d;
	} 
	else{
		return d+(V * V - car[i].v * car[i].v) / (2 * car[i].a);
	} 
}//超速开始的位置，全程没超速的按L+1算 

int panduan2(int d,int v,int a,int i){
	if (car[i].a >= 0){
		return L+2;
	} 
	else if (car[i].vmax <= V){
		return L+2;
	}  
	else{
		return d+(V * V - car[i].v * car[i].v) / (2 * car[i].a);
	} //一段时间超速 
}//超速结束的位置
signed main(){
	cin >> T;
	while(T --){//从此开始--------------------------------------------------------------------------------------------------------------------------------------------
		cin >> n >> m >> L >> V;
		int bjj=0;
		ans1=0;ans2=1;mined=1e13; //重置  ans为至少所需的测速仪数量 
		for (int i=0;i<m;i++)p[i]=0;
		for (int i=0;i<n;i++){
			cin >> car[i].d >> car[i].v >> car[i].a;//读入
			//初步处理，得到cs_st和cs_ed 
			if (car[i].a == 0) {
				car[i].end = L; 
				car[i].vmax = car[i].v;
			}
			else if (car[i].a > 0){
				car[i].end = L; 
				car[i].vmax = sqrt(car[i].v * car[i].v + 2 * car[i].a * (L - car[i].d));
			}									  
			else if (car[i].v * car[i].v + 2 * car[i].a * (L-car[i].d)){
				car[i].end = L;
				car[i].vmax = car[i].v;
			} //以上三种可达终点 
			else   {
				car[i].end = -car[i].v * car[i].v / (2 * car[i].a);         
				car[i].vmax = car[i].v;
			}     
			car[i].cs_st = panduan1(car[i].d , car[i].v , car[i].a , i);
			car[i].cs_ed = panduan2(car[i].d , car[i].v , car[i].a , i);//超速位置处理 
		}
		for (int i=0;i<m;i++) cin >> p[i];//读入测速器 
		sort (p,p+m);
		sort (car,car+n,cmp);
		
	//	for (int i=0;i<n;i++)cout<<car[i].d<<" "<<car[i].v<<" "<<car[i].a<<" vmax="<<car[i].vmax<<" cs_st="<<car[i].cs_st<<" cs_ed="<<car[i].cs_ed<<endl;
		
		for (int i = 0;i < n;i ++){//开始结合处理 
			int bj = bjj;
			if (car[i].cs_st > L)continue;
			while (p[bj] < car[i].cs_st){
				bj++;
			}bjj = bj;//节约时间 
			if (p[bj] < car[i].cs_ed){
				ans1++;
			} //能测出超速 
			
			if (car[i].cs_st > mined){
				ans2++;mined=1e13;
			}
			if (car[i].cs_ed < mined)mined = car[i].cs_ed; 
		}
		cout << ans1 << " " << m-ans2 <<endl;
	}
	return 0;
}
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15

4
10 10 150307 247
62978 968 -5
51700 883 -3
40408 564 -1
60366 870 -41
35943 797 -7
47476 595 -11
59020 672 -10
81024 964 -11
80637 695 -5
66114 874 -1
46720 48066 57373 60882 68842 72773 82820 116695 122159 150307

10 10 145322 772
10139 897 -47
86524 947 -2
51251 982 -2
12573 962 -2
14068 919 -163
10944 994 -6
35650 999 -9
3804 977 -1
1149 905 -2
43935 932 -2
10519 11805 14747 28890 37732 45509 55779 80531 108392 126659

10 10 175391 226
31181 234 -546
32757 670 -9
43723 775 -3
78541 862 -4
26626 961 -13
54690 759 -998
56165 659 -3
56531 776 -34
32860 950 -6
86709 145 47
31182 33025 46753 52673 57685 60635 99569 124240 162898 170704

10 10 25320 235
6591 945 -38
23654 277 -6
12793 859 -39
12032 762 -27
5568 739 -122
8019 774 -21
14198 881 -36
10302 866 -25
23595 868 -209
7864 667 -31
6534 6885 8702 14146 14580 15785 20903 21785 24323 24366

10 7
10 6
9 6
10 6
*/
