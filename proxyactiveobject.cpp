#include "proxyactiveobject.h"

ProxyActiveObject::ProxyActiveObject(){}

ProxyActiveObject::ProxyActiveObject(unsigned int _count_thread):
    _scheduler(_count_thread)
{}

ProxyActiveObject::~ProxyActiveObject(){}

bool ProxyActiveObject::start()
{
    return _scheduler.run_all();
}
void ProxyActiveObject::wait()
{
    _scheduler.wait_all();
}

unsigned int ProxyActiveObject::push(AbstractTask *task)
{
    return _scheduler.push_task(task);
}

unsigned int ProxyActiveObject::push(AbstractTask *task, int msec, TypeTask type)
{
    return _scheduler.push_task(task,msec,type);
}

bool ProxyActiveObject::remove(unsigned int index)
{
    return _scheduler.remove_task(index);
}
