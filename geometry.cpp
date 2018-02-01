// intersection of segment (inclusive)
bool intersect(int i, int j, int k, int l){
	ll a = (x[k]-x[l])*(y[i]-y[k])+(y[k]-y[l])*(x[k]-x[i]);
	ll b = (x[k]-x[l])*(y[j]-y[k])+(y[k]-y[l])*(x[k]-x[j]);
	if(a*b>0) return false;
	ll c = (x[i]-x[j])*(y[k]-y[i])+(y[i]-y[j])*(x[i]-x[k]);
	ll d = (x[i]-x[j])*(y[l]-y[i])+(y[i]-y[j])*(x[i]-x[l]);
	return c*d<=0;
}
