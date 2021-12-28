#include <bits/stdc++.h>
#include "algo.h"
using namespace std;

typedef long long ll;

const int maxn = 1e6 + 2;

template<typename A>
struct SquareRootDecomposition{

    vector<A> array;
    vector<A> tree;
    A block_size;

    SquareRootDecomposition(int n){
        block_size = sqrt(n) + (sqrt(n) != (int)sqrt(n));
        array.resize(n + 1);
        tree.resize(block_size + 1);
    }

    A func(A a, A b){
        if(a < b){
            return a;
        }
        else{
            return b;
        }
    }

    void build(int n){
        for(int i = 1; i <= n; ++i){
            int rest = (i % block_size != 0);
            tree[i / block_size + rest] = array[i];
        }
        for(int i = 1; i <= n; ++i){
            int rest = (i % block_size != 0);
            tree[i / block_size + rest] = func(tree[i / block_size + rest], array[i]);
        }
        return;
    }

    A get(int l, int r){
        A minimum = array[l];
        for(int i = l; i <= r; ++i){
            if(i % block_size == 1 && i + block_size - 1 <= r){
                minimum = func(minimum, tree[i / block_size + 1]);
                i += (block_size - 1);
            }
            else{
                minimum = func(minimum, array[i]);
            }
        }

        return minimum;  
    }

};


int n, m;
int initial_array[maxn];
int left_index[maxn];
int right_index[maxn];

void find_minimum(){

    std::ifstream input_file;
    std::ofstream output_file;
    
    input_file.open("./test.in");
    output_file.open("./test.out");

    input_file >> n >> m;

    for(int i = 1; i <= n; ++i){
        input_file >> initial_array[i];
    }

    for(int i = 1; i <= m; ++i){
        input_file >> left_index[i] >> right_index[i];
    }

    SquareRootDecomposition<int> sqd(n);
    for(int i = 1; i <= n; ++i){
        sqd.array[i] = initial_array[i];
    }
    sqd.build(n);
    for(int i = 1; i <= m; ++i){
        output_file << sqd.get(left_index[i], right_index[i]) << '\n';
    }

    return;
}