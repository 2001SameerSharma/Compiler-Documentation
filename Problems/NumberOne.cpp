#include <bits/stdc++.h>
using namespace std;


enum OpKind{
    matmul,
    add,
    sub,
    relu,
    conv,
    cnstnt,
    identity,
    transpose
};

enum DType {
    f32, f16, i8, unkown
};


struct Tensor{
    unordered_map<int, float> tensor;
};

struct Shape{
    vector<int64_t> dims;
};


struct TensorType{
    Shape shape;
    DType dtype{DType::unknown};
};


struct Node;

struct Edge{
    Node* from;
    Node* to;
    int input_idx;
    Tensor tensor;
};


struct Node{
    string name;
    OpKind opkind{OpKind::identity};
    vector<Edge*> uses;
    vector<Edge*> defs;
    vector<TensorType> inputs;
    vector<TensorType> outputs;
    unordered_map<string, string> attrs;
};









int main() {
	// your code goes here

}
