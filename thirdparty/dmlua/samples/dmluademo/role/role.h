#ifndef __ROLE_H_INCLUDE__
#define __ROLE_H_INCLUDE__


#include <map>
#include <iostream>
#include "common/struct.h"

/// ��������ģ��

class CObj { // tolua_export
public:
    void Reset() {
        m_qwObjID = -1;
    }

private:
    uint64_t            m_qwObjID;
    std::string         m_strName;

public:
    // tolua_begin
    CObj() {
        Reset();
    }

    virtual ~CObj() {
        Reset();
    }
    void SetObjID(uint64_t qwObjID) {
        m_qwObjID = qwObjID;
    }
    uint64_t GetObjID() {
        return m_qwObjID;
    }

    void SetName(const char* szName) {
        m_strName = szName;
    }
    const char* GetName() {
        return m_strName.c_str();
    }
};
// tolua_end


class CRole : public CObj { // tolua_export
public:
    void Reset() {
        m_nHP = 0;
        m_nMP = 0;
    }
private:
    int     m_nHP;
    int     m_nMP;

    TaskInfoMap m_TaskInfoMap;
    SPos    m_stPos;

public:
    // tolua_begin
    CRole() {
        Reset();
    }
    virtual ~CRole() {
        Reset();
    }
    void SetMp(int nMp) {
        m_nMP = nMp;
    }
    int GetMp() {
        return m_nMP;
    }

    void SetHp(int nHp) {
        m_nHP = nHp;
    }
    int GetHp() {
        return m_nHP;
    }

    void AddMP(int nMp) {
        m_nMP += nMp;
    }
    void AddHP(int nHp) {
        m_nHP += nHp;
    }


    void SetPos(const SPos& stPos) {
        m_stPos = stPos;
    }
    SPos& GetPos() {
        return m_stPos;
    }

    bool AcceptTask(int nTaskID);
    void FinishTask(int nTaskID);
};
// tolua_end

#endif // __ROLE_H_INCLUDE__
