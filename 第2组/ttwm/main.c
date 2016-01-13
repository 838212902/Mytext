#include "buyer.h"
#include "stdlib.h"
#include <string.h>
#define LENTH 20
extern struct Dingdan dingArr[LENTH];
extern struct Dish dish1[LENTH][LENTH];
extern struct Sellman sellArr[LENTH];
extern struct Buyman buyArr[LENTH];
extern struct Manager man[LENTH];
int main(int argc, const char * argv[])
{
   
    while (1) {
        
        loaddingdan_arr("/Users/zhongruanmini029/Desktop/dingdan", dingArr);
        loaddish_arr("/Users/zhongruanmini029/Desktop/dish", dish1);
        loadsellman_arr("/Users/zhongruanmini029/Desktop/sellman", sellArr);
        loadbuyman_arr("/Users/zhongruanmini029/Desktop/buyman", buyArr);
        loadmanager_arr("/Users/zhongruanmini029/Desktop/man", man);
        mainMenu();
    }
    
    
    return 0;
}
