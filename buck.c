#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main()
{
    int category = 0;                                                                                                                                                                                         // 카테고리
    int menu1[7][4] = {{4000, 4500, 5000, 5500}, {4500, 5000, 5500, 6000}, {4500, 5000, 5500, 6000}, {5400, 5900, 6400, 6900}, {5400, 5900, 6400, 6900}, {5000, 5500, 6000, 6500}, {5400, 5900, 6400, 6900}}; // 1번 메뉴금액
    // 500원씩차이남.
    int menu2[4][3] = {{5800, 6300, 6800}, {6000, 6500, 7000}, {5800, 6300, 6800}, {4900, 5400, 5900}};
    int menu3[9][3] = {{6300, 6800, 7300}, {6300, 6800, 7300}, {6300, 6800, 7300}, {6000, 6500, 7000}, {6000, 6500, 7000}, {6000, 6500, 7000}, {5900, 6400, 6900}, {5500, 6000, 6500}, {5500, 6000, 6500}};
    int menu4[5][3] = {{6300, 6800, 7300}, {6300, 6800, 7300}, {6300, 6800, 7300}, {6300, 6800, 7300}, {5400, 5900, 6400}};
    int menu5[3][3] = {{5900, 6400, 6900}, {5400, 5900, 6400}, {5400, 5900, 6400}};
    int menu6[8][3] = {{6100, 6600, 7100}, {5900, 6400, 6900}, {5900, 6400, 6900}, {5900, 6400, 6900}, {6100, 6600, 7100}, {5500, 6000, 6500}, {5900, 6400, 6900}, {5700, 6200, 6700}};
    int num[9][4] = {0};  //  개수
    int fee = 0;          // 요금
    int sum = 0;          // 금액합계
    int sales[7] = {0};   // 1번 .....6번 7.총매출
    int sales_p[7] = {0}; // 1....6  7.개인총요금
    int drink = 0;        // 음료
    int size = 0;         // 사이즈 선택

    char menu11[7][50] = {{"아메리카노"}, {"카페라떼"}, {"카푸치노"}, {"카라멜 마키아또"}, {"화이트 초콜릿 모카"}, {"카페모카"}, {"스타벅스 돌체라떼"}};
    char menu22[4][50] = {{"콜드 브루 오트라떼"}, {"돌체콜드브루"}, {"바닐라크림콜드브루"}, {"콜드브루"}};
    char menu33[9][50] = {{"더블 에스프레소 칩 프라푸치노"}, {"제주 유기농 말차 크림 프라푸치노"}, {"자바 칩 프라푸치노"}, {"초콜릿 크림칩 프라푸치노"}, {"화이트 초콜릿 모카 프라푸치노"}, {"모카 프라푸치노"}, {"카라멜 프라푸치노"}, {"에스프레소 프라푸치노"}, {"바닐라크림 프라푸치노"}};
    char menu44[5][50] = {{"민트 초콜릿 칩 블렌디드"}, {"딸기 딜라이트 요거트 블렌디드"}, {"피치레몬 블렌디드"}, {"망고 바나나 블렌디드"}, {"망고 패션 프루트 블렌디드"}};
    char menu55[3][50] = {{"쿨라임 피지오"}, {"블랙티 레모네이드 피지오"}, {"패션 탱고 티 레모네이드 피지오"}};
    char menu66[8][50] = {{"뉴이어 시트러스 티"}, {"돌체 블랙 밀크티"}, {"유자 민트 티"}, {"패션 프루트 티"}, {"제주 유기농 말차 라떼"}, {"차이 티 라떼"}, {"라임 패션 티"}, {"자몽 허니 블랙티"}};

    char size1[4][10] = {{"short"}, {"tall"}, {"grande"}, {"venti"}};
    char size2[3][10] = {{"tall"}, {"grande"}, {"venti"}};

    char cartmenu[20][50] = {0}; // 이름
    char cartsize[20][10] = {0}; // 사이즈
    int cartnum[20] = {0};       // 한음료의개수
    int cart = 0;                // 음료종류 개수

    char answer;         // 계산대답
    char membership[10]; // 멤버십
    double discount = 1; // 할인율

    while (1)
    {
        sum = 0; // 초기화
        // 개수 num배열 초기화
        for (int i = 0; i <= 8; i++)
        {
            for (int j = 0; j <= 3; j++)
                num[i][j] = 0;
        }
        system("clear");
        printf("카테고리를 골라주세요\n");
        printf("1.스타벅스 커피 메뉴\n");
        printf("2.스타벅스 콜드 브루 메뉴\n");
        printf("3.스타벅스 프라푸치노 메뉴\n");
        printf("4.스타벅스 블렌디드 메뉴\n");
        printf("5.스타벅스 피지오 메뉴\n");
        printf("6.스타벅스 티 메뉴\n");
        printf("9.결제하기\n");
        printf("0.일매출 정산\n");
        scanf("%d", &category);
        if (category == 1)
        {
            system("clear");
            printf(" 메뉴                1.SHORT      2.TALL      3.GRANDE     4.VENTI \n");
            printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
            printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
            printf("1.아메리카노           4000        4500         5000        5500\n");
            printf("2.카페라떼             4500        5000         5500        6000\n");
            printf("3.카푸치노             4500        5000         5500        6000\n");
            printf("4.카라멜 마끼아또      5400        5900         6400        6900\n");
            printf("5.화이트 초콜릿 모카   5400        5900         6400        6900\n");
            printf("6.카페모카             5000        5500         6000        6500\n");
            printf("7.스타벅스 돌체라떼    5400        5900         6400        6900\n");
            printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
            printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");

            printf("메뉴를 선택해주세요\n");
            scanf(" %d", &drink);
            printf("사이즈를 선택해주세요.\n");
            scanf(" %d", &size);
            printf("개수를 선택해주세요\n");
            scanf(" %d", &num[(drink - 1)][(size - 1)]);
            for (int i = 0; i <= 6; i++) // 요금계산
            {
                for (int j = 0; j <= 3; j++)
                {
                    fee = menu1[i][j] * num[i][j];
                    sum += fee; // 요금 초기화해야함.
                }
            }
            sales_p[0] += sum;
            strcpy(cartmenu[cart], menu11[drink - 1]);
            strcpy(cartsize[cart], size1[size - 1]);
            cartnum[cart] = num[(drink - 1)][(size - 1)];
            cart++;
        }
        if (category == 2)
        {
            system("clear");
            printf(" 메뉴                 1.TALL     2.GRANDE    3.VENTI \n");
            printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
            printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
            printf("1.콜드 브루 오트라떼      5800       6300       6800\n");
            printf("2.돌체 콜드 브루          6000       6500       7000\n");
            printf("3.바닐라크림 콜드 브루    5800       6300       6800\n");
            printf("4.콜드 브루               4900       5400       5900\n");
            printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
            printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");

            printf("메뉴를 선택해주세요\n");
            scanf(" %d", &drink);
            printf("사이즈를 선택해주세요.\n");
            scanf(" %d", &size);
            printf("개수를 선택해주세요\n");
            scanf(" %d", &num[(drink - 1)][(size - 1)]);
            for (int i = 0; i <= 3; i++) // 요금계산
            {
                for (int j = 0; j <= 2; j++)
                {
                    fee = menu2[i][j] * num[i][j];
                    sum += fee; // 요금
                }
            }
            sales_p[1] += sum;
            strcpy(cartmenu[cart], menu22[drink - 1]);
            strcpy(cartsize[cart], size2[size - 1]);
            cartnum[cart] = num[(drink - 1)][(size - 1)];
            cart++;
        }
        if (category == 3)
        {
            system("clear");
            printf(" 메뉴                              1.TALL    2.GRANDE   3.VENTI \n");
            printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
            printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
            printf("1.더블 에스프레소 칩 프라푸치노       6300      6800      7300\n");
            printf("2.제주 유기농 말차 크림 프라푸치노    6300      6800      7300\n");
            printf("3.자바 칩 프라푸치노                  6300      6800      7300\n");
            printf("4.초콜릿 크림칩 프라푸치노            6000      6500      7000\n");
            printf("5.화이트 초콜릿 모카 프라푸치노       6000      6500      7000\n");
            printf("6.모카 프라푸치노                     6000      6500      7000\n");
            printf("7.카라멜 프라푸치노                   5900      6400      6900\n");
            printf("8.에스프레소 프라푸치노               5500      6000      6500\n");
            printf("9.바닐라크림 프라푸치노               5500      6000      6500\n");
            printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
            printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

            printf("메뉴를 선택해주세요\n");
            scanf(" %d", &drink);
            printf("사이즈를 선택해주세요.\n");
            scanf(" %d", &size);
            printf("개수를 선택해주세요\n");
            scanf(" %d", &num[(drink - 1)][(size - 1)]);
            for (int i = 0; i <= 8; i++) // 요금계산
            {
                for (int j = 0; j <= 2; j++)
                {
                    fee = menu3[i][j] * num[i][j];
                    sum += fee; //
                }
            }
            sales_p[2] += sum;
            strcpy(cartmenu[cart], menu33[drink - 1]);
            strcpy(cartsize[cart], size2[size - 1]);
            cartnum[cart] = num[(drink - 1)][(size - 1)];
            cart++;
        }
        if (category == 4)
        {
            system("clear");
            printf(" 메뉴                         1.TALL   2.GRANDE   3.VENTI \n");
            printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
            printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
            printf("1.민트 초콜릿 칩 블렌디드        6300      6800     7300\n");
            printf("2.딸기 딜라이트 요거트 블렌디드  6300      6800     7300\n");
            printf("3.피치&레몬 블렌디드             6300      6800     7300 \n");
            printf("4.망고 바나나 블렌디드           6300      6800     7300\n");
            printf("5.망고 패션 프루트 블렌디드      5400      5900     6400\n");
            printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
            printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

            printf("메뉴를 선택해주세요\n");
            scanf(" %d", &drink);
            printf("사이즈를 선택해주세요.\n");
            scanf(" %d", &size);
            printf("개수를 선택해주세요\n");
            scanf(" %d", &num[(drink - 1)][(size - 1)]);
            for (int i = 0; i <= 4; i++) // 요금계산
            {
                for (int j = 0; j <= 2; j++)
                {
                    fee = menu4[i][j] * num[i][j];
                    sum += fee; // 요금
                }
            }
            sales_p[3] += sum;
            strcpy(cartmenu[cart], menu44[drink - 1]);
            strcpy(cartsize[cart], size2[size - 1]);
            cartnum[cart] = num[(drink - 1)][(size - 1)];
            cart++;
        }
        if (category == 5)
        {
            system("clear");
            printf(" 메뉴                             1.TALL   2.GRANDE   3.VENTI \n");
            printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
            printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
            printf("1.쿨라임 피지오                   5900      6400     6900\n");
            printf("2.블랙티 레모네이드 피지오        5400      5900     6400\n");
            printf("3.패션 탱고 티 레모네이드 피지오  5400      5900     6400\n");
            printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
            printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

            printf("메뉴를 선택해주세요\n");
            scanf(" %d", &drink);
            printf("사이즈를 선택해주세요.\n");
            scanf(" %d", &size);
            printf("개수를 선택해주세요\n");
            scanf(" %d", &num[(drink - 1)][(size - 1)]);
            for (int i = 0; i <= 2; i++) // 요금계산
            {
                for (int j = 0; j <= 2; j++)
                {
                    fee = menu5[i][j] * num[i][j];
                    sum += fee; // 요금
                }
            }
            sales_p[4] += sum;
            strcpy(cartmenu[cart], menu55[drink - 1]);
            strcpy(cartsize[cart], size2[size - 1]);
            cartnum[cart] = num[(drink - 1)][(size - 1)];
            cart++;
        }
        if (category == 6)
        {
            system("clear");
            printf(" 메뉴                1.TALL   2.GRANDE   3.VENTI \n");
            printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
            printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
            printf("1.뉴이어 시트러스 티    6100      6600     7100\n");
            printf("2.돌체 블랙 밀크티      5900      6400     6900\n");
            printf("3.유자 민트 티          5900      6400     6900\n");
            printf("4.패션 프루트 티        5900      6400     6900\n");
            printf("5.제주 유기농 말차 라떼 6100      6600     7100\n");
            printf("6.차이 티 라떼          5500      6000     6500\n");
            printf("7.라임 패션 티          5900      6400     6900\n");
            printf("8.자몽 허니 블랙티      5700      6200     6700\n");

            printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
            printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

            printf("메뉴를 선택해주세요\n");
            scanf(" %d", &drink);
            printf("사이즈를 선택해주세요.\n");
            scanf(" %d", &size);
            printf("개수를 선택해주세요\n");
            scanf(" %d", &num[(drink - 1)][(size - 1)]);
            for (int i = 0; i <= 7; i++) // 요금 계산
            {
                for (int j = 0; j <= 2; j++)
                {
                    fee = menu6[i][j] * num[i][j];
                    sum += fee; // 요금
                }
            }
            sales_p[5] += sum;
            strcpy(cartmenu[cart], menu66[drink - 1]);
            strcpy(cartsize[cart], size2[size - 1]);
            cartnum[cart] = num[(drink - 1)][(size - 1)];
            cart++;
        }

        if (category == 9)
        {
            system("clear");
            // 멤버십 할인 선택
            for (int i = 0; i <= 5; i++)
                sales_p[6] += sales_p[i];
            // 주문내역 출력하기
            printf("주문내역을 확인해주세요\n");
            printf("──────────────────────────────────────\n");
            for (int i = 0; i < cart; i++)
                printf("%s %s사이즈 %d잔\n", cartmenu[i], cartsize[i], cartnum[i]);
            printf("──────────────────────────────────────\n");

            printf("멤버쉽 적용을 하시겠습니까? Y/N\n");
            scanf(" %c", &answer);
            if (answer == 'Y' || answer == 'y')
            {
                printf("\t최소금액\t할인율\n");
                printf("──────┬──────────────────────────\n");
                printf("Silver│\t10000\t\t5%%\n");
                printf("Gold  │\t20000\t\t15%%\n");
                printf("VIP   │\t없음\t\t15%%\n");
                printf("──────┴──────────────────────────\n");
                printf("멤버쉽을 선택하여 주십시오.(소문자)\n");
                scanf(" %s", membership);
                if (strcmp(membership, "silver") == 0)
                {
                    if (sales_p[6] >= 10000)
                    {
                        discount = 0.95; // 5퍼할인.
                    }
                    else
                        printf("최소금액을 넘지않아 적용이 불가합니다\n");
                }
                if (strcmp(membership, "gold") == 0)
                {
                    if (sales_p[6] >= 20000)
                    {
                        discount = 0.85; // 15퍼할인.
                    }
                    else
                        printf("최소금액을 넘지않아 적용이 불가합니다\n");
                }
                if (strcmp(membership, "vip") == 0)
                {

                    discount = 0.85; // 15퍼할인.
                }
            }
            // 결제금액 ~입니다.

            sales_p[6] *= discount; // 할인율계산
            printf("총 결제금액은 %d 원 입니다.\n", sales_p[6]);

            printf("결제 하시겠습니까? Y/N\n"); // 결제응답
            scanf(" %c", &answer);
            if (answer == 'Y' || answer == 'y')
            {
                printf("결제가 완료되었습니다. 감사합니다\n");

                sleep(2);

                for (int i = 0; i <= 5; i++) // 결제를하면 카테고리별 매출 더하기.
                {
                    sales[i] += (sales_p[i] * discount);
                }
                discount = 1;
                cart = 0;

                for (int i = 0; i <= 6; i++) // sales_p초기화
                    sales_p[i] = 0;
            }
            if (answer == 'N' || answer == 'n')
            {
                printf("결제가 취소되었습니다. 안녕히 가십시오\n");
                // 초기화 다음손님
                discount = 1;
                cart = 0;

                for (int i = 0; i <= 6; i++) // sales_p초기화
                    sales_p[i] = 0;
                sleep(2);
            }
        }
        if (category == 0)
        {
            system("clear");
            sales[6] = 0;
            for (int i = 0; i <= 5; i++) // 일일 총매출 합산
                sales[6] += sales[i];

            printf("스타벅스 커피 메뉴 매출 : %d\n", sales[0]);
            printf("스타벅스 콜드 브루 매출 : %d\n", sales[1]);
            printf("스타벅스 프라푸치노 매출: %d\n", sales[2]);
            printf("스타벅스 블렌디드 매출  : %d\n", sales[3]);
            printf("스타벅스 피지오 매출    : %d\n", sales[4]);
            printf("스타벅스 티 매출        : %d\n", sales[5]);
            printf("─────────────────────────────────\n");
            printf("스타벅스 총 매출        : %d\n", sales[6]);

            printf("오늘 영업 종료  y/n\n");
            scanf(" %c", &answer);
            if (answer == 'y')
                break;
        }
    }
    return 0;
}