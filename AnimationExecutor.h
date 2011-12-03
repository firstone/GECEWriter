/*********************************************************************
 *
 *  File Name: AnimationExecutor.h
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
#ifndef __GE_CE_WRITER_ANIMATION_EXECUTOR_H__
#define __GE_CE_WRITER_ANIMATION_EXECUTOR_H__

#include <WProgram.h>

#include "TrackAnimator.h"
#include "Writer.h"

namespace ESoft {
  
  namespace GECEWriter {

    class AnimationExecutor {
    public:
      AnimationExecutor(uint8_t trackCount, TrackAnimator *animators[]);
      ~AnimationExecutor();

      void animate();

      bool isDone();

    private:
      class TrackWriter {
      public:
        TrackWriter(uint8_t trackCount, uint8_t tracks[]) 
          : writer_(trackCount, tracks), curTracks_(0) {}

         void addLight(Light light) {
           if (light != Light::SKIP_LIGHT)
             lights_[curTracks_++] = light;
         }

         void write() {
           writer_.write(curTracks_, lights_);
           curTracks_ = 0;
         }

      private:
        Writer writer_;
        Light lights_[Writer::PORT_PIN_COUNT];
        int curTracks_;
      };

      TrackWriter *writers_[Writer::PORT_COUNT];
      TrackAnimator **animators_;
      uint8_t trackCount_;

    };
    
  }
}

#endif //__GE_CE_WRITER_ANIMATION_EXECUTOR_H__

