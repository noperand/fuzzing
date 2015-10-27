#include "config.h"

#include <stdio.h>

/* #include "daemon/daemon.h"
   #include "daemon/worker.h"
*/

void* unbound_start_brk = 0;

extern struct daemon* daemon_init(void);
extern struct worker* worker_create(struct daemon* daemon, int id, int* ports, int n);
extern void daemon_cleanup( struct daemon* daemon );

int main(int argc, char **argv) {
  struct daemon *d;
  struct worker *w;

  /* Mock up a proper worker structure and relatively valid configuration. */
  /* Will initialize a daemon structure for use.
     struct daemon* daemon_init(void) */
  d = daemon_init();
  /* Load an existing configuration for a consistent environment, if desired.
     void daemon_apply_cfg(struct daemon* daemon, struct config_file* cfg) */

  /* Will instantiate a proper worker.
     struct worker* worker_create(struct daemon* daemon, int id, int* ports, int n) */
  /* The id value can be 1, it appears. */
  /* The value of the ports integer pointer can actually be NULL. */
  /* The n value must at least be 1. */
  w = worker_create( d, 1, NULL, 1 );
  
  /* Mock up a proper comm_point or communications endpoint, providing the data 
     for the request. */
  /* struct comm_point x; */
  /* sldns_buffer_init_frm_data( x.buffer, <FILE_DATA>, <FILE_DATA_SIZE> ); */

  /* int worker_handle_request(struct comm_point* c, void* arg, int error, 
     struct comm_reply* repinfo) */
  /* The void pointer 'arg' is cast to a worker structure pointer. */
  /* The error argument must equal 0 (NETEVENT_NOERROR). */

  daemon_cleanup(d);
  return 0;
}
