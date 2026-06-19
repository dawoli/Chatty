#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,logn;
int capbility[100010],attendant[100010];
int power_two[100];
string rule[19];
int T;
int ability[100010];
int powerTwoInit(){
	power_two[0] = 1;
	int i = 1;
	while(power_two[i - 1] < n){
		power_two[i] = power_two[i - 1] * 2;
		i++;
	}
	return i - 1;
}
struct unsure{
	int known_team[100];
	int helper_sum;
}fighter[200000];
unsure op(int r,unsure fighter0,unsure fighter1,int opr){
	int nu = 0;
	unsure afldsjnb=(unsure){ {} , 0};
	
	if(opr == 1){
		unsure tmp = fighter1;
		fighter1 = fighter0;
		fighter0 = tmp;
	}
	bool flag = 0;
	for(int i = 0;fighter0.known_team[i] != 0;i++){
		if(ability[fighter0.known_team[i]] >= r) afldsjnb.known_team[nu++] = fighter0.known_team[i];
		else{
			flag = 1;
		}
	}
	if(fighter0.helper_sum != 0){
		flag = 1;
		afldsjnb.helper_sum = fighter0.helper_sum;
	}
	if(flag){
		for(int i = 0;fighter1.known_team[i] != 0;i++){
			afldsjnb.known_team[nu++] = fighter1.known_team[i];
		}
		afldsjnb.helper_sum += fighter1.helper_sum;
	}
	return afldsjnb;
}
int work(int item){
	memset(fighter,sizeof(fighter),0);
	int race = ceil(log2(attendant[item]));
	for(int j = 1;j <= power_two[race];j++){
		if(j <= attendant[item]) fighter[j] = (unsure){ {j} , 0 };
		else fighter[j] = (unsure){ {} , j };
	}
	for(int r = 1;r <= race;r++){
		for(int j = 0;j < power_two[race-r];j++){
			fighter[1+j*power_two[r]] = op(r,fighter[1+j*power_two[r]],fighter[1+j*power_two[r]+power_two[r-1]],rule[r][j]-'0');
		}
	}
	int sum=fighter[1].helper_sum;
	for(int i = 0;fighter[1].known_team[i] != 0;i++){
		sum += fighter[1].known_team[i];
	}
	return sum;
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>capbility[i];
	for(int i = 1;i <= m;i++) cin>>attendant[i];
	logn = powerTwoInit();
	for(int i = 1;i <= logn;i++) cin>>rule[i];
	cin>>T;
	while(T--){
		int change[4],answer = 0;
		cin>>change[0]>>change[1]>>change[2]>>change[3];
		for(int i = 1;i <= n;i++){
			ability[i] = capbility[i] ^ change[i%4];
		}
		for(int i = 1;i <= m;i++){
			int temp = work(i);
			answer = answer ^ (i * temp);
		}
		cout<<answer<<endl;
	}
	return 0;
}

