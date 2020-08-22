#include <iostream>
using namespace std;

struct AVL_node{
    int data;
    AVL_node * left = NULL;
    AVL_node * right = NULL;
};
AVL_node * root = NULL;

int get_height(AVL_node * s){
    if(s == NULL){
        return 0;
    }
    int nl, nr;
    nl = get_height(s -> left);
    nr = get_height(s -> right);
    return (nl > nr ? nl : nr) + 1;
}

AVL_node * LL_Rotation(AVL_node * r){
    AVL_node * t = r -> left;
    r -> left = t -> right;
    t -> right = r;
    return t;
}

AVL_node * RR_Rotation(AVL_node * r){
    AVL_node * t = r -> right;
    r -> right = t -> left;
    t -> left = r;
    return t;
}

AVL_node * LR_Rotation(AVL_node * r){
    r -> left = RR_Rotation(r -> left);
    r = LL_Rotation(r);
    return r;
}

AVL_node * RL_Rotation(AVL_node * r){
    r -> right = LL_Rotation(r -> right);
    r = RR_Rotation(r);
    return r;
}

AVL_node * insert_avl(AVL_node * r, int s){
    if(!r){
        r = new AVL_node;
        r -> data = s;
        return r;
    }
    AVL_node * p = r;
    if(s < r -> data){
        r -> left = insert_avl(r -> left, s);
        if((get_height(r -> left) - get_height(r -> right)) == 2){
            if(s < r -> left -> data){
                //LL
                r = LL_Rotation(r);
            }else{
                //LR
                r = LR_Rotation(r);
            }
        }
    }else{
        r -> right = insert_avl(r -> right, s);
        if((get_height(r -> right) - get_height(r -> left)) == 2){
            if(s > r -> right -> data){
                //RR
                r = RR_Rotation(r);
            }else{
                //RL
                r = RL_Rotation(r);
            }
        }
    }
    return r;
}

int main(){
    int n, i, j;
    cin >> n;
    int s;

    for(i = 0; i < n; i++){
        cin >> s;
        root = insert_avl(root, s);
    }

    cout << root -> data;

    return 0;
}