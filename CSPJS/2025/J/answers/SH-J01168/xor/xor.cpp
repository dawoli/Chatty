#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[150000];
int mkb[150000];
int checksum=0;
int cs2=0;
void solveA(){
	cout << n/2;
}
void solveB(){//k=0 Lianggebianyige
	int ans=0;
	
	for (int i=1; i<=n; i++){
		if (a[i]==0){
			ans++;
		}
		if (a[i]==1 && a[i+1]==1 && mkb[i]+mkb[i+1]==0){
			ans++;
			mkb[i]=1;
			mkb[i+1]=1;
		}
	}
	cout << ans;
}
void solveB2(){//k=1 Shiijiushibushijiubushi
	int ans=0;
	for (int i=1; i<=n; i++){
		if (a[i]==1) ans++;
	}
	cout << ans;
}
int f[150000];
struct node{
	int l,r;
};
bool cmp(node a, node b){
	return a.r<b.r;
}
node seg[150000];
int ava[150000];//1=Used
void solveC(){//Zhen Pian Kai Shi!!!!!!!!!!
	int ans=0;
	int x=0;
	for (int i=1; i<=n; i++){
		f[i]=f[i-1]^a[i];
	}
	for (int i=1; i<=n; i++){
		for (int j=i; j<=n; j++){
			int u=(f[j])^(f[i-1]);
			if (u==k){
				x++;
				seg[x]={i,j};
				//cout << seg[x].l << " " << seg[x].r << " " << (u) << endl;
			}
		}
	}
	//cout << "---\n";
	sort(seg+1,seg+x+1,cmp);
	for (int i=1; i<=x; i++){
		int flag=1;
		for (int j=seg[i].l; j<=seg[i].r; j++){
			if (ava[j]==1){
				flag=0;
				break;
				
			}
		}
		if (flag==1){
			ans++;
			for (int j=seg[i].l; j<=seg[i].r; j++){
				ava[j]=1;
			}
			//cout << seg[i].l << " " << seg[i].r << endl;
		}
	}
	cout << ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i=1; i<=n; i++){
		cin >> a[i];
		if (a[i]!=1){
			checksum++;
		}
		if (a[i]>1){
			cs2++;
		}
	}
	if (checksum==0 && k==0){
		solveA();
	}else if (k==0 && cs2==0){
		solveB();
	}else if (k==1 && cs2==0){
		solveB2();
	}else{
		solveC();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
9:20 100% I can't 100 Pts
A: All A_i=1? if k>=2 Jst 0 
			  K=1 One to 1 
			  k=0 2 to 1 
			  +10
B: Doing A_i=0 or 1?? All Of them Is K=1 Or K=0 
						For K=1: All 1s Are Single, 0s Are Useless
						For K=0: (?) Try To Use 1 ^ 1=0 And 0
						+20
1-12: First Search All Of them We Can Use qianzhuihe since a xor b xor b=a f[i]=f[i-1] xor a[i] 
a[i] xor .. a[j] = f[j]-f[i-1] OHHHHHHHHHHH  
Try Them All Out then Use Greedy To Sort All Of them Using End S-L + Start S-L
Finnally, Try them And We Get O(n^2)? HopeFully 
Expected: TaskPoints 1-13 65 Pts. 
Write Later. So Complicateed See T4 
Now 9:31 Still Enugh Time
Now 10:07 I have more than enough? To finnish Greedy!
But For 100% Proof I will SolveA SolveB solveC 
I Hope No Dayishijingzhou
10:08 Continue this. 
10:27 Finsh A,B
10:47 Kai!Tiao!
10:54 I DID IT !!!!!!!!!!!!!!! 
10:57 Back From WC, 2nd Full Check!
11:00 Found T3 Have No Freopen
11:09 Checked Freopen. Sample Passed


*/
