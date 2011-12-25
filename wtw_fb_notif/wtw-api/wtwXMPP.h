#ifndef __wtw__xmpp_pep_h__
#define __wtw__xmpp_pep_h__

#include "wtwPlugin.h"
#include "wtwContact.h"

#define XMPP_PEP_EVENT_TYPE_USERTUNE	0x0001
#define XMPP_PEP_EVENT_TYPE_USERMOOD	0x0002
#define XMPP_PEP_EVENT_TYPE_GEOLOC		0x0003

struct xmppPepEvent 
{
	__wtwStdStructDefs(xmppPepEvent);

	int				structSize;

	wtwContactDef	accountInfo;
	wtwContactDef	fromUser;

	int				eventType;
};

struct xmppPepEventSet 
{
	__wtwStdStructDefs(xmppPepEventSet);

	int				structSize;
	int				setType;

	WTWFUNCTION		callback;	// not implemented, ale jakby kiedys bylo to: wP - 1, serwer zwrocil ok, 0 - serwer zwrocil err
	void			*od;
};

struct xmppPepUserMood 
{
	__wtwStdStructDefs(xmppPepUserMood);

	int				structSize;

	const wchar_t * mood;
	const wchar_t * text;

	const wchar_t * id;
};

struct xmppPepUserTune 
{
	__wtwStdStructDefs(xmppPepUserTune);

	int				structSize;

	const wchar_t * track;
	const wchar_t * artist;
	const wchar_t * title;
	const wchar_t * source;
	const wchar_t * uri;
	const wchar_t * length;

	const wchar_t * id;
};

struct xmppPepGeoLocation 
{
	__wtwStdStructDefs(xmppPepGeoLocation);

	int				structSize;

	const wchar_t * accuracy;		//  decimal 	Horizontal GPS error in meters; this element obsoletes the <error/> element  	10
	const wchar_t * alt;			// 	decimal 	Altitude in meters above or below sea level 	1609
	const wchar_t * area;			// 	string 		A named area such as a campus or neighborhood 	Central Park
	const wchar_t * bearing;		// 	decimal 	GPS bearing (direction in which the entity is heading to reach its next waypoint), measured in decimal degrees relative to true north [1] 	 
	const wchar_t * building;		// 	string 		A specific building on a street or in an area 	The Empire State Building
	const wchar_t * country;		// 	string 		The nation where the user is located 	United States
	const wchar_t * countrycode;	// 	string 		The ISO 3166 two-letter country code 	US
	const wchar_t * datum;			// 	string 		GPS datum [2] 	 
	const wchar_t * description;	// 	string 		A natural-language name for or description of the location 	Bill's house
	const wchar_t * error;			// 	decimal 	Horizontal GPS error in arc minutes; this element is deprecated in favor of <accuracy/> 	290.8882087
	const wchar_t * floor;			// 	string 		A particular floor in a building 	102
	const wchar_t * lat;			// 	decimal 	Latitude in decimal degrees North 	39.75
	const wchar_t * locality;		// 	string 		A locality within the administrative region, such as a town or city 	New York City
	const wchar_t * lon;			// 	decimal 	Longitude in decimal degrees East 	-104.99
	const wchar_t * postalcode;		// 	string 		A code used for postal delivery 	10027
	const wchar_t * region;			// 	string 		An administrative region of the nation, such as a state or province 	New York
	const wchar_t * room;			// 	string 		A particular room in a building 	Observatory
	const wchar_t * speed;			// 				The speed at which the entity is moving, in meters per second 	52.69 	xs:decimal
	const wchar_t * street;			// 	string 		A thoroughfare within the locality, or a crossing of two thoroughfares 	34th and Broadway
	const wchar_t * text;			// 	string 		A catch-all element that captures any other information about the location 	Northwest corner of the lobby
	const wchar_t * timestamp;		// 	dateTime 	UTC timestamp specifying the moment when the reading was taken (MUST conform to the DateTime profile of XMPP Date and Time Profiles [3]) 	2004-02-19T21:12Z
	const wchar_t * uri;			//	string		URL

	const wchar_t * id;
};

#define XMPP_PEP_EVENT_ARRIVED L"XMPP/OnPEPEvent" // event globalny;

#define XMPP_PFE_PEP_PUBLISH_EVENT L"PFEPublishData" // funkcja, zywana tak jak inne funkcje protoko³ów czyli w po³aczeniu z NetID i NetSID, 0 - bl¹d, 1 - ok

#endif