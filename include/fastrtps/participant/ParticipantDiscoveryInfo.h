/*************************************************************************
 * Copyright (c) 2014 eProsima. All rights reserved.
 *
 * This copy of eProsima Fast RTPS is licensed to you under the terms described in the
 * FASTRTPS_LIBRARY_LICENSE file included in this distribution.
 *
 *************************************************************************/

/**
 * @file ParticipantDiscoveryInfo.h
 *
 */

#ifndef PARTICIPANTDISCOVERYINFO_H_
#define PARTICIPANTDISCOVERYINFO_H_

#include "../rtps/participant/RTPSParticipantDiscoveryInfo.h"

using namespace eprosima::fastrtps::rtps;

namespace eprosima {
namespace fastrtps {

/**
 * Class ParticipantDiscoveryInfo, provided to the user with information regarding a Discovered Participant.
 * @ingroup FASTRTPS_MODULE
 */
class ParticipantDiscoveryInfo {
public:
	ParticipantDiscoveryInfo(){};
	virtual ~ParticipantDiscoveryInfo(){};
	//!RTPSParticipantAttributes of the discovered participant.
	RTPSParticipantDiscoveryInfo rtps;
};

} /* namespace fastrtps */
} /* namespace eprosima */

#endif /* PARTICIPANTDISCOVERYINFO_H_ */
