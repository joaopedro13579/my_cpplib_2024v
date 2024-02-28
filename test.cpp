#include <iostream>
using namespace std;

class lista
{
private:
    int size;
    int data;
    int nextlist[];
public:
    lista(int list[]);
    void apend(int data);
    void n(int data,int index);
    void print();
    int where(int data);
    int who(int index);
    ~lista();
};
    lista::lista(int list[])
{
    int original_size=sizeof(list);
    int nextlist[original_size];
    for (int i = 0; i < original_size; i++)
    {
        nextlist[i]=list[i];
    }
    size =original_size;
}
    lista::~lista()
{
}
    void lista::print(){
    for (int i = 0; i < size; i++)
    {
        cout<<","<<nextlist[i];
    }
    
}
    void lista::apend(int data){
    int inter_list[size+1];
    for (int i = 0; i < size; i++)
    {
        inter_list[i]=nextlist[i];
    }
    inter_list[size]=data;
    delete[] nextlist;
    int nextlist[size+1];
    for (int i = 0; i < size+1; i++)
    {
        nextlist[i]=inter_list[i];
    }
    size=size+1;
}
    void lista::n(int data,int index){
    nextlist[index]=data;
}
    int lista::where(int data){
    for (int i = 0; i < size; i++)
    {
        if (nextlist[i]==data)
        {
            return i;
        }
        
    }
    
}
    int lista::who(int index){
    return nextlist[index];
}

//node class
class node
{
private:
    int data;
    class node* left;
    class node* right;
public:
    node();
    void add_data(int data);
    int return_data();
    void new_left_node(class node* left);
    void new_right_node();
    class node* get_left();
    class node* get_right();
    ~node();
};
class node* node::get_left(){
    return left;
}
class node* node::get_right(){
    return right;
}
int node::return_data(){
    return data;
}
void node::add_data(int data){
    data=data;
}
void node::new_left_node(class node* left){
    left=left;
}
void node::new_left_node(class node* right){
    right=right;
}
node::node()
{
    
}
node::~node()
{
}

