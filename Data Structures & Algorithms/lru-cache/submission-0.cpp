class LRUCache {
public:
    struct Node{
        int key, val;
        Node* prev;
        Node* next;

        Node(int key, int val) {
            this -> key = key;
            this -> val = val;
        }
    };

    Node* head;
    Node* tail;
    int capacity;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        this -> capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
    }

    void deleteNode(Node* node) {
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
    }

    void addNode(Node* node) {
        node -> next = head -> next;
        node -> prev = head;
        head -> next -> prev = node;
        head -> next = node;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            Node* node = mp[key];
            deleteNode(node);
            addNode(node);
            return node -> val;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            Node* node = mp[key];
            deleteNode(node);
            mp.erase(key);
        }
        Node* node = new Node(key, value);
        addNode(node);
        mp[key] = node;
        if(mp.size() > capacity) {
            Node* lru = tail -> prev;
            mp.erase(lru -> key);
            deleteNode(lru);
        }
    }
};
