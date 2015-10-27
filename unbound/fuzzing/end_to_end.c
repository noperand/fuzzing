#include "config.h"

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "sldns/sbuffer.h"
#include "util/data/msgparse.h"
#include "util/data/msgreply.h"

int main( int argc, char **argv ) {
  struct stat input_stats;
  FILE *input = 0;
  char *input_data = 0;
  unsigned int count = 0;
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
  if( (count = fread( input_data, 1, input_stats.st_size, input )) > 0 ) {
    printf("successfully read %d bytes from file.\n", count);
  }

  /* do it */
  sldns_buffer mybuffer;
  struct edns_data myedns;
  struct query_info myqueryinfo;

  sldns_buffer_new_frm_data( &mybuffer, input_data, input_stats.st_size );
  if ( 0 == query_info_parse( &myqueryinfo, &mybuffer ) )
    return 0; /* didn't pass checks */
  parse_edns_from_pkt( &mybuffer, &myedns );

  printf("cleaning up.\n");

  /* cleanup */
  if (input)
    fclose(input);
  if (input_data) 
    free(input_data);

  return 0;
}
