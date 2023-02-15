class unionFind {
	int n;
	vector<int> parent;
	vector<int> sizeOf;
public:
	unionFind(int n) {
		this -> n = n;
		parent.resize(n);
		sizeOf.resize(n);
		for(int i = 0; i < n; i++) {
			parent[i] = i;
			sizeOf[i] = 1;
		}
	}

	int getParent(int x) {
		if(parent[x] == x)
			return x;
		return parent[x] = getParent(parent[x]);
	}

	int findSize(int x) {
		return sizeOf[x];
	}

	void performUnion(int x, int y) {
		int parentX = getParent(x);
		int parentY = getParent(y);
		if(parentX == parentY)
			return;

		if(sizeOf[parentX] > sizeOf[parentY]) {
			sizeOf[parentX] += sizeOf[parentY];
			parent[parentY] = parentX;
		} else {
			sizeOf[parentY] += sizeOf[parentX];
			parent[parentX] = parentY;
		}
	}
};
