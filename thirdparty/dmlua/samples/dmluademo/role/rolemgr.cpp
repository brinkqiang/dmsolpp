#include "rolemgr.h"
#include "role.h"
#include "dmsnowflake.h"

static inline uint64_t GetNextID()
{
    static CDMIDGenerator Gen(0, 0);
    return Gen.GetNextID();
}

CRoleMgr::CRoleMgr() : m_qwObjID(10000) {
}

CRoleMgr::~CRoleMgr() {
}

CRole* CRoleMgr::CreateRole() {
    CRole* poRole = m_oRolePool.FetchObj();

    if (NULL == poRole) {
        return NULL;
    }

    poRole->SetObjID(GetNextID());
    m_mapRole[poRole->GetObjID()] = poRole;
    return poRole;
}

void CRoleMgr::ReleaseRole(CRole* poRole) {
    if (NULL == poRole) {
        return;
    }

    m_mapRole.erase(poRole->GetObjID());
    m_oRolePool.ReleaseObj(poRole);
}

CRole* CRoleMgr::FindRole(uint64_t qwID) {
    MapRoleIt It = m_mapRole.find(qwID);

    if (It == m_mapRole.end()) {
        return NULL;
    }

    return It->second;
}

CRole* FindRole(uint64_t qwID)
{
    return CRoleMgr::Instance()->FindRole(qwID);
}

CRole* CreateRole()
{
    return CRoleMgr::Instance()->CreateRole();
}

void   ReleaseRole(CRole* poRole)
{
    CRoleMgr::Instance()->ReleaseRole(poRole);
}
