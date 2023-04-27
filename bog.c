#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int turn = 1;                       // 전역시대
int mp = 0;                         // 전역mp
double kg = 0;                      // 전역kg
double point = 0.0;                 // 모험 포인트
int evolution = 0;                  // 진화레벨
int feedclicknum = 0;               // 전역 총 먹이준횟수
int advenclicknum = 0;              // 전역 총 모험간횟수
void adventurement(int _adventure); // 모험하다 죽을때 출력함수
void feedment(int _feed);           // 밥먹다 죽을때 출력함수
int deadmp(int _evolution);         // 죽었을때 마나얻게하는 함수.
void squarebox(int n);              // 네모틀
void squarefirst(int n);            // 화면

int main(void)

{
    int start = 0;
    int game = 0;

    int feed = 0;      // 플랑크톤 0 먹이종류
    double feedkg = 0; // 먹이 무게
    int feednum = 7;   // 먹이개수
    int up;
    int adventurenum = 0;     // 모험종류
    double adventurekg = 2.6; // 모험추가무게
    int adventuremp = 30;     // 모험추가mp

    int die_feed, die_adventure;
    int evol1 = 1, evol2 = 1, evol3 = 1, evol4 = 1, evol5 = 1, evol6 = 1;       // 진화 턴마다 1번씩만 나오게
    int evol11 = 1, evol22 = 1, evol33 = 1, evol44 = 1, evol55 = 1, evol66 = 1; // ㅠㅠ..복잡해
    int point3 = 0;
    int dienum = 0;
    srand(time(NULL));
    printf("입력해주세요 : 1.시작 2.종료 \n");
    scanf("%d", &start);
    if (start == 1) // 게임시작
    {

        while (1)
        {
            dienum = 0; // 먹이 죽음변수 초기화.

            if (kg >= 2 && evol1 == 1 && evolution == 0)
            {
                printf("\n아기로 진화!!\n");
                if (evol11 == 1)
                    mp += 40;
                else
                {
                    mp += 20;
                    printf("첫번째진화가아니라서 적은mp증가\n");
                }
                evolution = 1;
                evol11 = 2;
                evol1 = 2;
            }
            if (kg >= 20 && evol2 == 1 && evolution == 1)
            {
                printf("\n어린이 진화\n");
                if (evol22 == 1)
                    mp += 70;
                else
                {
                    mp += 60;
                    printf("첫번째진화가아니라서 적은mp증가\n");
                }
                evol2 = 2;
                evol22 = 2;
                evolution = 2;
            }
            if (kg >= 90 & evol3 == 1 && evolution == 2)
            {
                printf("\n젊은이\n");
                if (evol33 == 1)
                    mp += 230;
                else
                {
                    mp += 90;
                    printf("첫번째진화가아니라서 적은mp증가\n");
                }
                evol33 = 2;
                evolution = 3;
                evol3 = 2;
            }
            if (kg >= 320 && evol4 == 1 && evolution == 3)
            {
                printf("\n사회의일원\n");
                if (evol44 == 1)
                    mp += 600;
                else
                {
                    mp += 140;
                    printf("첫번째진화가아니라서 적은mp증가\n");
                }
                evol44 = 2;
                evol4 = 2;
                evolution = 4;
            }
            if (kg >= 1000 && evol5 == 1 && evolution == 4)
            {
                printf("\n개복치왕이다\n");
                if (evol55 == 1)
                {
                    mp += 1950;
                }
                else
                {
                    mp += 360;
                    printf("첫번째진화가아니라서 적은mp증가\n");
                }
                evol5 = 2;
                evol55 = 2;
                evolution = 5;
            }
            if (kg >= 2500 && evol6 == 1 & evolution == 5) // 진화 ...
            {
                printf("나는 수족관 주인이다 \n");
                printf(" %d대수족관 주인 \n", turn);
                if (evol66 == 1) // 첫진화인지 아닌지 확인하기위해서.
                {
                    mp += 3340;
                }
                else
                {
                    mp += 680;
                }
                evol6 = 2; // 반복문에서 한번만나오게끔.
                evol66 = 2;
                evolution = 6; // 진화레벨
            }

            sleep(1);

            squarebox(1); // 1.기본 선택지화면
            scanf("%d", &game);
            if (game == 1) // 1.먹이
            {
                squarebox(2);

                if (feed == 0) // 먹이 종류에 따른 무게 선택하기.
                {
                    printf("개복치는 플랑크톤 %d개를 맛있게 먹는다....\n", feednum);
                    feedkg = 0.1;
                }
                if (feed == 1)
                {
                    printf("개복치는 해파리 %d개를 맛있게 먹는다....\n", feednum);
                    feedkg = 0.2;
                }
                if (feed == 2)
                {
                    printf("개복치는 오징어 %d개를 맛있게 먹는다....\n", feednum);
                    feedkg = 0.4;
                }
                if (feed == 3)
                {
                    printf("개복치는 새우 %d개를 맛있게 먹는다....\n", feednum);
                    feedkg = 0.7;
                }
                if (feed == 4)
                {
                    printf("개복치는 정어리 %d개를 맛있게 먹는다....\n", feednum);
                    feedkg = 1.0;
                }
                if (feed == 5)
                {
                    printf("개복치는 게 %d개를 맛있게 먹는다....\n", feednum);
                    feedkg = 1.4;
                }
                if (feed == 6)
                {
                    printf("개복치는 가리비 %d개를 맛있게 먹는다....\n", feednum);
                    feedkg = 2.5;
                }
                if (feed == 7)
                {
                    printf("개복치는 굴 %d개를 맛있게 먹는다....\n", feednum);
                    feedkg = 4.0;
                }
                if (feed == 8)
                {
                    printf("개복치는 닭새우 %d개를 맛있게 먹는다....\n", feednum);
                    feedkg = 5.5;
                }

                for (int i = 0; i < feednum; i++)
                {

                    if (feed >= 1) // 플랑크톤제외하고 죽이기.
                    {
                        if (turn == 1) // 첫턴
                        {
                            die_feed = rand() % 100;
                            if (die_feed < 8)
                                ; // 먹이먹다가 죽엇을때
                            {
                                feedment(feed);
                                mp += deadmp(evolution);
                                turn++;
                                kg = 0;
                                evol1 = 1;
                                evol2 = 1;
                                evol3 = 1;
                                evol4 = 1;
                                evol5 = 1;
                                evol6 = 1;
                                evolution = 0;
                                printf("개복치는 다시 별사탕이 된다!응애!\n");

                                dienum = 1; // while문 처음으로돌아가기위해 변수지정.

                                break; // for문 빠져나가기.
                            }
                        }
                        else if (turn > 1) // 첫턴이아닌경우 먹이사망
                        {
                            die_feed = rand() % 1000;

                            if (die_feed == 3) // 0.1프로확률로 사망
                            {
                                feedment(feed);
                                mp += deadmp(evolution);
                                turn++;
                                kg = 0;

                                evol1 = 1;
                                evol2 = 1;
                                evol3 = 1;
                                evol4 = 1;
                                evol5 = 1;
                                evol6 = 1;
                                printf("개복치는 다시 별사탕이 된다! 응애\n");
                                evolution = 0;
                                dienum == 1;
                                break;
                            }
                        }
                    }
                    kg += feedkg;
                }
                if (dienum == 1)
                {
                    continue; // while문 처음으로 돌아가기위한
                }
                feedclicknum++; // 먹이성공횟수..

                // 먹이를 먹으면 모험포인트 1/3 충전.
                point3++;
                point = (double)point3 / 3; // if쓰면 오차는 사라짐..
                continue;                   // 먹이 다 먹고 선택지로.
            }

            if (game == 2) // 2. 모험하기
            {
                if (point >= 1) // 가지고있는 모험포인트 검사.
                {
                    point--; // 모험할때마다 모험포인트 1 감소.
                    // 먹이와 비슷하게 모험설정.if문.
                    point3 -= 3;
                    squarebox(3);

                    if (turn == 1)
                    {
                        die_adventure = rand() % 2;
                        if (die_adventure == 0)
                        {
                            adventurement(adventurenum);
                            mp += deadmp(evolution);
                            turn++;
                            kg = 0;
                            evol1 = 1;
                            evol2 = 1;
                            evol3 = 1;
                            evol4 = 1;
                            evol5 = 1;
                            evol6 = 1;
                            evolution = 0;
                            continue;
                        }
                    }
                    else if (turn == 2)
                    {
                        die_adventure = rand() % 100;
                        if (die_adventure <= 25)
                        {
                            adventurement(adventurenum);
                            mp += deadmp(evolution);
                            turn++;
                            kg = 0;
                            evol1 = 1;
                            evol2 = 1;
                            evol3 = 1;
                            evol4 = 1;
                            evol5 = 1;
                            evol6 = 1;
                            evolution = 0;
                            continue;
                        }
                    }
                    else if (turn == 3)
                    {
                        die_adventure = rand() % 100;
                        if (die_adventure <= 5)
                        {
                            adventurement(adventurenum);
                            mp += deadmp(evolution);
                            turn++;
                            kg = 0;
                            evol1 = 1;
                            evol2 = 1;
                            evol3 = 1;
                            evol4 = 1;
                            evol5 = 1;
                            evol6 = 1;
                            evolution = 0;
                            continue;
                        }
                    }
                    else if (turn >= 4)
                    {
                        die_adventure = rand() % 100;
                        if (die_adventure == 1)
                        {
                            adventurement(adventurenum);
                            mp += deadmp(evolution);
                            turn++;
                            kg = 0;
                            evol1 = 1;
                            evol2 = 1;
                            evol3 = 1;
                            evol4 = 1;
                            evol5 = 1;
                            evol6 = 1;
                            evolution = 0;
                            continue;
                        }
                    }
                    advenclicknum++; // 모험성공횟수

                    kg += adventurekg;
                    mp += adventuremp;
                    if (adventurenum == 0)
                        printf("몸이 가려워 모험을 무사히 끝냈다!\n");
                    else if (adventurenum == 1)
                        printf("해저에는 진수성찬이 모험을 무사히 끝냈다!\n");
                    else if (adventurenum == 2)
                        printf("바위의 그림자에는 보물이 모험을 무사히 끝냈다!\n");
                    else if (adventurenum == 3)
                        printf("햇볕 쬐기 모험을 무사히 끝냈다!\n");
                    else if (adventurenum == 4)
                        printf("바다거북아,안녕 모험을 무사히 끝냈다!\n");
                    else if (adventurenum == 5)
                        printf("물고기 천국 모험을 무사히 끝냈다!\n");
                    else if (adventurenum == 6)
                        printf("새들은 친구들 모험을 무사히 끝냈다!\n");
                    else if (adventurenum == 7)
                        printf("동료를 구해라! 모험을 무사히 끝냈다!\n");
                    else if (adventurenum == 8)
                        printf("빛의 방향으로 모험을 무사히 끝냈다!\n");
                }
                else // 모험포인트없으면 출력.
                {
                    printf("모험 포인트가 부족해 모험이 불가능합니다.\n");
                    printf("다시 선택지를 골라주세요\n");
                }
                continue; // 선택지로.  안써줘도 상관없을것같다.
            }
            if (game == 3) // 3.상점 mp소모하여 모험과 먹이 업그레이드
            {
                squarebox(4);
                printf("1.먹이 종류 업그레이드 2.모험 업그레이드 3. 먹이 개수 업그레이드\n");
                scanf(" %d", &up);
                if (up == 1) // 먹이업그레이드
                {
                    if (feed == 0)
                    {
                        if (mp >= 110)
                        {
                            mp -= 110;
                            feed++;
                            printf("먹이가 해파리로 업그레이드 되셨습니다.\n");
                        }
                        else
                        {
                            printf("mp가 부족해서 업그레이드가 불가능합니다.\n");
                        }
                    }
                    else if (feed == 1)
                    {
                        if (mp >= 220)
                        {
                            mp -= 220;
                            feed++;
                            printf("먹이가 오징어로 업그레이드 되셨습니다.\n");
                        }
                        else
                        {
                            printf("mp가 부족해서 업그레이드가 불가능합니다.\n");
                        }
                    }
                    else if (feed == 2)
                    {
                        if (mp >= 600)
                        {
                            mp -= 600;
                            feed++;
                            printf("먹이가 새우로 업그레이드 되셨습니다.\n");
                        }
                        else
                        {
                            printf("mp가 부족해서 업그레이드가 불가능합니다.\n");
                        }
                    }
                    else if (feed == 3)
                    {
                        if (mp >= 1200)
                        {
                            mp -= 1200;
                            feed++;
                            printf("먹이가 정어리로 업그레이드 되셨습니다.\n");
                        }
                        else
                        {
                            printf("mp가 부족해서 업그레이드가 불가능합니다.\n");
                        }
                    }
                    else if (feed == 4)
                    {
                        if (mp >= 3200)
                        {
                            mp -= 3200;
                            feed++;
                            printf("먹이가 게로 업그레이드 되셨습니다.\n");
                        }
                        else
                        {
                            printf("mp가 부족해서 업그레이드가 불가능합니다.\n");
                        }
                    }
                    else if (feed == 5)
                    {
                        if (mp >= 6500)
                        {
                            mp -= 6500;
                            feed++;
                            printf("먹이가 가리비로 업그레이드 되셨습니다.\n");
                        }
                        else
                        {
                            printf("mp가 부족해서 업그레이드가 불가능합니다.\n");
                        }
                    }
                    else if (feed == 6)
                    {
                        if (mp >= 11000)
                        {
                            mp -= 11000;
                            feed++;
                            printf("먹이가 굴로 업그레이드 되셨습니다.\n");
                        }
                        else
                        {
                            printf("mp가 부족해서 업그레이드가 불가능합니다.\n");
                        }
                    }
                    else if (feed == 7)
                    {
                        if (mp >= 11000)
                        {
                            mp -= 11000;
                            feed++;
                            printf("먹이가 닭새우로 업그레이드 되셨습니다.\n");
                        }
                        else
                        {
                            printf("mp가 부족해서 업그레이드가 불가능합니다.\n");
                        }
                    }
                    else if (feed == 8)
                    {
                        printf("먹이종류 업그레이드 최고치에 도달하였습니다 \n");
                    }
                }
                if (up == 2) // 모험종류 업그레이드하기 0~8
                {
                    if (adventurenum == 0)
                    {
                        if (mp >= 100)
                        {
                            adventurenum++;
                            adventurekg = 3.9;
                            adventuremp = 30;
                            mp -= 100;
                            printf("해저에는 진수성찬이! 로 모험 업그레이드\n");
                        }
                        else
                        {
                            printf("mp가 부족해서 업그레이드가 불가능합니다 \n");
                        }
                    }
                    else if (adventurenum == 1)
                    {
                        if (mp >= 260)
                        {
                            adventurenum++;
                            adventurekg = 4.9;
                            adventuremp = 40;
                            mp -= 260;
                            printf("바위의 그림자에는 보물이! 로 모험 업그레이드\n");
                        }
                        else
                        {
                            printf("mp가 부족해서 업그레이드가 불가능합니다 \n");
                        }
                    }
                    else if (adventurenum == 2)
                    {
                        if (mp >= 800)
                        {
                            adventurenum++;
                            adventurekg = 11.8;
                            adventuremp = 40;
                            mp -= 800;
                            printf("햇볕 쬐기! 로 모험 업그레이드\n");
                        }
                        else
                        {
                            printf("mp가 부족해서 업그레이드가 불가능합니다 \n");
                        }
                    }
                    else if (adventurenum == 3)
                    {
                        if (mp >= 1600)
                        {
                            adventurenum++;
                            adventurekg = 21.5;
                            adventuremp = 50;
                            mp -= 1600;
                            printf("바다거북아, 안녕! 로 모험 업그레이드\n");
                        }
                        else
                        {
                            printf("mp가 부족해서 업그레이드가 불가능합니다 \n");
                        }
                    }
                    else if (adventurenum == 4)
                    {
                        if (mp >= 1600)
                        {
                            adventurenum++;
                            adventurekg = 21.5;
                            adventuremp = 50;
                            mp -= 1600;
                            printf("바다거북아, 안녕! 로 모험 업그레이드\n");
                        }
                        else
                        {
                            printf("mp가 부족해서 업그레이드가 불가능합니다 \n");
                        }
                    }
                    else if (adventurenum == 5)
                    {
                        if (mp >= 4200)
                        {
                            adventurenum++;
                            adventurekg = 33.7;
                            adventuremp = 60;
                            mp -= 4200;
                            printf("물고기 천국! 로 모험 업그레이드\n");
                        }
                        else
                        {
                            printf("mp가 부족해서 업그레이드가 불가능합니다 \n");
                        }
                    }
                    else if (adventurenum == 6)
                    {
                        if (mp >= 8300)
                        {
                            adventurenum++;
                            adventurekg = 49.9;
                            adventuremp = 110;
                            mp -= 8300;
                            printf("새로운 친구들! 로 모험 업그레이드\n");
                        }
                        else
                        {
                            printf("mp가 부족해서 업그레이드가 불가능합니다 \n");
                        }
                    }
                    else if (adventurenum == 7)
                    {
                        if (mp >= 15000)
                        {
                            adventurenum++;
                            adventurekg = 87.4;
                            adventuremp = 220;
                            mp -= 15000;
                            printf("동료를 구해라! 로 모험 업그레이드\n");
                        }
                        else
                        {
                            printf("mp가 부족해서 업그레이드가 불가능합니다 \n");
                        }
                    }
                    else if (adventurenum == 8)
                    {
                        if (mp >= 24000)
                        {
                            adventurenum++;
                            adventurekg = 120.0;
                            adventuremp = 300;
                            mp -= 24000;
                            printf("빛의 방향으로! 로 모험 업그레이드\n");
                        }
                        else
                        {
                            printf("mp가 부족해서 업그레이드가 불가능합니다 \n");
                        }
                    }
                    else if (adventurenum == 9)
                    {
                        printf("모험 업그레이드 레벨 최고치에 도달하였습니다\n");
                        printf("더이상 업그레이드가 불가능합니다\n");
                    }
                }
                if (up == 3) // 먹이 개수 업그레이드
                {
                    if (feednum == 7)
                    {
                        if (mp >= 24)
                        {
                            feednum++;
                            printf("먹이개수가 %d개로 증가하였습니다.\n", feednum);
                            mp -= 24;
                        }
                        else
                            printf("mp가 부족하여 업그레이드가 불가능합니다.\n");
                    }
                    else if (feednum == 8)
                    {
                        if (mp >= 64)
                        {
                            feednum++;
                            printf("먹이개수가 %d개로 증가하였습니다.\n", feednum);
                            mp -= 64;
                        }
                        else
                            printf("mp가 부족하여 업그레이드가 불가능합니다.\n");
                    }
                    else if (feednum == 9)
                    {
                        if (mp >= 96)
                        {
                            feednum++;
                            printf("먹이개수가 %d개로 증가하였습니다.\n", feednum);
                            mp -= 96;
                        }
                        else
                            printf("mp가 부족하여 업그레이드가 불가능합니다.\n");
                    }
                    else if (feednum == 10)
                    {
                        if (mp >= 128)
                        {
                            feednum++;
                            printf("먹이개수가 %d개로 증가하였습니다.\n", feednum);
                            mp -= 128;
                        }
                        else
                            printf("mp가 부족하여 업그레이드가 불가능합니다.\n");
                    }
                    else if (feednum == 11)
                    {
                        if (mp >= 192)
                        {
                            feednum++;
                            printf("먹이개수가 %d개로 증가하였습니다.\n", feednum);
                            mp -= 192;
                        }
                        else
                            printf("mp가 부족하여 업그레이드가 불가능합니다.\n");
                    }
                    else if (feednum == 12)
                    {
                        if (mp >= 400)
                        {
                            feednum++;
                            printf("먹이개수가 %d개로 증가하였습니다.\n", feednum);
                            mp -= 400;
                        }
                        else
                            printf("mp가 부족하여 업그레이드가 불가능합니다.\n");
                    }
                    else if (feednum == 13)
                    {
                        if (mp >= 600)
                        {
                            feednum++;
                            printf("먹이개수가 %d개로 증가하였습니다.\n", feednum);
                            mp -= 600;
                        }
                        else
                            printf("mp가 부족하여 업그레이드가 불가능합니다.\n");
                    }
                    else if (feednum == 14)
                    {
                        if (mp >= 800)
                        {
                            feednum++;
                            printf("먹이개수가 %d개로 증가하였습니다.\n", feednum);
                            mp -= 800;
                        }
                        else
                            printf("mp가 부족하여 업그레이드가 불가능합니다.\n");
                    }
                    else if (feednum == 15)
                    {
                        if (mp >= 1200)
                        {
                            feednum++;
                            printf("먹이개수가 %d개로 증가하였습니다.\n", feednum);
                            mp -= 1200;
                        }
                        else
                            printf("mp가 부족하여 업그레이드가 불가능합니다.\n");
                    }
                    else if (feednum == 16)
                    {
                        if (mp >= 2080)
                        {
                            feednum++;
                            printf("먹이개수가 %d개로 증가하였습니다.\n", feednum);
                            mp -= 2080;
                        }
                        else
                            printf("mp가 부족하여 업그레이드가 불가능합니다.\n");
                    }
                    else if (feednum == 17)
                    {
                        if (mp >= 3120)
                        {
                            feednum++;
                            printf("먹이개수가 %d개로 증가하였습니다.\n", feednum);
                            mp -= 3120;
                        }
                        else
                            printf("mp가 부족하여 업그레이드가 불가능합니다.\n");
                    }
                    else if (feednum == 18)
                    {
                        if (mp >= 4000)
                        {
                            feednum++;
                            printf("먹이개수가 %d개로 증가하였습니다.\n", feednum);
                            mp -= 4000;
                        }
                        else
                            printf("mp가 부족하여 업그레이드가 불가능합니다.\n");
                    }
                    else if (feednum == 19)
                    {
                        if (mp >= 6000)
                        {
                            feednum++;
                            printf("먹이개수가 %d개로 증가하였습니다.\n", feednum);
                            mp -= 6000;
                        }
                        else
                            printf("mp가 부족하여 업그레이드가 불가능합니다.\n");
                    }
                    else
                    {
                        printf("업그레이드 최대치에 도달하였습니다\n");
                    }
                }
            }
            if (game == 4) // 4.종료.
                break;
        }
    }
    printf("게임이 종료 됩니다 \n"); // 게임 종료

    return 0;
}
void adventurement(int _adventure) // 모험다이 멘트
{
    if (_adventure == 0)
    {
        printf("개복치는 기생충을 떨쳐내기 위해 점프했지만..\n");
        printf("착수 시의 충격으로 그만 죽어버렸다!!\n");
    }
    else if (_adventure == 1)
    {
        printf("개복치는 맛있는 먹이를 찾아서 한 번에 심해로 잠수했지만..\n");
        printf("물이 너무 차가워서 쇼크사했다!!\n");
    }
    else if (_adventure == 2)
    {
        printf("개복치는 거의 앞으로만 헤엄칠 수 있기 때문에..\n");
        printf("바위를 피하지 못하고 부딪혀 죽어버렸다!!\n");
    }
    else if (_adventure == 3)
    {
        printf("개복치는 일광욕한 채로 자버려서..\n");
        printf("육지로 떠올라 몸이 말라 죽어버렸다!!\n");
    }
    else if (_adventure == 4)
    {
        printf("개복치는 바다거북이 무서워서 그만..\n");
        printf("패닉이 되어 호흡법을 잊어버려 죽어버렸다!!\n");
    }
    else if (_adventure == 5)
    {
        printf("개복치는 그물에 걸려..\n");
        printf("인간에게 잡아먹혔다!!\n");
    }
    else if (_adventure == 6)
    {
        printf("개복치는 일광욕을 하여 몸의 기생충을 먹게 하지만..\n");
        printf("자주 새들의 발톱에 상처를 입어 고름이 생겨 죽어버렸다!!\n");
    }
    else if (_adventure == 7)
    {
        printf("개복치는 눈 앞에서 동료가 죽는모습을 보고..\n");
        printf("그 스트레스로 쇼크사했다!!\n");
    }
    else if (_adventure == 8)
    {
        printf("개복치는 섬세해서 아침해가 넘 밝으면..\n");
        printf("놀라서 죽는다!!\n");
    }
    printf("다시 별사탕으로 돌아간다! 응애!!\n");
    sleep(1);
}
void feedment(int _feed)
{

    if (_feed == 1)
        printf("으악!개복치는 해파리와 비닐봉투를 착각하여 죽었다!\n");
    else if (_feed == 2)
        printf("으악!개복치는 내장이 약해서 오징어를 너무 많이 먹어 소화를 시키지 못하여 죽었다!\n");
    else if (_feed == 3)
        printf("으악!개복치는 내장이 약해서 새우를 완전히 삼켜 껍질이 식도를 찔러서 죽었다!\n");
    else if (_feed == 4)
        printf("으악!개복치는 식도가 약해서 정어리의 작은 뼈에 찔려 고름이 생겨 죽었다!\n");
    else if (_feed == 5)
        printf("으악!개복치는 내장이 약해서 게의 다리에 찔려서 고름이 생겨 죽었다!\n");
    else if (_feed == 6)
        printf("으악!개복치는 내장이 약해서 가리비의 껍데기에 찔려서 고름이 생겨 죽었다!\n");
    else if (_feed == 7)
        printf("으악! 굴 껍데기에 찔려서 고름이 생겨 죽었다!(이건 아마 다른생물도..)\n");
    else if (_feed == 8)
        printf("으악! 개복치는 닭새우 껍질 때문에 죽었다! 그리고 돈도 많이 든다!\n");
    sleep(1);
}

