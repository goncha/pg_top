/* interface declaration for display messages */
/* This is a small subset of the interface from display.c that
   just contains the calls for displaying messages.  Do not include
   this and display.h at the same time. */

#ifndef _MESSAGE_H_
#define _MESSAGE_H_

void		new_message(int type, char *msgfmt,...);
void		clear_message();

#endif							/* _MESSAGE_H_ */
