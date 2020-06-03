// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file cadenaPublisher.h
 * This header file contains the declaration of the publisher functions.
 *
 * This file was generated by the tool fastcdrgen.
 */


#ifndef _CADENA_PUBLISHER_H_
#define _CADENA_PUBLISHER_H_

#include <fastrtps/fastrtps_fwd.h>
#include <fastrtps/publisher/PublisherListener.h>
#include "../topics/DSRGraphPubSubTypes.h"

class DSRPublisher
{
public:
	DSRPublisher();
	virtual ~DSRPublisher();
	bool init(eprosima::fastrtps::Participant *mp_participant_, const char* topicName, const char* topicDataType);
	void run();
	eprosima::fastrtps::rtps::GUID_t getParticipantID() const ;
	bool write(OrMap* object);
	bool write(Mvreg* object);
	bool write(GraphRequest* object);

private:
	eprosima::fastrtps::Participant *mp_participant;
	eprosima::fastrtps::Publisher *mp_publisher;

	class PubListener : public eprosima::fastrtps::PublisherListener
	{
	public:
		PubListener() : n_matched(0){};
		~PubListener(){};
		void onPublicationMatched(eprosima::fastrtps::Publisher* pub,eprosima::fastrtps::rtps::MatchingInfo& info);
		int n_matched;
	} m_listener;
	//DSRGraphTopicPubSubType dsrgraphType;
};

#endif // _CADENA_PUBLISHER_H_