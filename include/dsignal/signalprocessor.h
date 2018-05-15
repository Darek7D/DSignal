/*
 * Copyright (C) 2018 Tedtronix.
 * This file is part of DSignal.
 *
 * DSignal is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * DSignal is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with DSignal.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DSIGNAL_SIGNALPROCESSOR_H
#define DSIGNAL_SIGNALPROCESSOR_H

#include "dsignal_export.h"

namespace dsignal {

/**
 * The base element of signal processing in DSignal library.
 *
 * When subclassing SignalProcessor, you must implement pop(), has(), push(),
 * reset() and clone() - see the full description of each of them.
 *
 */
class DSIGNAL_EXPORT SignalProcessor
{
public:
    virtual ~SignalProcessor() {}

    virtual void push(double value) = 0;

    /**
     * Checks if the SignalProcessor has elements.
     * \returns true if SignalProcessor has data to output by pop().
     */
    virtual bool has() = 0;

    /**
     * Returns and removes the last element of the SignalProcessor.
     * \returns The last element of SignalProcessor.
     */
    virtual double pop() = 0;

    /**
     * Resets and clears data in internal buffers.
     */
    virtual void reset() = 0;

    /**
     * Clones the SignalProcessor object. Should return something like this:
     * \code
     * return new SignalProcessorSubclassed(*this);
     * \endcode
     */
    virtual SignalProcessor *clone() const = 0;
};

}

#endif // DSIGNAL_SIGNALPROCESSOR_H
