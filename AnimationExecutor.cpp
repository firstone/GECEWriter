/*********************************************************************
 *
 *  File Name: AnimationExecutor.cpp
 *
 *  Description: Animation program executor
 *
 *  Date Created: Sep 20, 2011
 * 
 *  Revision History:
 *  
 *  NNN - MMM YY - Name - Change
 *  
 *  Copyright (C) 2011, Erissoft
 *  
 *  This file is part of Erissoft GE CE library
 *
 *  GE CE library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *  
 *********************************************************************/
#include "AnimationExecutor.h"

#include <WProgram.h>

namespace ESoft {
  
  namespace GECEWriter {

    AnimationExecutor::AnimationExecutor(uint8_t trackCount, TrackAnimator *animators[])
      : trackCount_(trackCount), animators_(animators) {
      uint8_t list[Writer::PORT_PIN_COUNT];

      for (uint8_t port = 0; port < Writer::PORT_COUNT; port++) {
        uint8_t portTrackCount = 0;
        
        for (int track = 0; track < trackCount; track++)
          if (Writer::getPort(animators[track]->getTrack()) - 1 == port)
            list[portTrackCount++] = animators[track]->getTrack();

          writers_[port] = portTrackCount == 0 ? NULL : new TrackWriter(portTrackCount, list);
      }
    }

    AnimationExecutor::~AnimationExecutor() {
      for (int i = 0; i < Writer::PORT_COUNT; i++) {
        if (writers_[i] != NULL)
          delete writers_[i];
      }
    }

    void AnimationExecutor::animate() {
      while (!isDone()) {
        for (int track = 0; track < trackCount_; track++) {
          uint8_t port = Writer::getPort(animators_[track]->getTrack()) - 1;
          if (port < Writer::PORT_COUNT && writers_[port] != NULL)
            writers_[port]->addLight(animators_[track]->getLight());
        }

        for (int port = 0; port < Writer::PORT_COUNT; port++)
          if (writers_[port] != NULL)
            writers_[port]->write();

      }
    }

    bool AnimationExecutor::isDone() {
      for (int i = 0; i < trackCount_; i++)
        if (!animators_[i]->isDone())
          return false;

      return true;
    }
    
  }
}
