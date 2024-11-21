#include <stdlib.h>
#include <iostream>
#include <random>
#include <functional>
using namespace std;

template <typename R>
R randomR(R range_from, R range_to){
    random_device rd{};
    mt19937 engine{rd()};
    uniform_real_distribution<R> dist(range_from,range_to);
    return dist(engine);
}

template <typename I>
I randomI(I range_from, I range_to){
    random_device rd{};
    mt19937 engine{rd()};
    uniform_int_distribution<I> dist(range_from,range_to);
    return dist(engine);
}

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
        item max=0;
        struct vec *ptr=begin;
        max=ptr->val;
        while (ptr!=NULL)
        {
            if (ptr->val>=max)
            {
                max=ptr->val;
            }
            ptr=ptr->next;
        }
        return max;
    }
    item getMin(){
        item min=0;
        struct vec *ptr=begin;
        min=ptr->val;
        while (ptr!=NULL)
        {
            if (ptr->val<=min)
            {
                min=ptr->val;
            }
            ptr=ptr->next;
        }
        return min;
    }
    double* getSlice(int start, int end){
        double* t = new double[1+(end-start)];
        struct vec *ptr=begin;
        for (int i = 0; i < start; i++)
        {
            ptr=ptr->next;
        }
        for (int i = 0; i < 1+(end-start); i++)
        {
            t[i]=ptr->val;
            ptr=ptr->next;
        }
        return t;
        delete t;
    }
    ~myVector(){delete begin;}
};

int main(){
    myVector<double> test;
    for (int i = 1; i < randomI(11,20); i++){
        test.addItem(randomR(0.0, 100.0));
    }
    int size = test.getSize();
    cout<<size<<" Random Doubles Added"<<endl;
    for (int i = 0; i < size; i++){
        cout<<i<<" Index = "<<test.getItem(i)<<endl;
    }
    cout<<"Sum of myVector = "<<test.getSum()<<endl;
    cout<<"Max double = "<<test.getMax()<<endl;
    cout<<"Min double = "<<test.getMin()<<endl;
    int start = randomI(0,size);
    int end = randomI(start,size);
    cout<<"Creating new array from index "<<start<<" to index "<<end<<endl;
    double* sliced_array = test.getSlice(start,end);
    for (int i = 0; i < 1+(end-start); i++)
    {
        cout<<"Sliced array index "<<i<<": "<<sliced_array[i]<<endl;
    }
    delete sliced_array;

    return 0;
}