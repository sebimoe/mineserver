/*
   Copyright (c) 2011, The Mineserver Project
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

#include "../mineserver.h"
#include "../map.h"

#include "snow.h"

bool BlockSnow::affectedBlock(int block)
{
  switch(block)
  {
  case BLOCK_SNOW:
    return true;
  }
  return false;
}



void BlockSnow::onStartedDigging(User* user, int8_t status, int32_t x, int8_t y, int32_t z, int map, int8_t direction)
{

}

void BlockSnow::onDigging(User* user, int8_t status, int32_t x, int8_t y, int32_t z, int map, int8_t direction)
{

}

void BlockSnow::onStoppedDigging(User* user, int8_t status, int32_t x, int8_t y, int32_t z, int map, int8_t direction)
{

}

bool BlockSnow::onBroken(User* user, int8_t status, int32_t x, int8_t y, int32_t z, int map, int8_t direction)
{
  uint8_t block;
  uint8_t meta;

  if (!Mineserver::get()->map(map)->getBlock(x, y, z,&block, &meta))
    return true;

  Mineserver::get()->map(map)->sendBlockChange(x, y, z, BLOCK_AIR, 0);
  Mineserver::get()->map(map)->setBlock(x, y, z, BLOCK_AIR, 0);
  this->spawnBlockItem(x,y,z,map,block,meta);
  return false;
}

void BlockSnow::onNeighbourBroken(User* user, int16_t oldblock, int32_t x, int8_t y, int32_t z, int map, int8_t direction)
{
   uint8_t block;
   uint8_t meta;

   if (!Mineserver::get()->map(map)->getBlock(x, y, z, &block, &meta))
      return;
      
   if (direction == BLOCK_TOP && this->isBlockEmpty(x,y-1,z,map))
   {
      Mineserver::get()->map(map)->sendBlockChange(x, y, z, BLOCK_AIR, 0);
      Mineserver::get()->map(map)->setBlock(x, y, z, BLOCK_AIR, 0);
      this->spawnBlockItem(x, y, z,map, block, 0);
   }   
}

bool BlockSnow::onPlace(User* user, int16_t newblock, int32_t x, int8_t y, int32_t z, int map, int8_t direction)
{
//  uint8_t oldblock;
//  uint8_t oldmeta;
//
//   if (!Mineserver::get()->map(map)->getBlock(x, y-1, z, &oldblock, &oldmeta))
//      return true;
//
//   if(newblock == BLOCK_SNOW){
//     Mineserver::get()->map(map)->sendBlockChange(x, y, z, BLOCK_SNOW, 0);
//     Mineserver::get()->map(map)->setBlock(x, y, z, BLOCK_SNOW, 0);
     return false;
//   }
}

void BlockSnow::onNeighbourPlace(User* user, int16_t newblock, int32_t x, int8_t y, int32_t z, int map, int8_t direction)
{
}

void BlockSnow::onReplace(User* user, int16_t newblock, int32_t x, int8_t y, int32_t z, int map, int8_t direction)
{
}

