#pragma once

#include "dsignal_export.h"
#include "sample.h"
#include "signalvector.h"
#include <unordered_map>
#include <unordered_set>
#include <string>

namespace dsignal {

class SignalFlow;

/**
 * The SignalFlowSession class stores a session for signal flow processing.
 * The designed signal flow process is stored in SignalFlowSession and processed
 * when process() method is used.
 *
 * Example:
 * \code
 * // Create session
 * SignalFlowSession s;
 *
 * // Create signal flow elements
 * SignalFlow sig1(s, 4, SignalProcessorBuffered(), "Signal 1");
 * SignalFlow sig2(s, 4, SignalProcessorBuffered(), "Signal 2");
 *
 * // Declare inputs/outputs
 * s.setInput(sig1);
 * s.setOutput(sig2);
 *
 * // Design signal flow process
 * sig1 >> sig2;
 *
 * // Create sample and push it to session
 * Sample sample(4);
 * s.input()->push(sample);
 *
 * // Process all sample through signal processors.
 * s.process();
 *
 * // Pop output sample
 * Sample out = s.output()->pop();
 * \endcode
 */
class DSIGNAL_EXPORT SignalFlowSession {
public:
    virtual ~SignalFlowSession(){}

    /**
     * Make a connection between two SignalFlow's.
     * All data from input SignalFlow will be transfered to output SignalFlow.
     */
    virtual void connect(SignalFlow* input, SignalFlow* output);

    /**
     * Disconnects the connection between two SignalFlow's.
     * \returns true if the connection is successfully broken, otherwise returns false.
     */
    virtual bool disconnect(SignalFlow* input, SignalFlow* output);

    /**
     * Disconnects all output connections from provided SignalFlow.
     * \returns true if all connections are successfully broken, otherwise returns false.
     */
    virtual bool disconnect(SignalFlow* input);

    /**
     * Clear all connections.
     */
    virtual void clearConnections();

    /**
     * Declares the given SignalFlow as input. When you declare the input,
     * you can access it using the input() method.
     * The SignalFlow declaration doesn't affect the processing, it is only used
     * for easy identification by the library user.
     * \param sf SignalFlow object to declare.
     * \param id unique identification number for this input.
     */
    virtual void setInput(SignalFlow& sf, int id=0);

    /**
     * Declares the given SignalFlow as output. When you declare the output,
     * you can access it using the output() method.
     * The SignalFlow declaration doesn't affect the processing, it is only used
     * for easy identification by the library user.
     * \param sf SignalFlow object to declare.
     * \param id unique identification number for this output.
     */
    virtual void setOutput(SignalFlow& sf, int id=0);

    /**
     * Returns the pointer to SignalFlow object declared by setInput() method
     * \param id unique identification number defined by setInput() method.
     */
    virtual SignalFlow* inputSignalFlow(int id=0) const;

    /**
     * Returns the pointer to SignalFlow object declared by setOutput() method
     * \param id unique identification number defined by setOutput() method.
     */
    virtual SignalFlow* outputSignalFlow(int id=0) const;

    /**
     * Returns the pointer to SignalVector of SignalFlow object declared by setInput() method
     * \param id unique identification number defined by setInput() method.
     */
    virtual SignalVector* input(int id=0) const;

    /**
     * Returns the pointer to SignalVector of SignalFlow object declared by setOutput() method
     * \param id unique identification number defined by setOutput() method.
     */
    virtual SignalVector* output(int id=0) const;

    /**
     * Runs the processing of all buffered data in SignalFlow objects.
     */
    virtual void process();

    /**
     * Resets all signals.
     */
    virtual void reset();

    /**
     * Enables or disables all declared outputs.
     */
    virtual void enableOutputs(bool enable=true);

    /**
     * Enables or disables all declared inputs.
     */
    virtual void enableInputs(bool enable=true);

    /**
     * Dump the graph of all connections in Graphvis format.
     */
    virtual std::string dumpGraph() const;

    /**
     * Returns the SignalFlows connected to the provided source SignalFlow object.
     * \param source_signal_flow source SignalFlow.
     * \return connected SignalFlows to the provided source, or an empty vector
     * if there is no connections or provided source.
     */
    virtual std::vector<SignalFlow*> connectedSignals(SignalFlow* source_signal_flow);

private:
    std::unordered_map<SignalFlow*, std::vector<SignalFlow*>> m_signal_connections;
    std::unordered_map<int, SignalFlow*> m_inputs;
    std::unordered_map<int, SignalFlow*> m_outputs;

    std::string makeDotSymbol(const SignalFlow* signalflow) const;
    std::string stripStrToDotSymbol(std::string s) const;
};

}

