/* Simple help text displayed by "show_help" */

#ifndef _HELP_H_
#define _HELP_H_

char	   *help_text = "\n\
A top users display for PostgreSQL\n\
\n\
These single-character commands are available:\n\
\n\
^L      - redraw screen\n\
<sp>    - update screen\n\
A       - EXPLAIN ANALYZE (UPDATE/DELETE safe)\n\
C       - toggle the use of color\n\
E       - show execution plan (UPDATE/DELETE safe)\n\
I       - show I/O statistics per process (Linux only)\n\
L       - show locks held by a process\n\
M       - sort by memory usage\n\
N       - sort by pid\n\
P       - sort by CPU usage\n\
S       - show pg_stat_statements statistics\n\
Q       - show current query of a process\n\
T       - sort by time\n\
c       - toggle the display of process commands\n\
d       - change number of displays to show\n\
e       - list errors generated by last \"kill\" or \"renice\" command\n\
h or ?  - help; show this text\n\
i       - toggle the displaying of idle processes\n\
k       - kill processes; send a signal to a list of processes\n\
          not avilable when connected to a remote database\n\
n or #  - change number of processes to display\n\
o       - specify sort order (%s)\n\
          i/o stats (%s)\n\
q       - quit\n\
r       - renice a process\n\
          not avilable when connected to a remote database\n\
s       - change number of seconds to delay between updates\n\
u       - display processes for only one user (+ selects all users)\n\
\n\
Not all commands are available on all systems.\n\
";

#endif   /* _HELP_H_ */
