#pragma once
#include <curl/curl.h>

#include "cJSON.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

CURL *gcurl;
CURLcode res;

struct chat {
    long id;
	unsigned char *type;
	unsigned char *title;
	unsigned char *username;
    unsigned char *firstname;
    int allmembersareadmins;
};

struct parameters {
    unsigned char *keyword;
    void *actualvalue;
    int usable;
};

struct user {
    unsigned char *firstname;
    unsigned char *language_code;
    long id;
    unsigned char *username;
    int is_bot;
};

struct message {
    int id;
    unsigned char *text;
    struct user from;
    struct chat chat;
    int date;
};

struct result {
    struct message message;
};

struct updates {
    int ok;

    struct result result;
};

char *call(char const *w, char const *parameters);
void make_param(struct parameters *params, char const *keyword, char const *value, int index);
char *compile_post_parameters(struct parameters *params);
void setup_bot(unsigned char *token);
void get_updates(struct updates *update);
void send_message(long chat_id, char const *text);
