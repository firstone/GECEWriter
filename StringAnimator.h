/*********************************************************************
 *
 *  File Name: StringAnimator.h
 *
 *  Description: Applies animation steps to all bulbs together
 *
 *  Date Created: Sep 22, 2011
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
#ifndef __GE_CE_WRITER_STRING_ANIMATOR_H__
#define __GE_CE_WRITER_STRING_ANIMATOR_H__

#include "Color.h"
#include "LightAnimator.h"
#include "TrackAnimator.h"

namespace ESoft {

  namespace GECEWriter {

    class StringAnimator : public TrackAnimator {
    public:
      StringAnimator(uint8_t track, uint8_t lightCount, LightAnimator *animator)
        : TrackAnimator(track, lightCount), animator_(animator) {
      }
      
      ~StringAnimator() { delete animator_; }
      
      bool isDone() { return animator_->isDone() && curLight_ == 0;  }

      void reset();

    protected:
      Light getLight_();

    private:
      LightAnimator *animator_;
      Light light_;
    };

  }
}

#endif //__GE_CE_WRITER_STRING_ANIMATOR_H__
