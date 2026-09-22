#include<stdio.h>
#include<time.h>
#include<unistd.h>

void get_current_time(char*);
void clear_screen(){
    printf("\033[H\033[J");
}
int main()
{
    char buffer[100];
    while(1){
        clear_screen();
        get_current_time(buffer);    
    printf("Current date and time: %s", buffer);
    sleep(1);
    }
    return 0;
}

void get_current_time(char*buffer){
    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, 100, "%H:%M:%S %p & %Y-%m-%d", timeinfo); 
    
}