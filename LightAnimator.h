/*********************************************************************
 *
 *  File Name: LightAnimator.h
 *
 *  Description: Animator for a single light class
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
#ifndef __GE_CE_WRITER_LIGHT_ANIMATOR_H__
#define __GE_CE_WRITER_LIGHT_ANIMATOR_H__

#include <WProgram.h>

#include "Light.h"

namespace ESoft {
  
  namespace GECEWriter {

    class LightAnimator {
    public:
      LightAnimator() : shouldSleep_(false) {}
      virtual ~LightAnimator() {}
        
      virtual Light getLight();

      virtual bool isDone() { return false; }

      virtual void reset() {}

    protected:
      virtual Light getLight_() = 0;

      void sleep_(unsigned int ms);

      bool shouldSleep_;
      unsigned long wakeTime_;

    };
    
  }
}

#endif //__GE_CE_WRITER_LIGHT_ANIMATOR_H__
