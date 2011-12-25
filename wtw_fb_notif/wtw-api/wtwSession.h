#pragma once

#define WTW_EVENT_SESSION_PARAMS_CHANGE L"WTW/OnSessionChange" // wP -> SPC_

#define SPC_SESSION_END						0x0001	// system is being closed
#define SPC_SESSION_SUSPEND					0x0002	// system is going into sleep mode
#define SPC_SESSION_RESUME_NON_INTERACTIVE	0x0003	// waking up in non-interactive mode
#define SPC_SESSION_RESUME_INTERACTIVE		0x0004	// resuming in interactive mode
#define SPC_SESSION_LOGON					0x0005	// yeah I know, it's useleess in this program, but whatever
#define SPC_SESSION_LOGOFF					0x0006	// logoff
#define SPC_SESSION_LOCK					0x0007	// User locked down the workstation (Win+L)
#define SPC_SESSION_UNLOCK					0x0008	// and unlocked it
#define SPC_SESSION_REMOTE_CONTROL_CHANGED	0x0009	// connection via RDP to this desktop, or something, 
													// to get current RC status call
													// GetSystemMetrics with SM_REMOTECONTROL

#define SPC_LID_OPENED						0x0101	// laptop lid closed
#define SPC_LID_CLOSED						0x0102	// laptop lid opened
													// this event is sent on Vista+ systems
#define SPC_MONITOR_POWER_OFF				0x0110	// monitor(s) powered off, via DPMS
#define SPC_MONITOR_POWER_ON				0x0111	// and restored back into online status

#define SPC_SESSION_DISPLAY_OFF				0x0112	// display associated with our session is being disabled
#define SPC_SESSION_DISPLAY_ON				0x0113	// and enabled, both currently not used, it causes some weird problems
													// with other events

//////////////////////////////////////////////////////////////////////
//
// WTW_FUNCT_GET_SESSION_INACTIVITY
// wP - wtwInactivityDef*
// lP - 0
//
// do not call to often
//

#define WTW_FUNCT_GET_SESSION_INACTIVITY L"WTW/GetSessionInactivity"

struct wtwInactivityDef 
{
	__wtwStdStructDefs(wtwInactivityDef);

	int				structSize;

	DWORD			keyboardIdle;	// in miliseconds
	DWORD			mouseIdle;		// as above, but for mouse
};