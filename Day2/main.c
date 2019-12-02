// Day 2 is C

#include <stdio.h>
#include <stdint.h>

uint32_t data[] = {1,0,0,3,1,1,2,3,1,3,4,3,1,5,0,3,2,6,1,19,2,19,9,23,1,23,5,27,2,6,27,31,1,31,5,35,1,35,5,39,2,39,6,43,2,43,10,47,1,47,6,51,1,51,6,55,2,55,6,59,1,10,59,63,1,5,63,67,2,10,67,71,1,6,71,75,1,5,75,79,1,10,79,83,2,83,10,87,1,87,9,91,1,91,10,95,2,6,95,99,1,5,99,103,1,103,13,107,1,107,10,111,2,9,111,115,1,115,6,119,2,13,119,123,1,123,6,127,1,5,127,131,2,6,131,135,2,6,135,139,1,139,5,143,1,143,10,147,1,147,2,151,1,151,13,0,99,2,0,14,0};
//uint32_t data[] = {1,0,0,0,99};

int main(void)
{
    data[1] = 12;
    data[2] = 2;

    for (size_t i = 0; i < sizeof(data) / 4; i++)
    {
        uint32_t opcode = data[i];
        uint32_t posX;
        uint32_t posY;

        switch (opcode)
        {
        case 1:
            posX = data[++i];
            posY = data[++i];
            data[data[++i]] = data[posX] + data[posY];
            break;
        
        case 2:
            posX = data[++i];
            posY = data[++i];
            data[data[++i]] = data[posX] * data[posY];
            break;
        
        case 99:
            goto EndLoop;
            break;
        default:
            break;
        }
    }
    EndLoop:
    for (size_t i = 0; i < sizeof(data) / 4; i++)
    {
        printf("%d ", data[i]);
    }
     printf("\n");
    
    printf("End Result = %d\n", data[0]);
    return 0;
}