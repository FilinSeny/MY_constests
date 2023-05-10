#include <iostream>

using namespace std;


struct node {
    node *child_l, *child_r;
    int val, prior;
    node (int _val) {
        val = _val;
        y = rand();
        child_l = child_r = nullptr;

    }
    ~node() {
        delete child_l;
        delete child_r;
    }
};


pair <node *, node *> split(node *root, int cut_border) {
    if (!root) {
        return {nullptr, nullptr};
    }
    /*
    if (!root->child_l) {
        return {nullptr, child_r};
    }
    */
    if (cut_border < root->val) {
        auto p = split(root->child_l, cut_border);
        root->child_l = p.second;
        return {p.first, root};
    } else {
        auto p = split(root->child_r, cut_border);
        root->child_r = p.first;
        return {root, p.second};
    }
}


node *merge(node *root_1, node *root_2) {
    if (!root_1) return root_2;
    if (!root_2) return root_1;
    if (root_1->prior < root_2->prior) {
        root_1->child_r = merge(root_1->child_r, root_2);
        return root_1;
    } else {
        root_2->child_l = merge(root_1, root_2->child_l);
        return root_2;
    }
}


node *insert(node *root, int val) {
    if (!root) {
        return new node(val);
    }

    node *new_node(val);
    auto p = split(root, val);
    ///new_node->child_l = p.first;
    ///new_node->child_r = p.second;

    return merge(p.first, merge(new_node, p.second));
}


node *erase(node *root, int val) {
    if (!root) return root;
    auto p = split(root, val);
    auto q = split(p.second, val + 1);
    delete q.first;
    return merge(p.first, q.second);
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
