
#include "player.h"
#include "gtest.h"

uint64_t GNextID()
{
    static uint64_t NextID = time(0);
    return NextID++;
}

CPlayer::CPlayer()
    : m_level(1)
{
    SetObjID(GNextID());
}

CPlayer::CPlayer(int level, const std::string& strName)
    : m_level(level), m_strName(strName)
{

}

CPlayer::CPlayer(const std::string& strName)
    : m_level(1), m_strName(strName)
{

}

CPlayer::~CPlayer()
{

}


void CPlayer::DoAction()
{

}

void CPlayer::Init()
{

}

void CPlayer::OnChange()
{

}

void CPlayer::NotChange()
{

}

void CPlayer::SystemChange()
{

}

void CPlayer::LoadFromDB()
{

}

void CPlayer::SaveDB()
{

}

uint64_t CPlayer::NextID()
{
    return GNextID();
}
