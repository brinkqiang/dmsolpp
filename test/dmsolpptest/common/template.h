#ifndef __TEMPLATE_H_INCLUDE__
#define __TEMPLATE_H_INCLUDE__

template<class T>
std::string cast2string(T& t)
{
    return std::to_string(t);
}

template<class T>
class TCastString
{
public:
    std::string operator()(T&& t)
    {
        return std::to_string(t);
    }
};

#endif // __TEMPLATE_H_INCLUDE__
