int RomanToArabic(string s){
	int len = s.size(),a,b = 100000000,ans = 0;
	for(int i = 0; i < len; i++){
		if(s[i] == 'I') a = 1;
		if(s[i] == 'V') a = 5;
		if(s[i] == 'X') a = 10;
		if(s[i] == 'L') a = 50;
		if(s[i] == 'C') a = 100;
		if(s[i] == 'D') a = 500;
		if(s[i] == 'M') a = 1000;
		
		ans += a;
		if(a>b) ans -= 2*b;
		b = a;
	}
	return ans;
}