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
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FILTERFIR_H
#define FILTERFIR_H

#include "signalprocessorbuffered.h"
#include "dsignal_export.h"
#include <deque>
#include <vector>

namespace dsignal {

class DSIGNALIB_EXPORT FilterFir: public SignalProcessorBuffered
{
public:
    FilterFir(const std::vector<double> &a, int max_buffer_size=1024);
    FilterFir(const FilterFir& filter);

    void push(double value) override;
    void reset() override;
    FilterFir *clone() const override;

protected:
    virtual void process();

private:
    std::deque<double> m_filter_buffer;
    std::vector<double> m_a;
};

}

#endif // FILTERFIR_H
