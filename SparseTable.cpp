#include <bits/stdc++.h>
#include "algo.h"
using namespace std;

typedef long long ll;

const int maxn = 1e6 + 2;

template<typename A>
struct SparseTable{
    
    vector<vector<A>> matrix;
    vector<A> array;
    vector<A> log_values;
    
    SparseTable(int n){
        int max_log = 0, power = 1;
        while(power <= n){
            power <<= 1;
            ++max_log;
        }
        array.resize(n + 1);
        log_values.resize(n + 1);
        matrix.resize(n + 1);
        for(int i = 1; i <= n; ++i){
            matrix[i].resize(max_log);
        }
    }
    A func(A a, A b){
        if(a < b){
            return a;
        }
        else{
            return b;
        }
    }
    
    void build(int l, int r){
        int max_log = 0, power = 1;
        int n = r - l + 1;
        while(power <= n){
            power <<= 1;
            ++max_log;
        }
        int number = 0;
        power = 1;
        for(int i = 1; i <= n; ++i){
            while(power <= i){
                power <<= 1;
                ++number;
            }
            power >>= 1;
            --number;
            log_values[i] = number;
        }
        for(int j = 0; j < max_log; ++j){
            for(int i = l; i <= r - (1 << j) + 1; ++i){
                if(j == 0){
                    matrix[i][j] = array[i];
                    continue;
                }
                matrix[i][j] = func(matrix[i][j - 1], matrix[i + (1 << (j - 1))][j - 1]);
            }
        }
        return;
    }

    ll get(A start, A finish){
        ll distance = finish - start + 1;
        ll biggest_power = log_values[distance];
        return func(matrix[start][biggest_power], matrix[finish - (1 << biggest_power) + 1][biggest_power]);
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

    SparseTable<int> sparse_table(n);
    for(int i = 1; i <= n; ++i){
        sparse_table.array[i] = initial_array[i];
    }
    sparse_table.build(1, n);
    for(int i = 1; i <= m; ++i){
        output_file << sparse_table.get(left_index[i], right_index[i]) << '\n';
    }

    return;
}