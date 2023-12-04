#ifndef BASE_MESSAGE_H
#define BASE_MESSAGE_H

#include <string>

class BaseMesg
{
public:
    BaseMesg () = default;
    virtual ~BaseMesg () = default;

    virtual std::string message () = 0;

    friend std::ostream& operator << ( std::ostream &os, BaseMesg &base )
    {
        return os << base.message();
    }
};

#endif//BASE_MESAGE_H