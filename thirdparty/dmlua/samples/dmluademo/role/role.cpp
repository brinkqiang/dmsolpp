#include "role.h"
#include "rolemgr.h"

bool CRole::AcceptTask( int nTaskID ) {
    TaskInfoMapIt It = m_TaskInfoMap.find( nTaskID );

    if ( It != m_TaskInfoMap.end() ) {
        return false;
    }

    STaskInfo oInfo;
    oInfo.nTaskID = nTaskID;
    oInfo.nTaskState = eTaskStateStart;
    oInfo.nTaskCondition = 0;
    m_TaskInfoMap[oInfo.nTaskID] = oInfo;
    return true;
}

void CRole::FinishTask( int nTaskID ) {
    TaskInfoMapIt It = m_TaskInfoMap.find( nTaskID );

    if ( It == m_TaskInfoMap.end() ) {
        return;
    }

    It->second.nTaskState = eTaskStateEnd;
}
