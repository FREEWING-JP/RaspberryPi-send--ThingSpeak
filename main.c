/* 
 * File:   main.c
 * Author: osc
 *Test1
 * Created on 13. oktober 2015, 15:05
 *https://github.com/gabrield/libthingspeak
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "thingspeak.h"
#include "ts_http.h"
#include <time.h>
/*
 * 
 */
int main(int argc, char** argv) {
    printf("Put your value to update: ");
    //API key: YP554VA5F9TKWN7J chanel:3227
    char n;
    ts_context_t  *ctx   = NULL;
    ts_datapoint_t data;
    ts_datapoint_t data2;
    char *result        = NULL;

    //arguments API key, channel	
    ctx = ts_create_context("APKE1QRG2BFAQY00 ", 1); //8JBI3RKMHU9PD1I4, 62438
    result = (char*)malloc(sizeof(char)*MAXLINE);
    bzero(result, MAXLINE);

    int value;
    scanf("%d",&value);
    ts_set_value_i32(&data, value);
    //n=ts_http_post(ctx, HOST_API, "/update", "field1=21&field2=33"); for more than one data point

    printf("%s\n", ts_http_get(HOST_API, "/channels/1/feeds/last",result));

    ts_datastream_update(ctx, 1, "Field1", &data);

    printf("%s\n", ts_http_get(HOST_API, "/channels/1/feeds/last",result));
    printf("\n\nJSON:\n%s\n", ts_feed_get_all(ctx, 0, TS_DATA_JSON, result));
    printf("\n\nCSV:\n%s\n", ts_datastream_get(ctx, 0, TS_DATA_CSV, "Field1", result));


    ts_delete_context(ctx);
    return 0;
}


