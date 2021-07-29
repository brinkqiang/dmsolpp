
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "person.pb.h"
#include "creature.h"

uint64_t GNextID();

class CPlayer : public CCreature
{
public:
// tosol_begin
    CPlayer();
    CPlayer(int level, const std::string& strName);
    CPlayer(const std::string& strName);
    virtual ~CPlayer();

    void DoAction();

    void Init();
    void OnChange();
    void NotChange();
    void SystemChange();
    void LoadFromDB(db::tb_person& data);
    void SaveDB(db::tb_person& data);

    static uint64_t NextID();
// tosol_end
private:
    db::tb_person m_data_v1;
    db::tb_person m_data_v2;
};

#endif // __PLAYER_H__