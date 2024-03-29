#pragma once

#include "dsignal_export.h"
#include <cstddef>

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
    virtual ~SignalProcessor() = default;

    virtual void push(double value) = 0;

    /**
     * Checks if the SignalProcessor has elements.
     * \returns true if SignalProcessor has data to output by pop().
     */
    virtual bool has() const = 0;

    /**
     * Returns and removes the last element of the SignalProcessor.
     * \returns The last element of SignalProcessor.
     */
    virtual double pop() = 0;

    /**
     * Returns current value of SignalProcessor.
     */
    virtual double value() const = 0;

    /**
     * Returns a reference to the value at position n in the SignalProcessor.
     */
    virtual double& at(size_t n) = 0;

    /**
     * Returns a const reference to the value at position n in the SignalProcessor.
     */
    virtual const double& at(size_t n) const = 0;

    /**
     * The number of data available to pop();
     */
    virtual size_t size() const = 0;

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

