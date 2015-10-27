#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "dec/decode.h"

int main( int argc, char** argv ) {
  struct stat input_stats;
  FILE *input = 0;
  char *input_data = 0;
  unsigned int count = 0;
  int ret = 0;

  /* specifics */
  size_t output_length = 1.2 * input_stats.st_size + 10240;
  uint8_t *output = (uint8_t *) malloc(output_length);

  if( (ret = stat( argv[1], &input_stats )) != 0) {
    /* printf("error getting stats from file.\n"); */
    return ret;
  }
  input = fopen( argv[1], "r" );
  if ((input_data = (char *) malloc(input_stats.st_size)) == 0) {
    /* printf("memory allocation failed, closing.\n"); */
    return -1;
  }
  if( (count = fread( input_data, 1, input_stats.st_size, input )) > 0 ) {
    printf("successfully read %d bytes from file.\n", count);
  }

  /* fun stuff */
  BrotliDecompressBuffer(input_stats.st_size, (const uint8_t *) input_data,
			 &output_length, output);

  if (input)
    fclose(input);
  if (input_data)
    free(input_data);
  if (output)
    free(output);

  return 0;
}
