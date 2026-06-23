struct Node{
    Node* links[26] = {NULL};
    bool flag=false;
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    bool cont(char ch){
        return links[ch-'a']!=NULL;
    }
    void setend(){
        flag=true;
    }

};
class PrefixTree {
private:
Node* root;
public:
    PrefixTree() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->cont(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setend();
    }
    
    bool search(string word) {
         Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->cont(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(int i=0;i<prefix.size();i++){
            if(!node->cont(prefix[i])){
                return false;
            }
            node=node->get(prefix[i]);
        }
        return true;
    }
};
