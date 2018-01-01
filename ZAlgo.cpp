void ZAlgo(string &s, vector<int> &z){
	int n = s.size();
	z = vector<int>(n);
	z[0] = n;
	int i = 1, j = 0;
	while(i < n){
		while(i+j < n && s[j]==s[i+j]) j++;
		z[i] = j;
		if(j==0){
			i++;
			continue;
		}
		int k = 1;
		while(i+k < n && k+z[k]<j) z[i+k] = z[k], k++;
		i += k;
		j -= k;
	}
}
