#ifndef SYSTEM_H
#define SYSTEM_H


class System
{
public:
    System();
    virtual ~System();

    virtual void init() = 0;
    virtual void update() = 0;
    virtual void destroy() = 0;
};

#endif // SYSTEM_H
