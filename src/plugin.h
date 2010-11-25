/*
   Copyright (c) 2010, The Mineserver Project
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
 * Neither the name of the The Mineserver Project nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
   DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
   (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
   LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
   ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include <string>
#include <vector>
#include <map>

#include "constants.h"
#include "delegate/delegate.hpp"

#ifdef SRUTIL_DELEGATE_PREFERRED_SYNTAX
typedef srutil::delegate<void (int, int)> Delegate;
#else
typedef srutil::delegate2<void, int, int> Delegate;
#endif

class Object
{
public:
   Object(void* obj)
   {
      this->obj = obj;
//      callbacks.insert(std::pair<std::string, Delegate>("onStartedDigging", Delegate::from_function<&obj->onStartedDigging>());
   }
   
   ~Object()
   {
      if (this->obj) {
         delete &this->obj;
      }
   }
private:
   void* obj;
/*   typedef std::map<std::string, Delegate> Callbacks;
   Callbacks callbacks;*/
};

class Plugin
{
private:
   Plugin()
   {
   }
   std::vector<Object*> blocks;
public:
   void initPlugin();
   void setBlockObj(int type, void* obj);
   Object* getBlockObj(int type);
   static Plugin &get();
};
