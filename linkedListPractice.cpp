#include <iostream>

using namespace std;

struct node{
    int data;
    node* nextNode;
};


class LinkedList{
    private:
        node* head = new node;
        node* tail=new node;
    
    public: 
        LinkedList(){
            head->nextNode = tail;
            tail->nextNode = NULL;
        }
        
        // 링크드 리스트 맨 앞에 노드 추가 
        void addFront(int data){
            node* newNode = new node;
            newNode->data = data;
            
            // 노드가 한개도 없는 경우 
            if(head->nextNode == NULL){
                head->nextNode = newNode;
                newNode->nextNode = tail;
            }
            
            // 노드가 한개 이상인 경우 
            else{
                newNode->nextNode = head->nextNode;
                head->nextNode = newNode;
            }
        }
    
        void pushBack(int data){
            
            // 노드가 한개도 없는 경우 
            if(head->nextNode == NULL){
                addFront(data);    
            }
            // 노드가 한개 이상인 경우 
            else{
                node* newNode = new node;
                newNode->data = data;
                
                // 마지막 노드 찾기 
                node* curNode = head->nextNode;
                while(curNode->nextNode!=tail){
                    curNode = curNode->nextNode;
                }
                
                curNode->nextNode = newNode;
                newNode->nextNode = tail;
            }
        }
        
        void insertNode(node* prevNode, int data){
            if(prevNode==nullptr){
                cout << "올바른 노드주소가 아닙니다. 데이터를 삽입할 수 없습니다.\n";
                return;
            }
            
            node* newNode = new node;
            newNode->data = data;
            
            // prevNode가 맨 마지막에 있는 노드인 경우 
            if(prevNode->nextNode == tail){
               prevNode->nextNode = newNode;
               newNode->nextNode = tail;
               return;
            }
            
            // prevNode가 맨 마지막 노드가 아닌 경우 
            newNode->nextNode = prevNode->nextNode;
            prevNode->nextNode = newNode;
        }
        
       
        
        void deleteNode(int data){
            node* targetNode;
            
            if(head->nextNode==tail){
                cout<<"빈 리스트 입니다."<<endl;
                return;
            }
            
            // 첫번째 노드가 지우려는 노드일 때
            if(head->nextNode->data == data){
                targetNode = head->nextNode;
                head->nextNode = targetNode->nextNode;
                targetNode= nullptr;
                delete targetNode;
                return;
            }
            
            // 지우려는 데이터의 이전 노드 찾기 
            node* prevNode = head->nextNode;
            
            while(prevNode->nextNode!=tail){
                if(prevNode->nextNode->data == data){
                    targetNode =prevNode->nextNode; 
                    break;
                }
                
                prevNode= prevNode->nextNode;
            }
            
            if(prevNode->nextNode==tail){
                cout<< "해당 데이터는 존재하지 않습니다.\n";
                targetNode= nullptr;
                return;
            }
            
            if(targetNode->nextNode == tail){
                prevNode->nextNode = tail;
            }else{
                prevNode->nextNode = targetNode->nextNode;
            }
            
            targetNode->nextNode= nullptr;
            targetNode= nullptr;
            delete targetNode;
        }
        
        node* findNode(int data){
            node* curNode = head->nextNode;
            while(curNode->nextNode != NULL){
                if(curNode->data == data ){
                    return curNode;
                }
                curNode = curNode->nextNode;
            }
            return nullptr;
        }
        
        // 리스트의 모든 데이터 출력 
        void showAll(){
            if(head->nextNode==tail){
                cout << "빈 리스트입니다." << endl;
                return;
            }
            
            node* curNode= head->nextNode;
            
            while(true){
                cout << curNode->data;
                
                if(curNode->nextNode == tail){
                    break;
                }
                else{
                    cout <<"-";
                    curNode = curNode->nextNode;
                }
            }
            
            cout<<endl;
        }
    
    
};


int main()
{
    LinkedList linkedList = LinkedList();
    linkedList.showAll();
    // addFront 예제 
    linkedList.addFront(3);
    linkedList.showAll();
    linkedList.addFront(2);
    linkedList.showAll();
    linkedList.addFront(1);
    linkedList.showAll();
    
    // pushBack 예제 
    linkedList.pushBack(4);
    linkedList.showAll();
    linkedList.pushBack(5);
    linkedList.showAll();
    
    // findNode
    node* curNode = linkedList.findNode(5);
    
    // insert 예제 
    if(curNode!=0){
        linkedList.insertNode(curNode,6);
        linkedList.showAll();
    } 
    
    // deleteNode 예제 
    linkedList.deleteNode(1);
    linkedList.showAll();
    linkedList.deleteNode(6);
    linkedList.showAll();
    linkedList.deleteNode(5);
    linkedList.showAll();
    return 0;
}
