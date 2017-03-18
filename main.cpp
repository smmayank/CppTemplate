// #define DEBUG

#include <stdio.h>
#include <stdlib.h>
#include "headers/template.h"

int main()
{
  ITERATE_CASE
  {
    lld* workers = (lld*) malloc(2 * sizeof(lld));
    workers[0] = workers[1] = 0;
    lld tasks = 0;
    GET(LLD_FORMAT, &tasks);
    lld counter = 0;
    lld value;
    for(counter=0; counter<tasks; counter++)
    {
      GET(LLD_FORMAT, &value);
      LOG(LLD_FORMAT, value);
      workers[counter%2] += value;
    }
    for(counter=0; counter<tasks; counter++)
    {
      GET(LLD_FORMAT, &value);
      LOG(LLD_FORMAT, value);
      workers[(1+counter)%2] += value;
    }
    LOG_ARRAY(workers, 2, LLD_FORMAT);
    lld max = GET_MIN(workers[0], workers[1]);
    printf(LLD_FORMAT, max);
    printf("\n");
    free(workers);
  }
}
