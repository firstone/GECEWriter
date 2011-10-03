/*********************************************************************
 *
 *  File Name: FadeInAnimator.cpp
 *
 *  Description: Animates brightening from 0 to some value
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
#ifndef __GE_CE_WRITER_FADE_IN_ANIMATOR_H__
#define __GE_CE_WRITER_FADE_IN_ANIMATOR_H__

#include <WProgram.h>

#include <Color.h>
#include <Light.h>
#include <LightAnimator.h>

namespace ESoft {
  
  namespace GECEWriter {
    
    class FadeInAnimator : public GECEWriter::LightAnimator {
    public:
      FadeInAnimator(uint8_t maxBrightness, uint8_t step, const Color &color)
        : step_(step), maxBrightness_(maxBrightness), brightness_(0), 
          color_(color) {}

      bool isDone() { return brightness_ >= maxBrightness_; }

      void reset() { brightness_ = 0; }

    protected:
      Light getLight_() {
        brightness_ += step_;

        if (brightness_ > maxBrightness_)
          brightness_ == maxBrightness_;

        return Light().setBrightness(brightness_).setColor(color_);
      }

    private:
      uint8_t step_, brightness_, maxBrightness_;
      const Color &color_;
    };
    
  }
}

#endif //__GE_CE_LIGHTS_FADE_IN_ANIMATOR_H__


