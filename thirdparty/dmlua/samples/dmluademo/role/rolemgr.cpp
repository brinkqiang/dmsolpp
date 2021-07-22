#include "rolemgr.h"
#include "role.h"

CRoleMgr::CRoleMgr(): m_qwObjID( 10000 ) {
}

CRoleMgr::~CRoleMgr() {
}

CRole* CRoleMgr::CreateRole() {
    CRole* poRole = m_oRolePool.FetchObj();

    if ( NULL == poRole ) {
        return NULL;
    }

    poRole->SetObjID( GetNextObjID() );
    m_mapRole[poRole->GetObjID()] = poRole;
    return poRole;
}

void CRoleMgr::ReleaseRole( CRole* poRole ) {
    if ( NULL == poRole ) {
        return;
    }

    m_mapRole.erase( poRole->GetObjID() );
    m_oRolePool.ReleaseObj( poRole );
}

CRole* CRoleMgr::FindRole( uint64_t qwID ) {
    MapRoleIt It = m_mapRole.find( qwID );

    if ( It == m_mapRole.end() ) {
        return NULL;
    }

    return It->second;
}

uint64_t CRoleMgr::GetNextObjID() {
    for ( ;; ) {
        CRole* poRole = FindRole( ++m_qwObjID );

        if ( poRole ) {
            continue;
        }

        break;
    }

    return m_qwObjID;
}

CRole* FindRole( uint64_t qwID )
{
    return CRoleMgr::Instance()->FindRole(qwID);
}

CRole* CreateRole()
{
    return CRoleMgr::Instance()->CreateRole();
}

void   ReleaseRole( CRole* poRole )
{
    CRoleMgr::Instance()->ReleaseRole(poRole);
}
