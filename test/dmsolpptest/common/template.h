#ifndef __TEMPLATE_H_INCLUDE__
#define __TEMPLATE_H_INCLUDE__

template<class T>
void cast2string(T& t)
{

}

template<class T>
class cast2string
{
public:
    std::string operator (T&& t)
    {
        return std::to_string(t);
    }
};

#endif // __TEMPLATE_H_INCLUDE__
