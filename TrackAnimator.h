/*********************************************************************
 *
 *  File Name: TrackAnimator.h
 *
 *  Description: Animator for a string of lights
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
#ifndef __GE_CE_WRITER_TRACK_ANIMATOR_H__
#define __GE_CE_WRITER_TRACK_ANIMATOR_H__

#include "Light.h"
#include "LightAnimator.h"
#include "Writer.h"

namespace ESoft {
  
  namespace GECEWriter {

    class TrackAnimator : public LightAnimator {
    public:
      TrackAnimator(uint8_t track, uint8_t lightCount) 
        : track_(track), lightCount_(lightCount), curLight_(0) {}
        
      uint8_t getTrack() { return track_; }
        
      Light getLight() {
        return LightAnimator::getLight().setTrack(track_);
      }

      void reset() { curLight_ = 0; }
      bool isDone() { return false; }

    protected:
      uint8_t track_, lightCount_, curLight_;

    };
    
  }
  
}

#endif //__GE_CE_WRITER_TRACK_ANIMATOR_H__

