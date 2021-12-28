#include <bits/stdc++.h>
#include "algo.h"
using namespace std;

typedef long long ll;

const int maxn = 1e6 + 2;

template<typename A>
struct SegmentTree{
    vector<A> array;
    vector<A> tree;

    SegmentTree(int n){
        array.resize(n + 1);
        tree.resize(4 * (n + 1) + 1);
    }

    A func(A a, A b){
        if(a < b){
            return a;
        }
        else{
            return b;
        }
    }

    void build(int node, int l, int r){
        if(l == r){
            tree[node] = array[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        tree[node] = func(tree[node * 2], tree[node * 2 + 1]);
        return;
    }

    void update(int node, int l, int r, int x){
        if(r < x || l > x)return;
        if(l == r){
            tree[node] = array[l];
            return;
        }
        int mid = l + (r - l) / 2;
        update(node * 2, l, mid, x);
        update(node * 2 + 1, mid + 1, r, x);
        tree[node] = func(tree[node * 2], tree[node * 2 + 1]);
        return;
    }

    A get(int node, int l, int r, int L, int R){
        if(l >= L && r <= R){
            return tree[node];
        }
        int mid = l + (r - l) / 2;
        if(mid < L){
            return get(node * 2 + 1, mid + 1, r, L, R);
        }
        if(mid >= R){
            return get(node * 2, l, mid, L, R);
        }
        return func(get(node * 2, l, mid, L, R), get(node * 2 + 1, mid + 1, r, L, R));
    }
};

int n, m;
int initial_array[maxn];
int left_index[maxn];
int right_index[maxn];
char comanda[maxn];

void find_minimum(){

    std::ifstream input_file;
    std::ofstream output_file;
    
    input_file.open("./test.in");
    output_file.open("./test.out");

    input_file >> n >> m;

    int make_updates = 0; // Make this 1 if you want to apply updates during the interaction

    for(int i = 1; i <= n; ++i){
        input_file >> initial_array[i];
    }

    for(int i = 1; i <= m; ++i){
        if(make_updates){
            input_file >> comanda[i];
        }
        input_file >> left_index[i] >> right_index[i];
    }

    SegmentTree<int> segment_tree(n);
    for(int i = 1; i <= n; ++i){
        segment_tree.array[i] = initial_array[i];
    }
    segment_tree.build(1, 1, n);
    for(int i = 1; i <= m; ++i){
        if(make_updates){
            if(comanda[i] == 'U'){
                segment_tree.array[left_index[i]] = right_index[i];
                segment_tree.update(1, 1, n, left_index[i]);
            }
            else{
                output_file << segment_tree.get(1, 1, n, left_index[i], right_index[i])  << '\n';
            }
            continue;
        }
        output_file << segment_tree.get(1, 1, n, left_index[i], right_index[i]) << '\n';
    }
    return;
}