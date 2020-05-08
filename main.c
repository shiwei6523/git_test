//
//  main.c
//  c_test
//
//  Created by WEI SHI on 5/4/20.
//  Copyright © 2020 WEI SHI. All rights reserved.
//

#include <stdio.h>
#include <stdarg.h>

struct dx_rest;


struct dx_response{
    int a;
};

struct dx_rest{
    struct dx_response response[12];
};

struct gp_state{
    struct dx_rest rest;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    char buffer[256];
    //返回值ret = 13,buffer中的内容为123456789
    
    
    
    
    struct dx_response test[4];
    memset(&test,0, 4*sizeof(test));
    
    
    int code = (2<<5) | 5;
    //code = (((132) >>5) & 0x07);
    printf("%d\n",code);

    struct dx_response *rsp =malloc(sizeof(struct dx_response));
    rsp->a = 10;
    struct dx_rest *rst = malloc(sizeof(struct dx_rest));
    
    rst->response[0] = *rsp;
    
    struct gp_state *s = malloc(sizeof(struct gp_state));
    s->rest = *rst;
    

    
    struct dx_rest *temp = &s->rest;
    struct dx_response *res = &(temp->response[0]);
    
    printf("%p\n",&rst);
    printf("%p\n",temp);
    s->rest.response[0].a = 3;
    //temp->response[0] = *rsp;
    //temp->response[0].a = 4;
    printf("%d",temp->response[0].a );
    printf("%d", res->a);
    printf("%d", rsp->a);
    
    
    
    
    
    return 0;
}