//tree class
class tree
{
private:
    int size;
    bool binary;
    bool simetry;
    node no;
    void nl(node localNode);
    void nr(node localNode);
    node* bl(node localNode);
    void br(node localNode);
    void tl(node localNode);
    void tr(node localNode);
public:
    int data_return();
    int return_there(int coordinate[]);
    void add_data(int data);
    void add_right(int data);
    void add_left(int data);
    node traverse_nodes(int coordinate[]);
    void print(string type);
    tree();
    ~tree();
};
void tree::print(string type){
    node* ptr;
    if (type=="nl")
    {
        nl(no);
    }else if (type=="nr")
    {
        nr(no);
    }else if (type=="bl")
    {
        ptr=bl(no);
    }else if (type=="br")
    {
        br(no);
    }else if (type=="tl")
    {
        tl(no);
    }else if (type=="tr")
    {
        tr(no);
    }
} 
void tree::nl(node localNode){
    node* left_ptr=localNode.get_left();
    node* right_ptr=localNode.get_right();
    if (left_ptr!=nullptr)
    {
        localNode=*left_ptr,
        nl(localNode);
    }else if (right_ptr!=nullptr)
    {
        localNode=*right_ptr;
        nl(localNode);    
    }
    cout<<localNode.return_data();
}
void tree::nr(node localNode){
    node* left_ptr=localNode.get_left();
    node* right_ptr=localNode.get_right();
    if (right_ptr!=nullptr)
    {
        localNode=*right_ptr,
        nr(localNode);
    }else if (left_ptr!=nullptr)
    {
        localNode=*left_ptr;
        nr(localNode);    
    }
    cout<<localNode.return_data();
}
node* tree::bl(node localNode){
    node* left_ptr=localNode.get_left();
    node* right_ptr=localNode.get_right();
    
    if (left_ptr==nullptr && right_ptr==nullptr)
    {
        cout<<localNode.return_data();
    }
    return nullptr,nullptr;
}
void tree::br(node localNode){
    node* left_ptr=localNode.get_left();
    node* right_ptr=localNode.get_right();
    if (right_ptr!=nullptr)
    {
        localNode=*right_ptr,
        nr(localNode);
    }else if (left_ptr!=nullptr)
    {
        localNode=*left_ptr;
        nr(localNode);    
    }
    cout<<localNode.return_data();
}
void tree::tl(node localNode){
    node* left_ptr=localNode.get_left();
    node* right_ptr=localNode.get_right();
    if (right_ptr!=nullptr)
    {
        localNode=*right_ptr,
        nr(localNode);
    }else if (left_ptr!=nullptr)
    {
        localNode=*left_ptr;
        nr(localNode);    
    }
    cout<<localNode.return_data();
}
void tree::tr(node localNode){
    node* left_ptr=localNode.get_left();
    node* right_ptr=localNode.get_right();
    if (right_ptr!=nullptr)
    {
        localNode=*right_ptr,
        nr(localNode);
    }else if (left_ptr!=nullptr)
    {
        localNode=*left_ptr;
        nr(localNode);    
    }
    cout<<localNode.return_data();
}
node tree::traverse_nodes(int coordinates[]){
    int size;
    node node_=no;
    node* ptr_next_node;
    size=sizeof(coordinates);
    for (int i = 0; i < size; i++)
    {
        if (coordinates[i]==-1)
        {
            node* ptr_next_node=node_.get_left();
            
        }else if (coordinates[i]==1)
        {
            node* ptr_next_node=node_.get_right();
        }else{
            return node_;
        }
        if (ptr_next_node==nullptr)
        {
            return node_;
        }
        
        node_= *ptr_next_node;
    }
    return node_;
}
void tree::add_left(int data){
    node no_left;
    no_left.add_data(data);
    node* ptr_to_left_node= &no_left;
    no.new_left_node(ptr_to_left_node);
}
int tree::data_return(){
    return no.return_data();
}
int tree::return_there(int coordinate[]){
    node localNode=traverse_nodes(coordinate);
    int local_data=localNode.return_data();
    return local_data;
}
void tree::add_right(int data){
    node no_right;
    no_right.add_data(data);
    node* ptr_to_right_node= &no_right;
    no.new_left_node(ptr_to_right_node);
}
void tree::add_data(int data){
    node nó;
    nó.add_data(data);
    no=nó;
}
tree::tree()
{

}
tree::~tree()
{
}

/*print options:
-node based print left:
given this tree:
        01
       /  \
      /    \
     /      \
    02      03
   /  \    /  \
  /    \  06  07
 04    05
this is te order :04,02,05,01,06,03,07;
code word:nl
-node based print right:
given this tree:
        01
       /  \
      /    \
     /      \
    02      03
   /  \    /  \
  /    \  06  07
 04    05
this is te order :07,03,06,01,05,02,04;
code word:nr
-branchs print left->right:
given this tree:
        01
       /  \
      /    \
     /      \
    02      03
   /  \    /  \
  /    \  06  07
 04    05
this is te order :04,05,06,07,02,03,01;
code word:bl
-branchs print right->left:
given this tree:
        01
       /  \
      /    \
     /      \
    02      03
   /  \    /  \
  /    \  06  07
 04    05
this is te order :07,06,05,04,03,02,01;
code word:br
-tree based print left:
given this tree:
        01
       /  \
      /    \
     /      \
    02      03
   /  \    /  \
  /    \  06  07
 04    05
this is te order :01,02,03,04,05,06,07;
code word:tl
-tree based print right:
given this tree:
        01
       /  \
      /    \
     /      \
    02      03
   /  \    /  \
  /    \  06  07
 04    05
this is te order :01,03,02,07,06,05,04;
code word:tr
*/