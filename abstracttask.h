#ifndef ABSTRACTTASK_H
#define ABSTRACTTASK_H


class AbstractTask
{
public:
    AbstractTask();
    virtual void run_process() = 0;
    virtual ~AbstractTask();
};

#endif // ABSTRACTTASK_H
