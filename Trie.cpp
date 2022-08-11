template <typename T, int B = 30>
struct Trie {
    struct node {
        array<T, 2> ch;
        node() : ch{} {}
    };
    vector<node> tree;
    Trie() { new_node(); }
 
    int new_node() {
        tree.emplace_back();
        return tree.size() - 1;
    }
    void insert(const T& s) {
        int p = 0;
        for (int i = B; i >= 0; i--) {
            int b = s >> i & 1;
            if (!tree[p].ch[b]) {
                tree[p].ch[b] = new_node();
            }
            p = tree[p].ch[b];
        }
    }
    bool find(const T& s) {
        int p = 0;
        for (int i = B; i >= 0; i--) {
            int b = s >> i & 1;
            if (!tree[p].ch[b]) {
                return false;
            } 
            p = tree[p].ch[b];
        }
        return true;
    }
    int max(int start) {
        int p = 0;
        for (int i = B; i >= 0; i--) {
            int b = start >> i & 1;
            if (tree[p].ch[b ^ 1]) {
                start ^= ((b ^ 1) << i);
                p = tree[p].ch[b ^ 1];
            } else {
                start ^= ((b) << i);
                p = tree[p].ch[b];
            }
        }
        return start;
    }
    int min(int start) {
        int p = 0;
        for (int i = B; i >= 0; i--) {
            int b = start >> i & 1;
            if (tree[p].ch[b]) {
                start ^= ((b) << i);
                p = tree[p].ch[b];
            } else {
                p = tree[p].ch[b ^ 1];
                start ^= ((b ^ 1) << i);
            }
        }
        return start;
    }
};