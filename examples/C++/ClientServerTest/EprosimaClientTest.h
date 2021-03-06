/*************************************************************************
 * Copyright (c) 2014 eProsima. All rights reserved.
 *
 * This copy of eProsima Fast RTPS is licensed to you under the terms described in the
 * FASTRTPS_LIBRARY_LICENSE file included in this distribution.
 *
 *************************************************************************/

/**
 * @file EprosimaClientTest.h
 *
 */

#ifndef EPROSIMACLIENTTEST_H_
#define EPROSIMACLIENTTEST_H_

#include "EprosimaClient.h"
#include "fastrtps/utils/eClock.h"
using namespace eprosima::fastrtps;


class EprosimaClientTest {
public:
	EprosimaClientTest();
	virtual ~EprosimaClientTest();
	EprosimaClient m_client;
	double run(int samples);
	eClock m_clock;
	Time_t m_t1,m_t2;
	double m_overhead;
};

#endif /* EPROSIMACLIENTTEST_H_ */
