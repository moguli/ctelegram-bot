#include "source.h"
#include <unistd.h>


int main() {


    setup_bot("token");


    struct updates *update=malloc(sizeof(struct updates));
    
    while(1) {
        sleep(1);
        get_updates(update);
        if(update != 0) {
            if(update->result.message.text && update->result.message.chat.id || update->result.message.from.id) {
                printf("New message: %s\n", update->result.message.text);
                if(strcmp(update->result.message.text, "hi")==0) {
                    send_message(update->result.message.chat.id, "Hello!");
                }
            }
            // Clear the structure once the update is handled
            memset(update, 0x0, sizeof(struct updates));
        }
    }
    return 0;
}
