#include<bits/stdc++.h>
#define endl '\n'
#define MAX 1000010
typedef long long ll;
using namespace std;

bitset<MAX> bits;
int primes[MAX];

void LeastPrimeDivisor(){
    primes[0]=INT_MIN; //bcz u use prime[0] in operation
    primes[1]=1;
	for(int i=2; i<MAX; i+=2)	primes[i] = 2;//even numbers have smallest prime factor 2
	for(ll i=3; i<MAX; i+=2){
		if(!bits[i]){
			primes[i] = i;
			for(ll j=i; (j*i)<MAX; j+=2){
				if(!bits[j*i]){
                    bits[j*i] = true;
                    primes[j*i] = i;
                }
			}
		}
	}
}

int operation(int q1, int q2){ return max(primes[q1], primes[q2]); }

int querySegTree(int tree[], int treeIndex, int lo, int hi, int i, int j){ //[i,j] is the range/interval querying
    if(tree[treeIndex]==1)
        return 1;

    if(lo > j || hi < i)               // segment completely outside range
        return 0;                       // represents a null node equivalent to storing zero

    if(i <= lo && j >= hi)             // segment completely inside range
        return tree[treeIndex];

    int mid = lo + (hi - lo)/2;       // partial overlap of current segment and queried range. Recurse deeper.

    int leftQuery = querySegTree(tree, 2*treeIndex + 1, lo, mid, i, j);
    int rightQuery = querySegTree(tree, 2*treeIndex + 2, mid+1, hi, i, j);

    return operation(leftQuery, rightQuery);
}


void updateRangeSegTree(int tree[], int treeIndex, int lo, int hi, int l, int r){ //[l,r] is the range/interval updating
    if(tree[treeIndex]==1)
        return;

    if (lo > r || hi < l) // out of range
        return;
    
    if (lo == hi){ // Current node is a leaf node
        tree[treeIndex] /= primes[tree[treeIndex]];
        return;
    }

    int mid = lo + (hi - lo)/2;   // recurse deeper for appropriate child
    updateRangeSegTree(tree, treeIndex*2 + 1, lo, mid, l, r);
    updateRangeSegTree(tree, treeIndex*2 + 2, mid + 1, hi, l, r);

    // Use the result of children calls to update this node
    tree[treeIndex] = operation(tree[treeIndex*2 + 1], tree[treeIndex*2 + 2]);
}

void buildSegTree(int arr[], int *tree, int treeIndex, int lo, int hi){
    if(lo == hi){                 // leaf node. store value in node.
        tree[treeIndex] = arr[lo];
        return;
    }
    int mid = lo + (hi - lo) / 2;   // recurse deeper for children.
    buildSegTree(arr, tree, 2*treeIndex + 1, lo, mid);
    buildSegTree(arr, tree, 2*treeIndex + 2, mid + 1, hi);

    tree[treeIndex] = operation(tree[2*treeIndex + 1], tree[2*treeIndex + 2]);
}

int *constructST(int arr[], int n){
	int x = (int)(ceil(log2(n)));
	int max_size = 2*(int)pow(2, x) - 1;
	int *SegTree = new int[max_size];

	buildSegTree(arr, SegTree, 0, 0, n-1);

	return SegTree;
}

void PrintTree(int *arr, int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    ios::sync_with_stdio(false);
    int tcs;
    LeastPrimeDivisor();
    //freopen("input.txt", "r", stdin);
    cin>>tcs;
    while(tcs--){
        int n,m;
        cin >> n >> m;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        int *SegTree = constructST(arr, n);
        while(m--){
            int l,r;
            bool type;
            cin >> type;
            if(type){
                cin >> l >> r;
                cout << querySegTree(SegTree, 0, 0, n-1, l-1, r-1) << " ";
            }else{
                cin >> l >> r;
                updateRangeSegTree(SegTree, 0, 0, n-1, l-1, r-1);
            }
        }
        cout << endl;
    }
    return 0;
}
