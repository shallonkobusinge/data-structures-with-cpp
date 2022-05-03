#include <iostream>
using namespace std;

struct Node{
    int key;
    struct Node *left, *right;
};

class Bst{
private:
    Node *root;
public:
    Bst(){
        root = NULL;
    }
    Node *getRoot() const {
        return root;
    }
    void setRoot(Node *root) {
        Bst::root = root;
    }
    Node *createNode(int value) {
        Node *newNode = new Node();
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    Node *insertNode(Node *rootptr, int value) {
        if(rootptr == NULL) {
            return createNode(value);
        }else {
            if(value < rootptr->key){
                rootptr->left = insertNode(rootptr->left,value);
            }else{
                rootptr->right = insertNode(rootptr->right,value);
            }
        }
        return rootptr;
    }
    void display(Node * root){
        if(root != NULL){
            display(root->left);
            cout<<"  "<<root->key<<" - ";
            display(root->right);
        }
    }
    Node *findMinimum(Node *rootptr){
        Node * temp = rootptr;
        while(temp->left != NULL){
            temp = temp->left;
        }
        return temp;
    }
    int findMax(Node *rootptr) {
        Node * current = rootptr;
        while(current->right != NULL){
            current = current->right;
        }
        return current->key;

    }
    Node *deleteNode(Node *node, int searchKey){
        Node * temp;
        //base case
        if(node == NULL){
            cout<<" Looks like tree is empty "<<endl;
            return node;
        }
        //if the key to be deleted is small than the root's key, then it lies in the left sub tree
        if(searchKey < node->key) {
            node->left = deleteNode(node->left,searchKey);
        }
            //if the key to be deleted is larger than the root's key, then it lies in the right sub tree
        else if(searchKey > node->key) {
            node->right = deleteNode(node->right,searchKey);
        }
            //if the key is the same as the root's key, then this is the node to be deleted
        else{
            //node has no child
            if(node->left == NULL && node->right == NULL){
                return NULL;
            }
                //node with only one child or no child
            else if(node->left == NULL){
                Node * temp = node->right;
                delete node;
                return temp;
            }
            else if(node->right == NULL){
                Node * temp = node->left;
                delete node;
                return temp;
            }
            //node with two children: Get the inorder successor (smallest in the right subtree)
            Node * temp = findMinimum(node->right);
            //copy the inorder successor's content to this node
            node->key = temp->key;
            // Delete the inorder successor
            node->right = deleteNode(node->right,temp->key);
        }
        return node;
    }
    Node * searchNode(Node * node, int searchKey){
        if(node == NULL){
            cout <<" Tree is empty  "<<endl;
            return NULL;
        }else{
            if(searchKey < node->key){
                node->left = searchNode(node->left,searchKey);
            }else if(searchKey > node->key){
                node->right = searchNode(node->right,searchKey);
            }
            else if(node->key == searchKey){
                cout<<" Node found which has  "<<node->key<<endl;
                return node;
            }
            else{
                cout<<" Value not found  ";
                return NULL;
            }
        }
    }
    void deleteWholeTree(Node *rootptr) {
        if (rootptr == NULL) {
            return;
        }
        else {
            deleteWholeTree(rootptr->left);
            deleteWholeTree(rootptr->right);
            cout << " Deleting Node :   "<<rootptr->key << endl;
            delete rootptr;

        }
    }
    Node *mirrorImage(Node *root){
        Node * ptr = root;
        if(ptr != NULL){
            mirrorImage(ptr->left);
            mirrorImage(ptr->right);
            Node *temp = ptr->left;
            ptr->left = ptr->right;
            ptr->right = temp;
        }
        return ptr;
    }
    int calculateHeight(Node *node) {
        int lheight;
        int rheight;
        if(node == NULL){
            return 0;
        }else{
            lheight = calculateHeight(node->left);
            rheight = calculateHeight(node->right);
            if(lheight < rheight){
                return rheight+1;
            }else{
                return lheight+1;
            }
        }
    }
    void postOrderTransversal(Node *node){
        Node * temp = node;
        //left---->right----->root
        if(temp == NULL){
            return;
        }else{
            postOrderTransversal(temp->left);
            postOrderTransversal(temp->right);
            cout<<temp->key<<"  -  ";
        }
    }
    void inOrderTransversal(Node *node){
        Node * temp = node;
        //left->root->right
        if(temp != NULL){
            inOrderTransversal(temp->left);
            cout<<temp->key<<" - ";
            inOrderTransversal(temp->right);
        }
    }
    void preOrderTransversal(Node *node){
        Node * temp = node;
        //root->left->right
        if(temp != NULL){
            cout<<temp->key<<" - ";
            preOrderTransversal(temp->left);
            preOrderTransversal(temp->right);
        }
    }
};
int main() {
    Bst tree;
    Node *ptr, *mirror;
    int lgt,height;
    Node *sml;
    char choice;
    int option,element,searchKey,searchKeyToDelete;

    do{
        cout<<"        MENU                   "<<endl;
        cout<<"  1. Insert                    "<<endl;
        cout<<"  2. Delete a node             "<<endl;
        cout<<"  3. Display                   "<<endl;
        cout<<"  4. Search                    "<<endl;
        cout<<"  5. Delete whole Tree         "<<endl;
        cout<<"  6. Find Largest              "<<endl;
        cout<<"  7. Find smallest             "<<endl;
        cout<<"  8. Mirror Image              "<<endl;
        cout<<"  9. Height of the tree        "<<endl;
        cout<<"  10. Post Order Traversal   "<<endl;
        cout<<"  11. In Order Traversal     "<<endl;
        cout<<"  12. Pre Order Traversal    "<<endl;
        cin>>option;
        switch(option){
            case 1:
                cout<<"  Enter the element to insert into the list :  ";
                cin>>element;
                cout<<endl;
                ptr = tree.insertNode(tree.getRoot(), element);
                tree.setRoot(ptr);
                tree.display(tree.getRoot());
                break;
            case 2:
                cout<<"  Which element do you want to delete ? ";
                cin>>searchKeyToDelete;
                cout<<endl;
                tree.deleteNode(tree.getRoot(), searchKeyToDelete);
            case 3:
                tree.display(tree.getRoot());
                break;
            case 4:
                cout<<"   Which way do you want to go with search ?  "<<endl;
                cin>>searchKey;
                tree.searchNode(tree.getRoot(),searchKey);
                break;
            case 5:
                tree.deleteWholeTree(tree.getRoot());
                break;
            case 6:
                lgt = tree.findMax(tree.getRoot());
                cout<<" The largest is "<<lgt;
                break;

            case 7:
                sml = tree.findMinimum(tree.getRoot());
                cout<<" The smallest is "<<sml->key;
                break;
            case 8:
                mirror = tree.mirrorImage(tree.getRoot());
                tree.setRoot(mirror);
                tree.display(tree.getRoot());
                break;
            case 9:
                height = tree.calculateHeight(tree.getRoot());
                cout<<" The height of the tree is "<<height<<endl;
                break;
            case 10:
                tree.postOrderTransversal(tree.getRoot());
                break;
            case 11:
                tree.inOrderTransversal(tree.getRoot());
                break;
            case 12:
                tree.preOrderTransversal(tree.getRoot());
                break;
            default:
                cout<<" Invalid choice ! "<<endl;
                break;
        }
        cout<<endl;
        cout<<" Do you want to continue ? y | n"<<endl;
        cin>>choice;
    }while(choice != 'n');
}
