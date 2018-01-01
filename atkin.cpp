#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
#define MAX_N (1<<30)

bool prime[MAX_N+1];

void sieve_of_atkin(int N){
	double sqrtN = sqrt(N);
	int n;
	for(int z = 1; z <= 5; z += 4){
		for(int y = z; y <= sqrtN; y+= 6){
			for(int x = 1; x <= sqrtN && (n = 4*x*x+y*y) <= N; x++){
				prime[n] ^= true;
			}
			for(int x = y+1; x <= sqrtN && (n = 3*x*x-y*y) <= N; x+=2){
				prime[n] ^= true;
			}
		}
	}
	for(int z = 2; z <= 4; z += 2){
		for(int y = z; y <= sqrtN; y+= 6){
			for(int x = 1; x <= sqrtN && (n = 3*x*x+y*y) <= N; x+= 2){
				prime[n] ^= true;
			}
			for(int x = y+1; x <= sqrtN && (n = 3*x*x-y*y) <= N; x += 2){
				prime[n] ^= true;
			}
		}
	}
	for(int y = 3; y <= sqrtN; y += 6){
		for(int z = 1; z <= 2; z++){
			for(int x = z; x <= sqrtN &&(n = 4*x*x+y*y) <= N; x += 3){
				prime[n] ^= true;
			}
		}
	}
	for(n = 5; n <= sqrtN; n++){
		if(prime[n]){
			for(int k = n*n; k <= N; k+=n*n){
				prime[k] = false;
			}
		}
	}
	prime[2] = prime[3] = true;
}

int main(){
	int n;
	cin>>n;
	sieve_of_atkin(n);
	cout<<prime[n]<<endl;
	return 0;
}
