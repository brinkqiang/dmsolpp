#ifndef __ROLEMGR_H_INCLUDE__
#define __ROLEMGR_H_INCLUDE__

#include <map>

#include "dmsingleton.h"
#include "dmrapidpool.h"
#include "role/role.h"

class CRoleMgr : public TSingleton<CRoleMgr> {
    friend class TSingleton<CRoleMgr>;

public:
    CRoleMgr();
    ~CRoleMgr();

  public:
    CRole*   FindRole( uint64_t qwID );
    CRole*   CreateRole();
    void     ReleaseRole( CRole* poRole );

  private:
    uint64_t GetNextObjID();

    CDynamicRapidPool<CRole, 10000, 100> m_oRolePool;

    typedef std::map<uint64_t, CRole*> MapRole;
    typedef std::map<uint64_t, CRole*>::iterator MapRoleIt;
    MapRole m_mapRole;

    uint64_t m_qwObjID;
};
// tolua_begin
CRole* FindRole(uint64_t qwID );
CRole* CreateRole();
void   ReleaseRole( CRole* poRole );
// tolua_end
#endif // __ROLEMGR_H_INCLUDE__
