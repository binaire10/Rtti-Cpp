#ifndef VTYPELOGGER_H
#define VTYPELOGGER_H
#pragma once

#include <memory>
#include "vTypeInfo.h"

namespace v2{
    const vTypeInfo *load_type(std::unique_ptr<vTypeInfo> &);
    const vTypeInfo *load_type(std::unique_ptr<vTypeInfo> &&);
}

#endif // VTYPELOGGER_H
