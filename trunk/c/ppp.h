// Copyright (c) 2010 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef PPAPI_C_PPP_H_
#define PPAPI_C_PPP_H_

#include "ppapi/c/pp_module.h"
#include "ppapi/c/ppb.h"

#if __GNUC__ >= 4
#define PP_EXPORT __attribute__ ((visibility("default")))
#elif defined(_MSC_VER)
#define PP_EXPORT __declspec(dllexport)
#endif

// We don't want name mangling for these external functions.
extern "C" {

// Entrypoint for the module.
//
// Returns 0 on success, any other value on failure. Failure indicates to the
// browser that this plugin can not be used. In this case, the plugin will be
// unloaded and ShutdownModule will NOT be called.
PP_EXPORT int PPP_InitializeModule(PP_Module module,
                                   PPB_GetInterface get_browser_interface);

// Called before the plugin module is unloaded.
PP_EXPORT void PPP_ShutdownModule();

// Returns an interface pointer for the interface of the given name, or NULL
// if the interface is not supported. Interface names should be ASCII.
PP_EXPORT const void* PPP_GetInterface(const char* interface_name);

}  // extern "C"

#endif  // PPAPI_C_PPP_H_
