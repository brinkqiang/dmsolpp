/********************************************************************
**       This head file is generated by program,                   **
**            Please do not change it directly.                    **
**                   Auther: brinkqiang                            **
********************************************************************/
// source: person.proto

#ifndef __PERSON_MERGE_H__
#define __PERSON_MERGE_H__

#include "person.pb.h"

bool EqualFrom(::db::fd_task& data, ::db::fd_task& data2);
bool EqualFrom(::db::fd_item& data, ::db::fd_item& data2);
bool EqualFrom(::db::tb_person& data, ::db::tb_person& data2);
bool EqualFrom(::db::fd_item_list& data, ::db::fd_item_list& data2);
bool EqualFrom(::db::fd_item_map& data, ::db::fd_item_map& data2);
bool EqualFrom(::db::tb_person_merge& data, ::db::tb_person_merge& data2);


bool CreatePatch(::db::fd_task& data, ::db::fd_task& data2, ::db::fd_task& merge);
bool CreatePatch(::db::fd_item& data, ::db::fd_item& data2, ::db::fd_item& merge);
bool CreatePatch(::db::tb_person& data, ::db::tb_person& data2, ::db::tb_person& merge);
bool CreatePatch(::db::fd_item_list& data, ::db::fd_item_list& data2, ::db::fd_item_list& merge);
bool CreatePatch(::db::fd_item_map& data, ::db::fd_item_map& data2, ::db::fd_item_map& merge);
bool CreatePatch(::db::tb_person_merge& data, ::db::tb_person_merge& data2, ::db::tb_person_merge& merge);


bool ApplyPatch(::db::fd_task& data, ::db::fd_task& merge);
bool ApplyPatch(::db::fd_item& data, ::db::fd_item& merge);
bool ApplyPatch(::db::tb_person& data, ::db::tb_person& merge);
bool ApplyPatch(::db::fd_item_list& data, ::db::fd_item_list& merge);
bool ApplyPatch(::db::fd_item_map& data, ::db::fd_item_map& merge);
bool ApplyPatch(::db::tb_person_merge& data, ::db::tb_person_merge& merge);


bool DiffFrom(::db::tb_person& data, ::db::tb_person& data2, ::db::tb_person_merge& merge);

bool MergeFrom(::db::tb_person& data, ::db::tb_person_merge& merge);
#endif  // __PERSON_CF_H__
