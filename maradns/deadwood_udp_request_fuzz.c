#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/socket.h>

#include "DwSocket.h"

remote_T *rem;

int main( int argc, char **argv ) {
  struct stat input_stats;
  FILE *input = 0;
  char *input_data = 0;
  int ret = 0;

  if( (ret = stat( argv[1], &input_stats )) != 0) {
    /* printf("error getting stats from file.\n"); */
    return -1;
  }
  input = fopen( argv[1], "r" );
  if ((input_data = (char *) malloc(input_stats.st_size)) == 0) {
    /* printf("memory allocation failed, closing.\n"); */
    return -1;
  }

  printf("everything looks good.\n");

  rem = malloc(sizeof(remote_T));
  rem->local = malloc(sizeof(local_T));

  int s = 0;
  s = socket( AF_INET, SOCK_DGRAM, 0 );

  /* int get_rem_udp_packet_core(unsigned char *a, ssize_t count, int b, SOCKET sock, int l) */
  get_rem_udp_packet_core( input_data, input_stats.st_size, 0, s, 0);

  if (input)
    fclose(input);
  if (input_data)
    free(input_data);
  if (rem) {
    free(rem);
    rem = NULL;
  }

  return 0;
}
