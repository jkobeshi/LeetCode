class LRUCache {
private:
    struct dbList{
        int value;
        int key;
        dbList* prev;
        dbList* next;
        dbList(int ky, int val){
            key = ky;
            value = val;
            prev = nullptr;
            next = nullptr;
        } 
    };

    int cap;
    dbList* head;
    dbList* tail;
    unordered_map<int, dbList*> mapp;
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int key) {
        auto it = mapp.find(key);
        if(it == mapp.end()) return -1;
        dbList* temp = it->second;

        //Remove Key and insert Key to head
        if(head != temp){
            if(temp->prev != nullptr){
                temp->prev->next = temp->next;
            }
            if(temp->next != nullptr){
                temp->next->prev = temp->prev;
            }
            if(temp == tail){
                tail = tail->prev;
            }
            temp->prev = nullptr;
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        return head->value; 
    }
    
    void put(int key, int value) {
        if(mapp.find(key) == mapp.end()){
            dbList* temp = new dbList(key, value);
            if(mapp.size() == 0)
                tail = temp;
            else{
                head->prev = temp;
                temp->next = head;
            }
            head = temp;
            mapp[key] = temp;
            //Delete LRU
            if(mapp.size() > cap){
                dbList* toDel = tail;
                tail = tail->prev;
                tail->next = nullptr;
                mapp.erase(toDel->key);
                delete toDel;
            }
        }
        else{
            dbList* temp = mapp[key];
            temp->value = value;
            if(head != temp){
                if(temp->prev != nullptr){
                    temp->prev->next = temp->next;
                }
                if(temp->next != nullptr){
                    temp->next->prev = temp->prev;
                }
                if(temp == tail){
                    tail = tail->prev;
                }
                temp->prev = nullptr;
                temp->next = head;
                head->prev = temp;
                head = temp;
            }
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */