
#ifndef __CREATURE_H_INCLUDE__
#define __CREATURE_H_INCLUDE__

#include "object.h"

class CCreature : public CObject
{
public:
// tosol_begin
    CCreature(): m_llHP(0), m_llMP(0){}
    virtual ~CCreature(){}

    void SetHP(int64_t HP){ m_llHP = HP;}
    void SetMP(int64_t MP){ m_llMP = MP;}

    int64_t GetHP(){ return m_llHP;}
    int64_t GetMP(){ return m_llMP;}

// tosol_end
private:
    int64_t m_llHP;
    int64_t m_llMP;
};

#endif // __CREATURE_H_INCLUDE__