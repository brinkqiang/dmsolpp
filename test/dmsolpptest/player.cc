
#include "player.h"
#include "person.merge.h"
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
    db::tb_person data;

    data.set_uuid(NextID());
    data.set_job(2);
    data.set_name("jerry");

    auto item = data.add_item_list();
    item->set_tid(1001);
    item->set_count(1);

    m_data_v2 = data;
    m_data_v1 = m_data_v2;
}

void CPlayer::OnChange()
{
    db::tb_person data2;

    data2.set_uuid(m_data_v1.uuid());
    data2.set_job(4);
    data2.set_name("jerry");

    {
        auto item2 = data2.add_item_list();
        item2->set_tid(1001);
        item2->set_count(2);
    }

    {
        auto item2 = data2.add_item_list();
        item2->set_tid(1001);
        item2->set_count(2);
    }

    m_data_v2 = data2;


    db::tb_person_merge merge;
    DiffFrom(m_data_v1, m_data_v2, merge);

    db::tb_person client = m_data_v1;
    MergeFrom(client, merge);

    m_data_v2.PrintDebugString();
    client.PrintDebugString();
    ASSERT_EQ(m_data_v2.DebugString(), client.DebugString());
}

void CPlayer::NotChange()
{
    db::tb_person data2;

    data2.set_uuid(m_data_v1.uuid());
    data2.set_job(4);
    data2.set_name("jerry");

    {
        auto item2 = data2.add_item_list();
        item2->set_tid(1001);
        item2->set_count(2);
    }

    {
        auto item2 = data2.add_item_list();
        item2->set_tid(1001);
        item2->set_count(2);
    }

    m_data_v2 = data2;


    db::tb_person_merge merge;
    DiffFrom(m_data_v1, m_data_v2, merge);

    db::tb_person client = m_data_v1;
    MergeFrom(client, merge);

    m_data_v2.PrintDebugString();
    client.PrintDebugString();
    ASSERT_EQ(m_data_v2.DebugString(), client.DebugString());
}

void CPlayer::SystemChange()
{
    db::tb_person_merge merge;
    DiffFrom(m_data_v1, m_data_v2, merge);

    db::tb_person client = m_data_v1;
    MergeFrom(client, merge);

    m_data_v2.PrintDebugString();
    client.PrintDebugString();
    ASSERT_EQ(m_data_v2.DebugString(), client.DebugString());
}

void CPlayer::LoadFromDB(db::tb_person& data)
{
    m_data_v1 = data;
}

void CPlayer::SaveDB(db::tb_person& data)
{
    data = m_data_v1;
}

uint64_t CPlayer::NextID()
{
    return GNextID();
}
