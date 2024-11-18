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
    int getSize(){
        struct vec *ptr=begin;
        int i = 0;
        while (ptr!=NULL){
            i++;
            ptr=ptr->next;
        }
        return i;
    }
    bool sizeTest(int a){
        bool test;
        if (a>getSize())
        {
            test=true;
        }
        else{
            test=false;
        }
        return test;
    }
    item getItem(int searchItem){
        if(sizeTest(searchItem)==1){
            struct vec *ptr=begin;
            return ptr->val;
        }
        else{
            struct vec *ptr=begin;
            for (int i = 0; i < searchItem; i++){
                ptr=ptr->next;
            }
            return ptr->val;
        }
    }
    item getSum(){
        item sum=0;
        struct vec *ptr=begin;
        while (ptr!=NULL)
        {
            sum+=ptr->val;
            ptr=ptr->next;
        }
        
        return sum;
    }
    item getMax(){
        item max;
        struct vec *ptr=begin;
        max=ptr->val;
        while (ptr!=NULL)
        {
            ptr=ptr->next;
            if (ptr->val>=max)
            {
                max=ptr->val;
            }
            else{
                max=max;
            }
        }
        return max;
    }
    ~myVector(){delete begin;}
};

int main(){
    myVector<double> test;
    for (int i = 1; i < 11; i++){
        test.addItem(i);
    }
    for (int i = 0; i < 10; i++){
        cout<<test.getItem(i)<<endl;
    }
    cout<<"Size of myVector = "<<test.getSize()<<endl;
    cout<<test.getSum()<<endl;
    cout<<test.getMax()<<endl;
    return 0;
}