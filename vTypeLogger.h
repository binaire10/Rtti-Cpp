/*!
 * \author Alexandre Wery
 * \file vTypeLogger.h
 * \brief Declaration of any type loader prototype
 * \date 04/09/2017
 */
#ifndef VTYPELOGGER_H
#define VTYPELOGGER_H
#pragma once

/*!
 * \fn v2::load_type(std::unique_ptr<vTypeInfo> &)
 * \brief Function to get an instance of vTypeInfo
 * \return instance of class
 *
 * \fn v2::load_type(std::unique_ptr<vTypeInfo> &&)
 * \brief Function to get an instance of vTypeInfo
 * \return instance of class
 *
 * \fn v2::load_class(std::unique_ptr<vClassInfo> &)
 * \brief Function to get an instance of vClassInfo
 * \return instance of class
 *
 * \fn v2::load_class(std::unique_ptr<vClassInfo> &&)
 * \brief Function to get an instance of vClassInfo
 * \return instance of class
 */

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
