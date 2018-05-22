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

#ifndef DSIGNAL_MIXEROPERATION_H
#define DSIGNAL_MIXEROPERATION_H

#include "dsignal_export.h"

namespace dsignal {

class DSIGNAL_EXPORT MixerOperation
{
public:
    virtual ~MixerOperation() {}
    virtual double operate(const double a, const double b) = 0;
};

}

#endif // DSIGNAL_MIXEROPERATION_H
