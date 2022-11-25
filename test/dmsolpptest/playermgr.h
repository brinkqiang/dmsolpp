
#ifndef __PLAYER_MGR_H__
#define __PLAYER_MGR_H__

#include "player.h"
#include <map>

class CPlayerMgr
{
public:
    // export_begin
    CPlayer* create_player();
    CPlayer* find_player(uint64_t id);
    void release_player(uint64_t id);
    // export_end
private:
    std::map<int, CPlayer*> m_mapPlayers;
};

// export_begin
CPlayer* create_player();
CPlayer* find_player(uint64_t id);
void release_player(uint64_t id);
// export_end

#endif // __PLAYER_MGR_H__
