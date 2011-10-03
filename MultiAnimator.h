/*********************************************************************
 *
 *  File Name: MultiAnimator.h
 *
 *  Description: Animator container object
 *
 *  Date Created: Sep 21, 2011
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
#ifndef __GE_CE_WRITER_MULTI_ANIMATOR_H__
#define __GE_CE_WRITER_MULTI_ANIMATOR_H__

#include <WProgram.h>

#include "Light.h"
#include "LightAnimator.h"

namespace ESoft {
  
  namespace GECEWriter {

    class MultiAnimator : public LightAnimator {
    public:
      MultiAnimator(unsigned int maxCount);
      ~MultiAnimator();

      bool isDone() { return curAnimator_ >= count_; }

      void reset();

      void addAnimator(LightAnimator *animator);

    protected:
      Light getLight_();
      
    private:
      LightAnimator **animators_;
      unsigned int maxCount_, count_, curAnimator_;
     
    };
    
  }
}

#endif //__GE_CE_WRITER_MULTI_ANIMATOR_H__
