
#ifndef __PLAYER_MGR_H__
#define __PLAYER_MGR_H__

#include "player.h"

class CPlayerMgr
{
public:
    // tosol_begin
    CPlayer* create_player();
    CPlayer* find_player(uint64_t id);
    void release_player(uint64_t id);
    // tosol_end
private:
    std::map<int, CPlayer*> m_mapPlayers;
};

// tosol_begin
CPlayer* create_player();
CPlayer* find_player(uint64_t id);
void release_player(uint64_t id);
// tosol_end

#endif // __PLAYER_MGR_H__
