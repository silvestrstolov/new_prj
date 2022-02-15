#include <hall.h>


int menu(void)
{
    int key;

    cout << "1. creat arrey" << endl;
    cout << "2.faind minimal doubles element in errey" << endl;
    cout << "3.faind prodused element arrea" << endl;
    cout << "4.creat matrix" << endl;
    cout << "5.find analog value in matrix" << endl;
    cout << "6.move border" << endl;
    cout << "7.find inverded matrix" << endl;
    cout << "8.print" << endl;
    cout << "9.print matrix" << endl;
    cout << "10. fill new arrea" << endl;
    cout << "11. fill new matrix" << endl << endl << endl;


    cout << " laba 3: sort array" << endl << endl;

    cout << "12. simple insertion sort" << endl;
    cout << "13. simple bubble sort" << endl;
    cout << "14. simple choice sort" << endl;
    cout << "15. quickly sort" << endl;
    cout << "16. Shell sort" << endl;
    cout << "17. piramid sort" << endl;
    cout << "18. matrix sort" << endl;
    cout << "19. BinFindElement" << endl;




            cin >> key;
    fflush(stdin);
    return key;
}
