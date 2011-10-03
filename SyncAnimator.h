/*********************************************************************
 *
 *  File Name: SyncAnimator.h
 *
 *  Description: Synchroniously moves through light string and animator
 *               at the same time
 *
 *  Date Created: Sep 24, 2011
 * 
 *  Revision History:
 *  
 *  NNN - MMM YY - Name - Change
 *  
 *  Copyright (C) 2011, Erissoft
 *  
 *  This file is part of Erissoft GE CE Lights Controller
 *
 *  GE CE Lights Controller is free software; you can redistribute it and/or
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
#ifndef __GE_CE_WRITER_SYNC_ANIMATOR_H__
#define __GE_CE_WRITER_SYNC_ANIMATOR_H__

#include <Color.h>
#include <LightAnimator.h>
#include <TrackAnimator.h>

namespace ESoft {

  namespace GECEWriter {

    class SyncAnimator : public TrackAnimator {
    public:
      SyncAnimator(uint8_t track, uint8_t lightCount, LightAnimator *animator,
          uint8_t startLight = 0)
        : TrackAnimator(track, lightCount), animator_(animator),
          startLight_(startLight) {
        curLight_ = startLight;
      }
      ~SyncAnimator() { delete animator_; }
      
      bool isDone() { return curLight_ >= lightCount_ || animator_->isDone(); }

      void reset();

    protected:
      Light getLight_();
     
    private:
      LightAnimator *animator_;
      const uint8_t startLight_;
    };

  }
}

#endif //__GE_CE_WRITER_SYNC_ANIMATOR_H__
