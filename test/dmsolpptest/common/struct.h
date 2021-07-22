#ifndef __STRUCT_H_INCLUDE__
#define __STRUCT_H_INCLUDE__

#include "dmos.h"
#include "enum.h"
#include "macros.h"


struct STaskInfo {

    // tosol_begin
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
    // tosol_end
};

typedef std::map<int, STaskInfo>    TaskInfoMap;
typedef TaskInfoMap::iterator       TaskInfoMapIt;

struct SPos {
    // tosol_begin
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
    // tosol_end
};

#endif // __STRUCT_H_INCLUDE__

