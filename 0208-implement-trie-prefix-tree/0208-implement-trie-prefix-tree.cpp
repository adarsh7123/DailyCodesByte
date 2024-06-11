struct MyTrie {
    vector<vector<int>> tr;
    vector<bool> isWord;

    int root, id;

    void init() {
        root = 0;
        id = 1;
        tr.push_back(vector<int>(26, -1));
        isWord.push_back(false);
    }

    int newNode() {
        tr.push_back(vector<int>(26, -1));
        isWord.push_back(false);
        int newNode = id;
        id++;
        return newNode;
    }

    void add(string& s) {
        int u = root;
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            if (tr[u][c] == -1) {
                tr[u][c] = newNode();
            }

            u = tr[u][c];
        }
        isWord[u] = true;
    }

    int find(string& s) {
        int u = root;
        for (int i = 0; i < s.size() && u != -1; i++) {
            int c = s[i] - 'a';
            u = tr[u][c];
        }
        return u;
    }
};

class Trie {
public:
    MyTrie tr;
    Trie() { tr.init(); }

    void insert(string word) { tr.add(word); }

    bool search(string word) {
        int node = tr.find(word);
        return node != -1 && tr.isWord[node];
    }

    bool startsWith(string prefix) {
        int node = tr.find(prefix);
        return node != -1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */