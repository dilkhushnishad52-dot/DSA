class Node {
public:
    string data;
    Node* next;
    Node* back;

    Node(string x) {
        data = x;
        next = nullptr;
        back = nullptr;
    }
};

class BrowserHistory {
    Node* currentPage;

public:

    BrowserHistory(string homepage) {
        currentPage = new Node(homepage);
    }

    void visit(string url) {
        Node* newNode = new Node(url);

        // Delete/ignore forward history
        currentPage->next = newNode;
        newNode->back = currentPage;

        currentPage = newNode;
    }

    string back(int steps) {
        while (steps > 0 && currentPage->back != nullptr) {
            currentPage = currentPage->back;
            steps--;
        }

        return currentPage->data;
    }

    string forward(int steps) {
        while (steps > 0 && currentPage->next != nullptr) {
            currentPage = currentPage->next;
            steps--;
        }

        return currentPage->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */