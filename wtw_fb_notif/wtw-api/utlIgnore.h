#pragma once

#include "wtwContact.h"

/*******************************************************************************
**
** Function: 
**		IGNORE_IS_IGNORED - checks if requested contact(s) has any locks
**			applied;
**
** Returns: 
**		S_OK/E_*
**
** Parameters:
**		wP - utlIgnoreEntry*
**		lP - NULL
**
*/

#define IGNORE_IS_IGNORED			L"utlIgnore/IsIgnored"

struct utlIgnoreEntry
{
	__wtwStdStructDefs(utlIgnoreEntry);

	int					structSize;
	wtwContactDef *		pContacts;	// array of contacts to be checked
	DWORD				iContacts;	// size of the array
	DWORD *				rInfo;		// array of return values (recordsof(rInfo) == recordsof(pContacts) == iCOntacts)

	DWORD				flags;
	wchar_t *			userLockName;
};

#define IGNORE_FLAG_CHECK_MESSAGES	0x000001
#define IGNORE_FLAG_CHECK_PRESENCE	0x000002
#define IGNORE_FLAG_CHECK_WHATIFY	0x000004
#define IGNORE_FLAG_CHECK_PEP		0x000008
#define IGNORE_FLAG_CHECK_ARCHIVE	0x000010
#define IGNORE_FLAG_CHECK_FILES		0x000020
#define IGNORE_FLAG_CHECK_ALL_STD	0x0000FF
#define IGNORE_FLAG_CHECK_USER		0x100000 //userLockName must be valid

/*******************************************************************************
**
** Function: 
**		IGNORE_ADD_OPTION - adds option to "ignoring" tab, of the contac properties
**			requires utlIgnore to be present and enabled
**
** Returns: 
**		S_OK/E_*
**
** Parameters:
**		wP - utlIgnoreOptionEntry*
**		lP - NULL
**
*/

#define IGNORE_ADD_OPTION			L"utlIgnore/addOption"

struct utlIgnoreOptionEntry
{
	__wtwStdStructDefs(utlIgnoreOptionEntry);

	int					structSize;
	
	const wchar_t *		lockId;			// only lowercase letters, numbers underscore and dash allowed
	const wchar_t *		lockName;		// name displayed in column headers and tooltips
	const wchar_t *		lockOptionName; // name displayed in contact properties

	const wchar_t *		uiBlockIfSelected;		// NULL
	const void *		reserved;		// NULL

	DWORD				flags;
};

/*******************************************************************************
**
** Event: 
**		IGNORE_EVENT_STATUS_CHANGE - when status of message block was changed
**
** You should return: 
**		S_OK
**
** Parameters:
**		wP - wtwContactDef*
**		lP - 0 - not present, 1 - lock present
**
*/

#define IGNORE_EVENT_STATUS_CHANGE	L"utlIgnore/OnStatusChange"
