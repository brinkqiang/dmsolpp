#ifndef __STRUCT_H_INCLUDE__
#define __STRUCT_H_INCLUDE__

#include "dmos.h"
#include "enum.h"
#include "macros.h"
// tolua_begin

struct STaskInfo {
    STaskInfo()
        : nTaskID( 0 ),
          nTaskState( 0 ),
          nTaskCondition( 0 ) {
    }

    ~STaskInfo() {
    }

    int nTaskID;
    int nTaskState;
    int nTaskCondition;
};

typedef std::map<int, STaskInfo>    TaskInfoMap;
typedef TaskInfoMap::iterator       TaskInfoMapIt;

struct SPos {
    SPos()
        : x( 0 ),
          y( 0 ),
          z( 0 ) {
    }

    SPos( int _x, int _y, int _z )
        : x( _x ),
          y( _y ),
          z( _z ) {
    }

    ~SPos() {
    }

    int x;
    int y;
    int z;
};

// tolua_end
#endif // __STRUCT_H_INCLUDE__

