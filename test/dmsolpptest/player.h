
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "person.pb.h"
#include "creature.h"

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
    void LoadFromDB(db::tb_person& data);
    void SaveDB(db::tb_person& data);
    std::string GetName(){ return m_strName; };
    static uint64_t NextID();
    // export_end
private:
    db::tb_person m_data_v1;
    db::tb_person m_data_v2;
    std::string m_strName;
    int m_level;
};

#endif // __PLAYER_H__
