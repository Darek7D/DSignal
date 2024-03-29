#include <dsignal/signalprocessorbuffered.h>
#include <catch.hpp>

using namespace dsignal;


TEST_CASE("signalprocessorbuffered testPushPopHas", "[signalprocessorbuffered]")
{
    SignalProcessorBuffered sig;
    REQUIRE(sig.has()==false);
    sig.push(1);
    sig.push(2);
    sig.push(3);

    REQUIRE(sig.size()==3);
    REQUIRE(sig.has());

    REQUIRE(sig.value()==1);
    REQUIRE(sig.pop()==1);

    REQUIRE(sig.value()==2);
    REQUIRE(sig.pop()==2);

    REQUIRE(sig.value()==3);
    REQUIRE(sig.pop()==3);

    REQUIRE(sig.size()==0);
    REQUIRE(sig.has()==false);
}

TEST_CASE("signalprocessorbuffered testOverflow", "[signalprocessorbuffered]")
{
    bool exception = false;
    SignalProcessorBuffered sig(4);
    try {
        sig.push(1);
        sig.push(2);
        sig.push(3);
        sig.push(4);
    } catch (std::exception &e) {
        exception = true;
    }
    REQUIRE(exception==false);

    exception = false;
    try {
        sig.push(5);
    } catch (std::exception &e) {
        exception = true;
    }
    REQUIRE(exception==true);
}

TEST_CASE("signalprocessorbuffered testUnderflow", "[signalprocessorbuffered]")
{
    bool exception = false;
    SignalProcessorBuffered sig(4);
    try {
        sig.push(1);
        sig.push(2);
        sig.pop();
        sig.pop();
        sig.pop();
    } catch (std::exception &e) {
        exception = true;
    }
    REQUIRE(exception);
}

TEST_CASE("signalprocessorbuffered testClone", "[signalprocessorbuffered]")
{
    SignalProcessorBuffered sig(4);
    sig.push(1);
    sig.push(2);

    SignalProcessorBuffered *sig2 = sig.clone();
    REQUIRE(sig2->maxSize()==4);
    REQUIRE(sig2->size()==2);
    REQUIRE(sig2->pop()==1);
    REQUIRE(sig2->pop()==2);

    delete sig2;
}

TEST_CASE("signalprocessorbuffered testAt", "[signalprocessorbuffered]")
{
    SignalProcessorBuffered sig(4);
    sig.push(1);
    sig.push(2);
    sig.push(3);

    REQUIRE(sig.at(0)==1);
    REQUIRE(sig.at(1)==2);
    REQUIRE(sig.at(2)==3);

    REQUIRE_THROWS_AS(sig.at(3), std::out_of_range);
}
