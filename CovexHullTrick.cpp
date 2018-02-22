struct CHT{
	CHT(){
		ls.insert({L(INF, 0), L(-INF, 0)});
		ps.insert(cp(L(INF, 0), L(-INF, 0)));
	};
	ll get(ll x){
		const L &l = (--ps.lower_bound(C(x, 1, L(0, 0))))->l;
		return l.a*x+l.b;
	}
	void add(ll a, ll b){
		const L l(a, b);
		auto it = ls.insert(l).fst;
		if(check(*it_last(it), l, *it_next(it))){
			ls.erase(it);
			return;
		}
		ps.erase(cp(*it_last(it), *it_next(it)));
		{
			auto it2 = it_last(it);
			while(it2!=ls.begin()&&check(*it_last(it2), *it2, l)) --it2;
			erase(it2, it_last(it));
			ls.erase(++it2, it);
			it = ls.find(l);
		}
		{
			auto it2 = it_next(it);
			while(it_next(it2)!=ls.end()&&check(l, *it2, *it_next(it2))) ++it2;
			erase(++it, it2);
			ls.erase(it, it2);
			it = ls.find(l);
		}
		ps.insert(cp(*it_last(it), *it));
		ps.insert(cp(*it, *it_next(it)));
	}
	private:
	template<class T> T it_next(T a){return ++a;}
	template<class T> T it_last(T a){return --a;}
	struct L{
		ll a, b;
		L(ll a, ll b):a(a),b(b){};
		bool operator<(const L &l) const {
			return a!=l.a?a>l.a:b<l.b;
		}
	};
	struct C{
		ll n, d;
		L l;
		C(ll n2, ll d2, const L &l):n(n2),d(d2),l(l){
			if(d<0){n *= -1; d *= -1;}
		};
		bool operator<(const C &p) const {
			if(n==INF||p.n==-INF) return 0;
			if(n==-INF||p.n==INF) return 1;
			return n*p.d<p.n*d;
		}
	};
	set<L> ls;
	set<C> ps;
	bool check(const L &l1, const L &l2, const L &l3){
		if(l1.a==l2.a&&l1.b<=l2.b) return 1;
		if(l1.a==INF||l3.a==-INF) return 0;
		return (l2.a-l1.a)*(l3.b-l2.b)>=(l2.b-l1.b)*(l3.a-l2.a);
	}
	void erase(set<L>::iterator it1, set<L>::iterator it2){
		for(auto it = it1; it != it2; ++it) ps.erase(cp(*it, *it_next(it)));
	}
	C cp(const L &l1, const L &l2){
		if(l1.a==INF) return C(-INF, 1, l2);
		if(l2.a==-INF) return C(INF, 1, l2);
		return C(l1.b-l2.b, l2.a-l1.a, l2);
	}
};
