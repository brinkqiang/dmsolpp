#include "playermgr.h"

CPlayer* CPlayerMgr::create_player()
{
    auto player = new CPlayer();
    m_mapPlayers[player->GetObjID()] = player;

    return player;
}

CPlayer* CPlayerMgr::find_player(uint64_t id)
{
    auto it = m_mapPlayers.find(id);
    if (it != m_mapPlayers.end())
    {
        return it->second;
    }
    return nullptr;
}

void CPlayerMgr::release_player(uint64_t id)
{
    auto it = m_mapPlayers.find(id);
    if (it != m_mapPlayers.end())
    {
        delete it->second;
        m_mapPlayers.erase(it);
    }
}

CPlayerMgr g_CPlayerMgr;

CPlayer* create_player()
{
    return g_CPlayerMgr.create_player();
}

CPlayer* find_player(uint64_t id)
{
    return g_CPlayerMgr.find_player(id);
}

void release_player(uint64_t id)
{
    g_CPlayerMgr.release_player(id);
}
