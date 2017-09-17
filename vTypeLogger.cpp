#include "vTypeLogger.h"

#include <memory>
#include <unordered_map>

namespace {
    std::unordered_map<std::string, std::unique_ptr<vTypeInfo>> &getLogger()
    {
        static std::unordered_map<std::string, std::unique_ptr<vTypeInfo>> log;
        return log;
    }
}

namespace v2{
    const vTypeInfo *load_type(std::unique_ptr<vTypeInfo> &&v)
    {
        std::unordered_map<std::string, std::unique_ptr<vTypeInfo>>::const_iterator it = getLogger().find(v->name());
        if(it == getLogger().end())
        {
            const vTypeInfo *ptr = v.get();
            getLogger()[v->name()] = std::move(v);
            return ptr;
        }
        return it->second.get();
    }

    const vTypeInfo *load_type(std::unique_ptr<vTypeInfo> &v)
    {
        std::unordered_map<std::string, std::unique_ptr<vTypeInfo>>::const_iterator it = getLogger().find(v->name());
        if(it == getLogger().end())
        {
            const vTypeInfo *ptr = v.get();
            getLogger()[v->name()] = std::move(v);
            return ptr;
        }
        return it->second.get();
    }

}