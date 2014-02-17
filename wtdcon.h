/*
 * wdtcon.h -- Lock/unlock TriCore's ENDINIT bit and modify WDTCON0.
 *
 * Copyright (C) 2000 HighTec EDV-Systeme GmbH.
 *
 */

#ifndef __wdtcon_h
#define __wdtcon_h


#ifdef __cplusplus
extern "C" {
#endif

/* To modify ENDINIT-protected registers, use the following sequence:

	unlock_wdtcon (); // reset ENDINIT bit
	write new value(s) to desired register(s)
	lock_wdtcon (); // set ENDINIT bit

   Another way would be:

	WDT_Passwd (); // prepare WDTCON0 for write access
	WDT_Modify (0, 0x1); // reset ENDINIT bit
	write new value(s) to desired register(s)
	WDT_Passwd ();
	WDT_Modify (1, 0x1); // set ENDINIT bit

   The basic difference between the two approaches is that WDT_Modify()
   allows to manipulate every bit in WDTCON0 at the same time, while
   (un)lock_wdtcon() only (re)sets the ENDINIT bit.
*/

extern void lock_wdtcon (void);
extern void unlock_wdtcon (void);

extern void WDT_Passwd (void);
extern void WDT_Modify (unsigned long modify, unsigned long mask);

#ifdef __cplusplus
}
#endif

#endif /* __wdtcon_h */
