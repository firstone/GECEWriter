/*********************************************************************
 *
 *  File Name: RainbowAnimator.h
 *
 *  Description: Rainbow colors animator
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
#ifndef __GE_CE_WRITER_RAINBOW_ANIMATOR_H__
#define __GE_CE_WRITER_RAINBOW_ANIMATOR_H__

#include <WProgram.h>

#include <Color.h>
#include <Light.h>
#include <Rainbow.h>
#include <LightAnimator.h>

namespace ESoft {
  
  namespace GECEWriter {
    
    class RainbowAnimator : public LightAnimator {
    public:
      RainbowAnimator(uint8_t brightness, uint8_t start = 0,
        uint8_t step = 1, bool reverse = false); 

      bool isDone();
      void reset();
      
    protected:
      Light getLight_(); 

    private:
      void change_(int step);

      Rainbow rain_;
      uint8_t brightness_, step_;
      bool reverse_;
      
    };
    
  }

}

#endif //__GE_CE_WRITER_RAINBOW_ANIMATOR_H__
