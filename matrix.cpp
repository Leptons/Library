typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll mod = 1000000007;

mat mul(const mat& A, const mat& B){
	int n = A.size(), m = B[0].size(), l = A[0].size();
	mat C(n, vec(m, 0));
	for(int i = 0; i < n; i++)
		for(int k = 0; k < l; k++)
			for(int j = 0; j < m; j++)
				if(k&7==7 || k==l-1) (C[i][j]+=A[i][k]*B[k][j])%=mod; else C[i][j]+=A[i][k]*B[k][j];
	return C;
}

mat pow(const mat& A, ll m){
	int n = A.size();
	mat B(n, vec(n, 0)), C(A);
	for(int i = 0; i < n; i++) B[i][i] = 1;
	while(m){
		if(m&1) B = mul(B, C);
		C = mul(C, C);
		m >>= 1;
	}
	return B;
}

vec mul(const mat& A, const vec& b){
	int n = A.size(), m = A[0].size();
	vec c(n, 0);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			(c[i]+=A[i][j]*b[j])%=mod;
	return c;
}
