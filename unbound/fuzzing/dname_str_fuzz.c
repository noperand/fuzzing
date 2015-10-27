#include "config.h"

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "util/data/dname.h"

int main( int argc, char **argv ) {
  struct stat input_stats;
  FILE *input = 0;
  char *input_data = 0;
  unsigned int count = 0;
  int ret = 0;

  char output_data[257] = {0};

  if( (ret = stat( argv[1], &input_stats )) != 0) {
    printf("error getting stats from file.\n");
    return -1;
  }
  input = fopen( argv[1], "r" );
  if ((input_data = (char *) malloc(input_stats.st_size)) == 0) {
    printf("memory allocation failed, closing.\n");
    return -1;
  }
  if( (count = fread( input_data, 1, input_stats.st_size, input )) > 0 ) {
    printf("successfully read %d bytes from file.\n", count);
  }

  printf("input_data before:\n%s\n", input_data);
  /* do it */
  dname_str( input_data, &output_data );

  printf("output_data after:\n%s\n", output_data);

  /* if(output_data)
     free(output_data); */

  if (input)
    fclose(input);
  if (input_data) 
    free(input_data);

  return 0;
}
