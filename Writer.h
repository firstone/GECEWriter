/*********************************************************************
 *
 *  File Name: Writer.h
 *
 *  Description: Physical signal writer
 *
 *  Date Created: Sep 20, 2011
 * 
 *  Revision History:
 *  
 *  NNN - MMM YY - Name - Change
 *  001 - Nov 11 - firstone - Added reverse address assignment and bad pixel exception
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
#ifndef __GE_CE_WRITER_WRITER_H__
#define __GE_CE_WRITER_WRITER_H__

#include <pins_arduino.h>

#include "Light.h"

namespace ESoft {
  
  namespace GECEWriter {

    class Writer {
    public:

#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
      static const uint8_t PORT_COUNT = 12;
#else
      static const uint8_t PORT_COUNT = 4;
#endif

      static const uint8_t PORT_PIN_COUNT = 8;

      Writer(uint8_t lineCount, const uint8_t lines[]) {
      
        out_ = portOutputRegister(getPort(lines[0]));

        for (int i = 0; i < lineCount; i++) {
          pinMode(lines[i], OUTPUT);
          digitalWrite(lines[i], LOW);
        }

        lastSent_ = micros();
      }

      void write(uint8_t lightCount, Light lights[]);

      static void initialize(uint8_t track, uint8_t lightCount, uint8_t brightness, 
        bool visual = false, bool reverse = false, uint8_t badPixel = 255);

      static uint8_t getPort(int track) { return digitalPinToPort(track); }
 
    private:
      void delay5_();
      void delay4_();

      static void writeAll_(Writer &writer, Light lights[], uint8_t lightCount, 
        bool reverse, uint8_t badPixel);

      static const uint8_t FRAME_BITS_ = 26;
      static const uint8_t SEND_DELAY_ = 30; // usec
      static const uint32_t LIGHT_MASK_ = static_cast<uint32_t>(1) << (FRAME_BITS_ - 1);
 
      uint8_t zeroMask_[FRAME_BITS_];
      unsigned long lastSent_;
      volatile uint8_t *out_;
    };
  
    inline void Writer::write(uint8_t lightCount, Light lights[]) {
      uint8_t mask = 0;
    
      for (int i = 0; i < FRAME_BITS_; ++i)
        zeroMask_[i] = 0;

      for (int i = 0; i < lightCount; ++i) {
        mask |= digitalPinToBitMask(lights[i].getTrack());

	uint32_t lightMask = LIGHT_MASK_;
        for (int j = 0; j < FRAME_BITS_; ++j) {
	  if (!(lights[i].getData() & lightMask))
            zeroMask_[j] |= digitalPinToBitMask(lights[i].getTrack());
          lightMask >>= 1;
        }
      }

      cli();

      while(static_cast<long>(micros() - lastSent_) < SEND_DELAY_)
        delayMicroseconds(1);

      *out_ |= mask;
      delay5_();
      delay4_();

      for (int i = 0; i < FRAME_BITS_; ++i) {
        *out_ &= ~mask;
        delay5_();
        delay5_();
        delayMicroseconds(1);

        *out_ |= zeroMask_[i];
        delay5_();
        delay4_();

        *out_ |= mask;
        delay5_();
        delay4_();
      }

      *out_ &= ~mask;

      lastSent_ = micros();

      sei();

    }
  
    inline void Writer::delay4_() {
      delayMicroseconds(1);
      delayMicroseconds(1);
      delayMicroseconds(1);
      delayMicroseconds(1);
    }

    inline void Writer::delay5_() {
      delayMicroseconds(1);
      delayMicroseconds(1);
      delayMicroseconds(1);
      delayMicroseconds(1);
      delayMicroseconds(1);
    }

  }
  
}

#endif //__GE_CE_WRITER_WRITER_H__
