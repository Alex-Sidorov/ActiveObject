#include <iostream>
#include "abstracttask.h"
#include "proxyactiveobject.h"
#include <windows.h>

class first:public AbstractTask
{
public:
    first(){}
    void run_process() override
    {
        std::cout<<"1111111111"<<std::endl;
        delete this;
    }
    virtual ~first(){}
};

class second:public AbstractTask
{
public:
    second(){}
    void run_process() override
    {
        std::cout<<"2222222222"<<std::endl;
        delete this;
    }
    virtual ~second(){}
};

class third:public AbstractTask
{
public:
    third(ProxyActiveObject *p):_p(p){}
    void run_process() override
    {
        std::cout<<"i:"<<i<<std::endl;
        i++;
        if(i == 10)
        {
            delete this;
        }
        else if(i > 5)
        {
            _p->push(this,2000, Scheduler::TypeTask::EXPRESS);
        }
        else
        {
            _p->push(this,2000);
        }
    }
    virtual ~third(){}
    ProxyActiveObject *_p;
    int i = 0;

};

int main()
{
    ProxyActiveObject *proxy = new ProxyActiveObject(4);
    proxy->start();

    //Sleep(10);
    /*for(int i = 0; i < 20; i++)
    {
        if(i%2)
            proxy.push(new first());
        else proxy.push(new second());
    }*/
    auto i = proxy->push(new third(proxy),3000);
    //bool res = proxy->remove(i);
    //proxy.push(new third(&proxy),10000);
    Sleep(1000000);
    /*proxy.wait();
    Sleep(10000);
    proxy.start();
    Sleep(2000);*/


    /*auto t1 = std::chrono::steady_clock::now();
    Sleep(4484);
    std::cout<<std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-t1).count();*/
    return 0;
}
