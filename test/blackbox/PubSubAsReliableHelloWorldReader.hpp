/*************************************************************************
 * Copyright (c) 2014 eProsima. All rights reserved.
 *
 * This copy of eProsima Fast RTPS is licensed to you under the terms described in the
 * FASTRTPS_LIBRARY_LICENSE file included in this distribution.
 *
 *************************************************************************/

/**
 * @file PubSubAsReliableHelloWorldReader.hpp
 *
 */

#ifndef _TEST_BLACKBOX_PUBSUBASRELIABLEHELLOWORLDREADER_HPP_
#define _TEST_BLACKBOX_PUBSUBASRELIABLEHELLOWORLDREADER_HPP_

#include "PubSubHelloWorldReader.hpp" 
#include <boost/asio.hpp>
#include <boost/interprocess/detail/os_thread_functions.hpp>

class PubSubAsReliableHelloWorldReader : public PubSubHelloWorldReader
{
    public:
        void configSubscriber(SubscriberAttributes &sattr)
        {
            sattr.qos.m_reliability.kind = eprosima::fastrtps::RELIABLE_RELIABILITY_QOS;

            std::ostringstream t;

            t << "PubSubAsReliableHelloworld_" << boost::asio::ip::host_name() << "_" << boost::interprocess::ipcdetail::get_current_process_id();

            sattr.topic.topicName = t.str();
        };
};

#endif // _TEST_BLACKBOX_PUBSUBASRELIABLEHELLOWORLDREADER_HPP_

