//定义剧情流程的函数
#include"Plot.h"
#include"statement.h"
void Plot_1() {
    PrintVerbatim("大学即将毕业的你，面对步入社会的迷茫，宿舍内的你们畅想着未来...");
    system("pause");//同上
    system("cls");
    PrintVerbatim("傍晚时分，你决定去...");
    std::cout << "\033[33m食堂[1]\033[0m" << std:: endl;
    std::cout << "\033[33m操场[2]\033[0m" << std::endl;
    std::cout << "你选择..." << std::endl;
    bool flag = 1;
    while (flag) {
        switch (_getch()) {
        case 49:
            system("cls");
            std::cout << yellow;
            PrintVerbatim(yellow + "独自在享用晚饭，你觉得美食给你的满足是任何东西无法比拟的... (￣y▽,￣)╭\n" + white);
            std::cout << white;
            flag = 0;
            break;
        case 50:
            system("cls");
            std::cout << yellow;
            PrintVerbatim("李华拿着几袋外卖拍了拍你，美食的香味飘进了你的鼻子... (￣﹃￣)\n");
            std::cout << white;
            flag = 0;
            break;
        default:
            break;
        }//中间已省略
    }
    system("pause");
    system("cls");
    PrintVerbatim(yellow + "但是学管理学的你，并不知道该如何做出第一步...\n你诀定得找一个人谈谈..." + white);
    flag = 1;
    while (flag) {
        std::cout << "你选择...\n";
        std::cout << green <<"叔父[1]（在一家饭店里当着厨师）\n" << white;
        std::cout << green <<"李华[2]（你的好兄弟）\n" << white;
        std::cout << green << "Marry[3]（你的辅导员)\n" << white;
        switch (_getch()) {
        case 49:
            std::cout << yellow;
            PrintVerbatim("身为老厨师的他，告诉了你一些行情，并表示期待你的成就...\n");
            std::cout << white;
            flag = 0;
            break;
        case 50:
            std::cout << yellow;
            PrintVerbatim("他虽然也不大了解，但身为大吃货的他，如果需要试吃，他义不容辞... o(￣▽￣)ｄ\n");
            std::cout << white;
            flag = 0;
            break;
        case 51:
            std::cout << yellow;
            PrintVerbatim("她表示你的想法不错，并嘱咐你要有明确目标规划...\n");
            std::cout << white;
            flag = 0;
            break;
        default:
            break;
        }
    }
    system("pause");
    PrintVerbatim("你信誓旦旦的说：“能服务好食客是你的最真诚的想法!”... <(￣︶￣)↗[GO!]");
    system("pause");
    PrintVerbatim("看遍身上，也就只有仅仅1000块，小摊生意对自己来说也许是最好的开始……");
    player->SetPlayerPlot(1);
    return;
}
