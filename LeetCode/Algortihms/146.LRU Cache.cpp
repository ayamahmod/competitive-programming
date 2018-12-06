struct Node{
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k, int val, Node* p, Node* n){
        key=k;
        value=val;
        prev=p;
        next=n;
    }
};

class LRUCache{
private:
    int CacheSize;
    int Capacity;

public:
      Node* head;
      Node* tail;
      unordered_map<int,Node*> HashTable;

    LRUCache(int capacity): CacheSize(0), Capacity(capacity), head(NULL), tail(NULL) {}

    void moveTofront(Node* ptr){

        if(ptr->prev==NULL)  return;//It's already the head

        if(ptr->next==NULL) tail=ptr->prev; //It's the tail

        ptr->prev->next=ptr->next;

        if(ptr->next)
            ptr->next->prev=ptr->prev;
        ptr->prev=NULL;
        ptr->next=head;
        head->prev=ptr;
        head=ptr;
    }

    int get(int key) {
        if(HashTable.find(key)!=HashTable.end()){
            moveTofront(HashTable[key]);
            return HashTable[key]->value;
        }
        return -1;
    }

    void set(int key, int value) {
        if(get(key)==-1){
            if(CacheSize>=Capacity){
                if(tail->prev==NULL)  head=NULL; //single node

                Node* newTail=tail->prev;
                if(newTail) newTail->next=NULL;

                HashTable.erase(tail->key);
                delete tail;
                tail=newTail;
                CacheSize--;
            }
            Node* newNode= new Node(key, value, NULL, head);
            if(head)  head->prev=newNode;
            head=newNode;
            HashTable[key]=head;
            CacheSize++;
            if(tail==NULL)  tail=head;
        }
        else    HashTable[key]->value=value;
    }
};


// Second solution

struct Node {
    int key, value;
    Node* prev;
    Node* next;
    Node(int k, int v){
        key = k;
        value = v;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
private:
    unordered_map<int, Node*> p;
    Node* head;
    Node* tail;
    int size;
    int capacity;
    void insertIntoFront(Node* ptr) {
        if(head) head->prev = ptr;
        ptr->next = head;
        ptr->prev = NULL;
        head = ptr;
        if(tail == NULL) tail = ptr;
    }
    void moveToFront(Node* ptr) {
        if(ptr == head || ptr == NULL) return;
        if(tail == ptr) tail = ptr->prev;
        if(ptr->prev) ptr->prev->next = ptr->next;
        if(ptr->next) ptr->next->prev = ptr->prev;
        insertIntoFront(ptr);
    }
    void popBack() {
        Node* tmp = tail;
        tail = tail->prev;
        if(tail) tail->next = NULL;
        if(head == tmp) head = NULL;
        p.erase(tmp->key);
        delete tmp;
        tmp = NULL;
    }
public:
    LRUCache(int capacity) {
        this->size = 0;
        this->capacity = capacity;
        head = NULL;
        tail = NULL;
    }

    int get(int key) {
        if(p.find(key) == p.end()) return -1;
        Node* ptr = p[key];
        moveToFront(ptr);
        return ptr->value;
    }

    void put(int key, int value) {
        if(capacity == 0) return;
        Node* ptr = p[key];
        if(p[key] != NULL) {
            moveToFront(ptr);
            ptr->value = value;
        } else {
            if(size >= capacity) {
                popBack();
                --size;
            }
            ptr = new Node(key, value);
            insertIntoFront(ptr);
            p[key] = ptr;
            ++size;
        }
    }

    void traverseDLL() {
      Node* ptr = head;
      while(ptr!=NULL){
        cout << ptr->value << " -> ";
        ptr = ptr->next;
      }
      cout << endl;
      ptr = tail;
      while(ptr!=NULL){
        cout << ptr->value << " -> ";
        ptr = ptr->prev;
      }
      cout << endl;
    }
};

int main(){
  // ["LFUCache","put","put","get","get","get","put","put","get","get","get","get"]
  // [[3],[2,2],[1,1],[2],[1],[2],[3,3],[4,4],[3],[2],[1],[4]]
  LRUCache obj = LRUCache(3);
  obj.put(2,2);
  obj.put(1,1);
  cout << obj.get(2) << endl;
  cout << obj.get(1) << endl;
  cout << obj.get(2) << endl;
  obj.put(3,3);
  obj.put(4,4);
  cout << obj.get(3) << endl;
  cout << obj.get(2) << endl;
  cout << obj.get(1) << endl;
  cout << obj.get(4) << endl;
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
