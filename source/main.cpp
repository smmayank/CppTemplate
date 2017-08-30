#define DEBUG

#include <stdio.h>
#include <stdlib.h>
#include "headers/template.h"

int getJumpRequired(int jumpHeight, int fallHeight, int wallHeight)
{
  if(ZERO_OR_LESS(wallHeight) || ZERO_OR_LESS(jumpHeight))
  {
    LOG("Special case 1 wallHeight %d, jumpHeight %d", wallHeight, jumpHeight);
    // fail case
    return 0;
  }
  if(jumpHeight >= wallHeight)
  {
    // special case
    LOG("Special case 2 wallHeight %d, jumpHeight %d", wallHeight, jumpHeight);
    return 1;
  }
  if(fallHeight >= jumpHeight)
  {
    // special case when relative jump is zero or less
    LOG("Special case 3 jumpHeight %d, fallHeight %d", jumpHeight, fallHeight);
    return 0;
  }
  if(ZERO_OR_LESS(fallHeight))
  {
    LOG("Special case 4 fallHeight %d", fallHeight);
    fallHeight = 0;
  }
  int relativeJump = jumpHeight - fallHeight;
  int jumps = wallHeight / relativeJump;
  int heightLeft = wallHeight % relativeJump;
  if(heightLeft > fallHeight)
  {
    jumps++;
  }
  LOG("wallHeight %d, jumpHeight %d, fallHeight %d, heightLeft %d, relativeJump %d,  jumps => %d", wallHeight, jumpHeight, fallHeight, heightLeft,relativeJump, jumps);
  return jumps;
}

int GetJumpCount(int input1,int input2,int input3_size, int* input3)
{
        //Write code here
        lld index = 0;
        lld totalJumps = 0;
        for (index=0; index < input3_size; index++)
        {
                totalJumps += getJumpRequired(input1, input2, input3[index]);
        }
        return totalJumps;
}

int main()
{
        int output = 0;
        int ip1;
        scanf("%d", &ip1);
        int ip2;
        scanf("%d", &ip2);
        int ip3_size = 0;
        int ip3_i;
        scanf("%d\n", &ip3_size);
        int ip3[ip3_size];
        for(ip3_i = 0; ip3_i < ip3_size; ip3_i++) {
                int ip3_item;
                scanf("%d", &ip3_item);

                ip3[ip3_i] = ip3_item;
        }
        output = GetJumpCount(ip1,ip2,ip3_size,ip3);
        printf("%d\n", output);
        return 0;
}
