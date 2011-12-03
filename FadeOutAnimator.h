/*********************************************************************
 *
 *  File Name: FadeOutAnimator.cpp
 *
 *  Description: Animates fade from some value to 0
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
#ifndef __GE_CE_WRITER_FADE_OUT_ANIMATOR_H__
#define __GE_CE_WRITER_FADE_OUT_ANIMATOR_H__

#include <WProgram.h>

#include <Color.h>
#include <Light.h>
#include <LightAnimator.h>

namespace ESoft {
  
  namespace GECEWriter {
    
    class FadeOutAnimator : public LightAnimator {
    public:
      FadeOutAnimator(uint8_t brightness, uint8_t step, const Color &color)
        : step_(step), brightness_(brightness), maxBrightness_(brightness),
          color_(color) {}

      bool isDone() { return brightness_ <= 0; }

      void reset() { brightness_ = maxBrightness_; }

    protected:
      virtual Light getLight_() {
        brightness_ -= step_;

        if (brightness_ < 0)
          brightness_ = 0;

        return Light().setBrightness(brightness_).setColor(color_);
      }

    private:
      uint8_t step_, brightness_, maxBrightness_;
      const Color &color_;
    };
    
  }
}

#endif //__GE_CE_WRITER_FADE_OUT_ANIMATOR_H__


