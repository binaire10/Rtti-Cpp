#ifndef VTYPELOGGER_H
#define VTYPELOGGER_H
#pragma once

#include <memory>
#include "vTypeInfo.h"
#include "vClassInfo.h"

namespace v2{
    const vTypeInfo *load_type(std::unique_ptr<vTypeInfo> &);
    const vTypeInfo *load_type(std::unique_ptr<vTypeInfo> &&);
    const vClassInfo *load_class(std::unique_ptr<vClassInfo> &);
    const vClassInfo *load_class(std::unique_ptr<vClassInfo> &&);
}

#endif // VTYPELOGGER_H
