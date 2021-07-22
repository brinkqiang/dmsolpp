
#ifndef __OBJECT_H_INCLUDE__
#define __OBJECT_H_INCLUDE__

#include <stdint.h>

class CObject
{
public:
// tosol_begin
    CObject(): m_objID(0){}
    virtual ~CObject(){}
    uint64_t GetObjID(){ return m_objID;}
    void SetObjID(uint64_t id){ m_objID = id;}
// tosol_end
private:
    uint64_t m_objID;
};

#endif // __OBJECT_H_INCLUDE__