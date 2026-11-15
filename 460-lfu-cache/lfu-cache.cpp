
class LFUCache {
public:

    class Node {
    public:
        int key, value, cnt;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            cnt = 1;
            prev = NULL;
            next = NULL;
        }
    };

    class List {
    public:
        int size;
        Node* head;
        Node* tail;

        List() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);

            head->next = tail;
            tail->prev = head;

            size = 0;
        }

        void addFront(Node* node) {
            Node* temp = head->next;

            node->next = temp;
            node->prev = head;

            head->next = node;
            temp->prev = node;

            size++;
        }

        void removeNode(Node* node) {
            Node* prevNode = node->prev;
            Node* nextNode = node->next;

            prevNode->next = nextNode;
            nextNode->prev = prevNode;

            size--;
        }

        Node* removeLast() {
            if(size == 0) return NULL;

            Node* node = tail->prev;
            removeNode(node);

            return node;
        }
    };

    int capacity;
    int minFreq;

    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqList;

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    void updateFreq(Node* node) {

        int oldFreq = node->cnt;

        freqList[oldFreq]->removeNode(node);

        if(oldFreq == minFreq && freqList[oldFreq]->size == 0) {
            minFreq++;
        }

        node->cnt++;

        if(freqList.find(node->cnt) == freqList.end()) {
            freqList[node->cnt] = new List();
        }

        freqList[node->cnt]->addFront(node);
    }

    int get(int key) {

        if(keyNode.find(key) == keyNode.end()) {
            return -1;
        }

        Node* node = keyNode[key];

        int value = node->value;

        updateFreq(node);

        return value;
    }

    void put(int key, int value) {

        if(capacity == 0) return;

        if(keyNode.find(key) != keyNode.end()) {

            Node* node = keyNode[key];

            node->value = value;

            updateFreq(node);

            return;
        }

        if(keyNode.size() == capacity) {

            Node* node = freqList[minFreq]->removeLast();

            keyNode.erase(node->key);

            delete node;
        }

        Node* newNode = new Node(key, value);

        minFreq = 1;

        if(freqList.find(1) == freqList.end()) {
            freqList[1] = new List();
        }

        freqList[1]->addFront(newNode);

        keyNode[key] = newNode;
    }
};
