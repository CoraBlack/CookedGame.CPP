//����������̵ĺ���
#include"Plot.h"
#include"statement.h"
void Plot_1() {
    PrintVerbatim("��ѧ������ҵ���㣬��Բ���������ã�������ڵ����ǳ�����δ��...");
    system("pause");//ͬ��
    system("cls");
    PrintVerbatim("����ʱ�֣������ȥ...");
    std::cout << "\033[33mʳ��[1]\033[0m" << std:: endl;
    std::cout << "\033[33m�ٳ�[2]\033[0m" << std::endl;
    std::cout << "��ѡ��..." << std::endl;
    bool flag = 1;
    while (flag) {
        switch (_getch()) {
        case 49:
            system("cls");
            std::cout << yellow;
            PrintVerbatim(yellow + "���������������������ʳ������������κζ����޷������... (��y��,��)�q\n" + white);
            std::cout << white;
            flag = 0;
            break;
        case 50:
            system("cls");
            std::cout << yellow;
            PrintVerbatim("����ż��������������㣬��ʳ����ζƮ������ı���... (�����)\n");
            std::cout << white;
            flag = 0;
            break;
        default:
            break;
        }//�м���ʡ��
    }
    system("pause");
    system("cls");
    PrintVerbatim(yellow + "����ѧ����ѧ���㣬����֪�������������һ��...\n���������һ����̸̸..." + white);
    flag = 1;
    while (flag) {
        std::cout << "��ѡ��...\n";
        std::cout << green <<"�常[1]����һ�ҷ����ﵱ�ų�ʦ��\n" << white;
        std::cout << green <<"�[2]����ĺ��ֵܣ�\n" << white;
        std::cout << green << "Marry[3]����ĸ���Ա)\n" << white;
        switch (_getch()) {
        case 49:
            std::cout << yellow;
            PrintVerbatim("��Ϊ�ϳ�ʦ��������������һЩ���飬����ʾ�ڴ���ĳɾ�...\n");
            std::cout << white;
            flag = 0;
            break;
        case 50:
            std::cout << yellow;
            PrintVerbatim("����ȻҲ�����˽⣬����Ϊ��Ի������������Ҫ�Գԣ����岻�ݴ�... o(������)��\n");
            std::cout << white;
            flag = 0;
            break;
        case 51:
            std::cout << yellow;
            PrintVerbatim("����ʾ����뷨������������Ҫ����ȷĿ��滮...\n");
            std::cout << white;
            flag = 0;
            break;
        default:
            break;
        }
    }
    system("pause");
    PrintVerbatim("�����ĵ�����˵�����ܷ����ʳ�����������ϵ��뷨!��... <(�����)�J[GO!]");
    system("pause");
    PrintVerbatim("�������ϣ�Ҳ��ֻ�н���1000�飬С̯������Լ���˵Ҳ������õĿ�ʼ����");
    player->SetPlayerPlot(1);
    return;
}
