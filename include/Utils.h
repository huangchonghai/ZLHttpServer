// ***********************************************************************
// Filename         : Utils.h
// Author           : LIZHENG
// Created          : 2014-07-01
// Description      : ���ߺ���
//
// Last Modified By : LIZHENG
// Last Modified On : 2014-06-23
// 
// Copyright (c) lizhenghn@gmail.com. All rights reserved.
// ***********************************************************************
#ifndef ZL_UTILS_H
#define ZL_UTILS_H
#include "Define.h"

NAMESPACE_ZL_START

bool  IsFileExist(const char* filepath);
long  GetFileSize(FILE *file);
long  GetFileSize(const char* filepath);
bool  GetFileData(const char* filepath, std::string& buf);


NAMESPACE_ZL_END

#endif /* ZL_UTILS_H */