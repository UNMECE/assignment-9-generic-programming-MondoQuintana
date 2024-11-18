#include <iostream>
using namespace std;

template <typename item>
class myVector{
private:
    struct vec
    {
        item val;
        struct vec *next;
    };
    struct vec *begin;
public:
    myVector(){begin=NULL;}
    void addItem(item newVal){
        struct vec *ptr = begin;
        if (ptr == NULL){
            begin = new struct vec;
            begin->next=NULL;
            begin->val=newVal;
        }
        else{
            while (ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            struct vec *t=new struct vec;
            t->val=newVal;
            t->next=NULL;
            ptr->next=t;
        }
    }
    item getItem(int searchItem){
        struct vec *ptr=begin;
        while (ptr!=NULL)
        {
            for (int i = 0; i < searchItem; i++)
            {
                ptr=ptr->next;
            }
            return ptr->val;
        }
        return ptr->val;
    }
    ~myVector(){delete begin;}
};

int main(){
    myVector<double> test;
    
    for (int i = 1; i < 11; i++)
    {
        test.addItem(i);
    }
    for (int i = 0; i < 20; i++)
    {
        cout<<test.getItem(i)<<endl;
    }
    
    return 0;
}