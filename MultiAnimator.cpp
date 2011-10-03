/*********************************************************************
 *
 *  File Name: MultiAnimator.cpp
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
#include "MultiAnimator.h"

namespace ESoft {
  
  namespace GECEWriter {

      MultiAnimator::MultiAnimator(unsigned int maxCount) 
        : maxCount_(maxCount), count_(0), curAnimator_(0), 
          animators_(new LightAnimator*[maxCount]) {}
          
      MultiAnimator::~MultiAnimator() {
        for (int i = 0; i < count_; i++)
          delete animators_[i];
          
        delete []animators_;
      }

      void MultiAnimator::reset() {
        for (int i = 0; i < count_; i++)
          animators_[i]->reset();
          
        curAnimator_ = 0;
      }

      Light MultiAnimator::getLight_() {
        Light light = animators_[curAnimator_]->getLight();

        if (animators_[curAnimator_]->isDone()) curAnimator_++;

        return light;        
      }
      

      void MultiAnimator::addAnimator(LightAnimator *animator) {
        if (count_ < maxCount_)
          animators_[count_++] = animator;
      }
    
  }

}


