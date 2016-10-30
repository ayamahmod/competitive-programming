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
