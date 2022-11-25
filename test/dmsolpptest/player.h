
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "creature.h"
#include <cstdint>
#include <string>

uint64_t GNextID();

class CPlayer : public virtual CCreature
{
public:
    // export_begin
    CPlayer();
    CPlayer(int level, const std::string& strName);
    CPlayer(const std::string& strName);
    virtual ~CPlayer();

    void DoAction();

    void Init();
    virtual void OnChange();
    void NotChange();
    void SystemChange();
    void LoadFromDB();
    void SaveDB();
    std::string GetName(){ return m_strName; };
    static uint64_t NextID();
    // export_end
private:
    std::string m_strName;
    int m_level;
};

#endif // __PLAYER_H__
