#include <bits/stdc++.h>
using namespace std;


/*
The OpKind enum is used to represnet which operation we will be running at a particular nodec in the graph.
*/

enum OpKind{
    MATMUL,
    ADD,
    SUB,
    RELU,
    CONV,
    CONSTANT,
    IDENTITY,
    TRANSPOSE
};


/*
The DType enum is used to determine if the values in the tensor are 32 bit floating points, 16 bit floating points, 8 bit integers or unkown.
*/

enum DType {
    F32, F16, I8, UNKNOWN
};


/*
The Tensor struct holds the values of the tensor itself. It uses a single float array to hold each value in the tensor, and we will use shape to determine the actual shape of the tensor.
*/

struct Tensor{
    vector<float> data;
};


/*
The shape struct represents the shape of a tensor. Index i in the vector represents the i+1th dimension of the tensor, and the value in the vector at i represents the size of that dimension on the tensor.
*/

struct Shape{
    vector<int64_t> dims;
};


/*
The Tensor Type struct is a struct that we use to hold data about the tensor. We have two datatypes shape, and DType. DType is an enum that defines which type of floating point or integer we are using for the data inside the tensor. Shape is used fro use to define an array that carries a value that represents the length of our tennsor for the corresponding dimension of that value in the dimensions array.
*/

struct TensorType{
    Shape shape;
    DType dtype{DType::UNKNOWN};
};


/*We need to initialize the Node struct before we use it in the Edge struct.*/

struct Node;

/* 
The Edge struct represents a tensor itself. It has a pointer to the Node it cacme from and goes to. It has an int that represents which index in the input array it is of the Node that it goes to. This is also where we will store the literal tensor's data onccce we actually build the graph.
*/


struct Edge{
    Node* from;
    Node* to;
    int input_idx;
    Tensor tensor;
};




/*
The computation graph exists as a deterministic traversal of operations on tensors. Each node is an operation and eacch edge is a tensor. The Node struct is used to represent the node itself, and carry all of the data that we will need to use in our futute ccompiler passes. It holds a name string which represents the node's identity. It holds an opKind enum which represents the type of operation we will be running in this node. It holds an Edge* vector for uses and defs which means it shows which Edge's are being used by data collected at this stage of the graph, and it shows which data this stage of the graph is dependent upon. The inputs and outputs vectors hold data about the tensors themselves that are in those uses and defs. We finally build a attrs unordered_map. We will use this for any attributes that we need to manually add. Each attribute itself will have a name and a value.

*/

struct Node{
    string name;
    OpKind opkind{OpKind::IDENTITY};
    vector<Edge*> uses;
    vector<Edge*> defs;
    vector<TensorType> inputs;
    vector<TensorType> outputs;
    unordered_map<string, string> attrs;
};









int main() {
	// your code goes here

}