int deadmp(int _evolution) // evolution 0~
{
    int result = 0;

    if (_evolution == 0)
        result = 30;
    else if (_evolution == 1)
        result = 120;
    else if (_evolution == 2)
        result = 240;
    else if (_evolution == 3)
        result = 560;
    else if (_evolution == 4)
        result = 900;
    else if (_evolution == 5)
        result = 1950;
    else if (_evolution == 6)
        result = 3340;

    return result;
}
void squarefirst(int n) // 화면
{
    if (n == 1)
    {

        printf("│　　　 　 ∧＿∧                      진화레벨:%d   │레벨0:별사탕\n", evolution);
        printf("│　 　　 (*･∀ ･*)                                 │레벨1:아기\n");
        printf("│  ★*。:ﾟ*〇☆ 〇*ﾟ:。:*★               1.먹이     │레벨2:어린이\n");
        printf("│  ☆｡*･:+*ﾟ　　 ﾟ*+:･*｡☆               2.모험     │레벨3:젊은이\n");
        printf("│  　Ｈ┃Ａ┃Ｐ┃Ｐ┃Ｙ┃                   3.상점     │레벨4:사회의 일원\n");
        printf("│     ━┛ ━┛ ━┛ ━┛ ━┛                   4.종료     │레벨5:개복치왕\n");
        printf("│  　Ｂ┃ Ο ┃Ｇ┃Ｃ┃Ｈ┃Ｉ┃                          │레벨6:수족관주인\n");
        printf("│     ━┛  ━┛ ━┛ ━┛ ━┛ ━┛                          │먹이 성공 횟수: %d\n", feedclicknum);
        printf("│  　　　Ｄ┃Ａ┃Ｙ┃                                │모험 성공 횟수: %d\n", advenclicknum);
        printf("│  　 　  ━┛ ━┛ ━┛                                │\n");
    }
    if (n == 2) // 밥
    {
        printf("│ 　　　♡                    。                   │\n");
        printf("│  　。　／⌒ヽ                                    │\n");
        printf("│ 　　 ／　　　＼         ♡     밥먹는중          │\n");
        printf("│  　　/　　　 丶 ＼             ......           │\n");
        printf("│  　 (/　　　　丶　)            ....             │\n");
        printf("│     /　　　　　丶”       。                 ♡   │\n");
        printf("│    f　　　　　　i                               │\n");
        printf("│   　| ●　　●　　 |                              │\n");
        printf("│   　|　　一　　　|            ♡                 │\n");
        printf("│   　ヽ＿＿ 　 　ノ                              │\n");
        printf("│  　 丿ﾉ ﾉ丁丁￣l＼                              │\n");
        printf("│   く(_(_(＿L＿)ノ                               │\n");
    }
    if (n == 3) // 개복치 모험
    {

        printf("│　 　  　  ∧＿∧                                  │\n");
        printf("│　　,.-､（ ・∀ ・ ）_                            │\n");
        printf("│　　|~~? 　 ∨　 ＿_|二二二つ          개복치는   │\n");
        printf("│ 　 !-.|'ヽ　 　 ＼                     모험중   │\n");
        printf("│ 　  ヽ._ノ ＼　 　ヽ                  .....     │\n");
        printf("│　　　　　　 ヽ. _ ／}                           │\n");
        printf("│　　　　　　　 ∨　  /                            │\n");
        printf("│　　　　　　　 /　/ヽ                            │\n");
        printf("│　　　　　　 ./　/ヽ ヽ                          │\n");
        printf("│　　　　　   │  | 　＼ ＼                        │\n");
        printf("│　　　　　 　│  | 　　 ＼ ＼                     │\n");
        printf("│　／￣＼.　 {__.!　　　　 ＼.）                  │\n");
        printf("│ ! 　 ∴ |                                        │\n");
        printf("│　＼＿／                                         │\n");
    }
    if (n == 4)
    {
        printf("│ 먹이 종류          모험 종류        먹이 개수   │\n");
        printf("├");
        for (int i = 1; i < 50; i++)
            printf("─");
        printf("┤\n");
        printf("│해파리 110         해저 100            8개 24    │\n");
        printf("│오징어 220         바위   260          9개 64    │\n");
        printf("│새우   600         햇볕  800           10개 96   │\n");
        printf("│정어리 1200        바다거북 1600       11개 128  │\n");
        printf("│게     3200        물고기 4200         12개 192  │\n");
        printf("│가리비 6500        친구들 8300         13개 400  │\n");
        printf("│굴     11000       구해라 15000        14개 600  │\n");
        printf("│닭새우 23000       빛의방향  24000     15개 800  │\n");
        printf("│                                       16개 1200 │\n");
        printf("│                                       17개 2080 │\n");
        printf("│                                       18개 3120 │\n");
        printf("│                                       19개 4000 │\n");
        printf("│                                       20개 6000 │\n");
    }
}
void squarebox(int n) // 네모틀만들기
{
    sleep(1);
    system("clear");
    printf("┌");
    for (int i = 1; i < 50; i++)
        printf("─");
    printf("┐\n"); // 위

    squarefirst(n);

    printf("└");
    for (int i = 1; i < 50; i++)
        printf("─");
    printf("┘\n"); // 아래

    printf("     time          kg           mp         point          \n");

    printf("┌");
    for (int i = 1; i < 50; i++)
        printf("─");

    printf("┐\n");

    printf("│    %02d    /   %07.2f    /   %04d  /    %06.2f   │\n", turn, kg, mp, point);

    printf("└");
    for (int i = 1; i < 50; i++)
        printf("─");
    printf("┘\n"); // 아래
}
