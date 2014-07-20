//typedef struct UF{
//	int id[MAP_VERTICAL * MAP_HORIZONTAL]; // parent of i
//	int sz[MAP_VERTICAL * MAP_HORIZONTAL]; // size
//	int count;
//
//	void init(){
//		count = MAP_VERTICAL * MAP_HORIZONTAL;
//		for (int i = 0; i < MAP_VERTICAL * MAP_HORIZONTAL; i++){
//			id[i] = 0;
//			sz[i] = 1;
//		}
//	}
//
//	int find(int p){
//		int root = p;
//		while (root != id[root]){
//			root = id[root];
//		}
//		while (p != root){
//			int newp = id[p];
//			id[p] = root;
//			p = newp;
//		}
//		return root;
//	}
//
//	bool find(int p, int q){
//		return this->find(p) == this->find(q);
//	}
//
//	void connect(int p, int q){
//		int rootP = this->find(p);
//		int rootQ = this->find(q);
//		if (rootP == rootQ) return;
//		if (sz[rootP] < sz[rootQ]){
//			id[rootP] = rootQ;
//			sz[rootQ] += sz[rootP];
//		}
//		else{
//			id[rootQ] = rootP;
//			sz[rootP] = rootQ;
//		}
//		count--;
//	}
//
//	void show(){
//		for (int i = 0; i < (MAP_VERTICAL * MAP_HORIZONTAL); i++){
//			if (i % MAP_HORIZONTAL == 0){
//				printf("\n");
//			}
//			printf("%d ", id[i]);
//		}
//	}
//};


