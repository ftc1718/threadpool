#ifndef __NOCOPYABLE_H__
#define __NOCOPYABLE_H__

class NonCopyable
{
protected:
    NonCopyable(){}
    ~NonCopyable(){}

private:
    NonCopyable(const NonCopyable &);
    NonCopyable &operator=(const NonCopyable &);
};
#endif
