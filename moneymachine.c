#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"


int money = 0;

struct quest {
    char currentQuest[32];
    int (*listQuests)();
};


void buyItems() {
    if (money < 999999) {
        printf(WHT "You only have %d gold... you do not have enough money\n\n" RESET, money);
    } else {
        printf(RED "Your balance is %d gold pieces. Item acquired UwU\n\n" RESET, money);
        printf(RED "      /| ________________\n" RESET);
        printf(RED "O|===|* >________________>\n" RESET);
        printf(RED "      \\|\n\n" RESET);

    }
}

void listQuests() {
    printf(YEL "Monkey Madness\nCooks assistant\nLords of dranor\nDragon Slayer\nImp Catcher\n\n" RESET);
}

void makeItRain() {
    money += 1000000;
    printf(GRN "making it rain... check your balance now UwU \n\n"    RESET);
}


int main() {
    struct quest *newQuest;
    printf(MAG "█░░░█ █▀▀ █░░ █▀▀ █▀▀█ █▀▄▀█ █▀▀ 　 ▀▀█▀▀ █▀▀█ 　 █▀▀█ █░░░█ █▀▀▄ █▀▀ █▀▀ █▀▀█ █▀▀█ █▀▀ 　\n" RESET);
    printf(MAG "█▄█▄█ █▀▀ █░░ █░░ █░░█ █░▀░█ █▀▀ 　 ░░█░░ █░░█ 　 █░░█ █▄█▄█ █░░█ ▀▀█ █░░ █▄▄█ █░░█ █▀▀ 　\n" RESET);
    printf(MAG "░▀░▀░ ▀▀▀ ▀▀▀ ▀▀▀ ▀▀▀▀ ▀░░░▀ ▀▀▀ 　 ░░▀░░ ▀▀▀▀ 　 █▀▀▀ ░▀░▀░ ▀░░▀ ▀▀▀ ▀▀▀ ▀░░▀ █▀▀▀ ▀▀▀ 　\n" RESET);
    printf(MAG "created by @inversecos\n\n");

    while (1){
        printf(BLU "[1] Buy legendary items\n[2] New quest\n[3] Available quests\n[4] Import items\n[5] Leave quests\n[6] Quit\n\n"   RESET);
        int selection;
        scanf("%d",&selection);

        switch (selection){
            case 1:
                buyItems();
                break;
            case 2:
                newQuest = malloc(128);
                strncpy(newQuest->currentQuest, "Goblin Diplomacy", 32);
                newQuest->listQuests = listQuests;
                printf("Your current quest is %s\n\n", newQuest->currentQuest);
                break;
            case 3:
                newQuest->listQuests();
                break;
            case 4:
                // Get items
                printf("Reading from file items.txt...\n");
                char *userItems = malloc(128);
                FILE *items = fopen("items.txt", "rb");
                fseek(items,0,SEEK_END);
                size_t fs = ftell(items);
                fseek(items,0,SEEK_SET);
                fread(userItems, 1, 64, items);
                printf("File read with the contents: %s\n\n", userItems);
                break;
            case 5:
                if (newQuest){
                    free(newQuest);
                    printf("Quests cleared.\n\n");
                }else{
                    printf("No quests currently.\n\n");
                }
                break;
            case 6:
                exit(0);
                break;
        }
      }
    return 0;
}
