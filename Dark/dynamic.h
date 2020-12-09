#ifndef DYNAMIC_H
#define DYNAMIC_H


class Dynamic
{
public:
    Dynamic() = default;
    virtual ~Dynamic() = default;


    virtual int giveX() const = 0;
    virtual int giveY() const = 0;
    virtual void move(int x, int y) = 0;
    virtual bool isRemoved() const = 0;
    virtual void remove() = 0;
};

#endif // DYNAMIC_H
