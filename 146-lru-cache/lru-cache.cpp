class Node{
    public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int k,int val){
        this->val=val;
        this->key=k;
        this->prev=NULL;
        this->next=NULL;
    }
};

class LRUCache {
public:
    Node* head;
    Node* tail;
    unordered_map<int,Node*> mp;
    int n;
    LRUCache(int capacity) {
        this->n=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    void deleteNode(int k){
        Node* temp=mp[k];
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        // delete del;
    }


    Node* addfront(int k,int v){
        Node* temp=new Node(k,v);
        Node* first = head->next;
        temp->next = first;
        temp->prev = head;
        head->next = temp;
        first->prev = temp;
        return temp;
    }
    int get(int key) {
        if(mp.count(key)){
            deleteNode(key);
            Node* temp=addfront(key,mp[key]->val);
            mp[key]=temp;
            return temp->val;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            deleteNode(key);
            Node* temp=addfront(key,value);
            mp[key]=temp;
        }
        else if(mp.size()<n){
            Node* temp=addfront(key,value);
            mp[key]=temp;
        }
        else{
            int k=tail->prev->key;
            deleteNode(k);
            mp.erase(k);
            Node* temp=addfront(key,value);
            mp[key]=temp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */