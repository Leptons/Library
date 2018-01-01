#include <iostream>
#include <vector>
#include <complex>

typedef double Num;
typedef complex<double> Complex;
double PI = 3.14159265358979;

void fft_main(int n, Num theta, Complex *a){
	for(int m = n; m >= 2; m>>=1){
		int mh = m >> 1;
		Complex thetaI = Complex(0, theta);
		for(int i = 0; i < mh; i++){
			Complex w = exp((Num)i*thetaI);
			for(int j = i; j < n; j += m){
				int k = j+mh;
				Complex x = a[j] - a[k];
				a[j] += a[k];
				a[k] = w * x;
			}
		}
		theta *= 2;
	}
	int i = 0;
	for(int j = 1; j < n-1; j++){
		for(int k = n >> 1; k > (i ^= k); k >>= 1);
		if(j < i) swap(a[i], a[j]);
	}
}

void fft(int n,  Complex *a){ fft_main(n, 2*PI/n, a); }
void ifft(int n, Complex *a){ fft_main(n, -2*PI/n, a); }

void convolution(vector<Complex> &v, vector<Complex> &w){
	int n = 1, vwn = v.size() + w.size() - 1;
	while(n < vwn) n <<= 1;
	v.resize(n); w.resize(n);
	fft(n, &v[0]);
	fft(n, &w[0]);
	for(int i = 0; i < n; i++) v[i] *= w[i];
	ifft(n, &v[0]);
	for(int i = 0; i < n; i++) v[i] /= n;
}

void trans(int n, int m, vector<vector<Complex> > &a){
	vector<vector<Complex> > b(m, vector<Complex> (n));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			b[j][i] = a[i][j];
	a.swap(b);
}

void fft2_main(int n, int m, Num theta1, Num theta2, vector<vector<Complex> > &a){
	for(int i = 0; i < n; i++) fft_main(n, theta1, &a[i][0]);
	trans(n, m, a);
	for(int i = 0; i < m; i++) fft_main(m, theta2, &a[i][0]);
	trans(m, n, a);
}

void fft2(int n, int m, vector<vector<Complex> > &a){ fft2_main(n, m, 2*PI/n, 2*PI/m, a); }
void ifft2(int n, int m, vector<vector<Complex> > &a){ fft2_main(n, m, -2*PI/n, -2*PI/m, a); }

void convolution2(vector<vector<Complex> > &v, vector<vector<Complex> > &w){
	int n = 1, vwn = v.size()+w.size()-1, m = 1, vwm = v[0].size()+w[0].size()-1;
	while(n < vwn) n <<= 1;
	while(m < vwm) m <<= 1;
	v.resize(n); w.resize(n);
	for(int i = 0; i < n; i++)
		v[i].resize(m), w[i].resize(m);
	fft2(n, m, v);
	fft2(n, m, w);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			v[i][j] *= w[i][j];
	ifft2(n, m, v);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			v[i][j] /= n*m;
}
