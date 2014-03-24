/*************************************************************************
 * Copyright (c) 2014 eProsima. All rights reserved.
 *
 * This copy of eProsima RTPS is licensed to you under the terms described in the
 * EPROSIMARTPS_LIBRARY_LICENSE file included in this distribution.
 *
 *************************************************************************/

/**
 * @file NackSupressionDuration.cpp
 *
 *  Created on: Mar 24, 2014
 *      Author: Gonzalo Rodriguez Canosa
 *      email:  gonzalorodriguez@eprosima.com
 *              grcanosa@gmail.com  	
 */

#include "eprosimartps/timedevent/NackSupressionDuration.h"
#include "eprosimartps/writer/StatefulWriter.h"
namespace eprosima {
namespace rtps {

NackSupressionDuration::NackSupressionDuration() {
	// TODO Auto-generated constructor stub

}

NackSupressionDuration::~NackSupressionDuration() {
	// TODO Auto-generated destructor stub
}

NackSupressionDuration::NackSupressionDuration(StatefulWriter* SW_ptr,boost::posix_time::milliseconds interval):
		TimedEvent(&SW_ptr->eventTh.io_service,interval),
		SW(SW_ptr)
{

}

void NackSupressionDuration::event(const boost::system::error_code& ec,ReaderProxy* RP)
{
	if(!ec)
	{
		boost::lock_guard<ReaderProxy> guard(*RP);
		std::vector<ChangeForReader_t*>::iterator cit;
		for(cit=RP->changes.begin();cit!=RP->changes.end();cit++)
		{
			if((*cit)->status == UNDERWAY)
				(*cit)->status = UNACKNOWLEDGED;
		}
	}
	if(ec==boost::asio::error::operation_aborted)
	{
		pInfo("Nack Response delay aborted");
	}
	else
	{
		pError(ec.message()<<endl);
	}
}

} /* namespace dds */
} /* namespace eprosima */
