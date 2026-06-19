 #include<bits/stdc++.h>
 using namespace std;
 int D[60], C[60], H[60], S[60];
 
 int main(){
 	freopen("poker.in", "r", stdin);
 	freopen("poker.out", "w", stdout);
 	long long n, res = 0;
 	scanf("%lld", &n);
 	while(n--){
 		char tmp1, tmp2;
 		cin >> tmp1 >> tmp2;
 		int num;
 		if(tmp2 == 'T'){
			num = 10;
		}else if(tmp2 == 'J'){
			num = 11;
		}else if(tmp2 == 'Q'){
			num = 12;
		}else if(tmp2 == 'K'){
			num = 13;
		}else if(tmp2 == 'A'){
			num = 1;
		}else{
			num = tmp2 - '0';
		}
		if(tmp1 == 'D'){
			D[num]++;
		}else if(tmp1 == 'C'){
			C[num]++;
		}else if(tmp1 == 'H'){
			H[num]++;
		}else{
			S[num]++;
		}
	}
	for(int i = 1;i <= 13;i++){
		if(D[i] == 0){
			res++;
		}
	}
	for(int i = 1;i <= 13;i++){
		if(C[i] == 0){
			res++;
		}
	}
	for(int i = 1;i <= 13;i++){
		if(H[i] == 0){
			res++;
		}
	}
	for(int i = 1;i <= 13;i++){
		if(S[i] == 0){
			res++;
		}
	}
 	printf("%lld", res);
 	fclose(stdin);
 	fclose(stdout);
 	return 0;
 }
