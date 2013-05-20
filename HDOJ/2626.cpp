#include<iostream>
using namespace std;
int main()
{
    int t,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        switch(n)
        {
            case 0:cout << "Samuel will go out." << endl;break;
            case 1:cout << "Samuel will decorate." << endl;break;
            case 2:cout << "Samuel will decorate." << endl;break;
            case 3:cout << "Samuel will stay at home." << endl;break;
            case 4:cout << "Samuel will go to movies." << endl;break;
            case 5:cout << "Samuel will meet friends." << endl;break;
            case 6:cout << "Samuel will go to KTV." << endl;break;
            case 7:cout << "Samuel will visit teachers." << endl;break;
            case 8:cout << "Samuel will stay at home." << endl;break;
            case 9:cout << "Samuel will buy food." << endl;break;
            case 10:cout << "Samuel will buy clothes." << endl;break;
            case 11:cout << "Samuel will stay at home." << endl;break;
            case 12:cout << "Samuel will go home." << endl;break;
            case 13:cout << "Samuel will take test." << endl;break;
            case -1:cout << "Samuel will be in the park." << endl;break;
            case -2:cout << "Samuel will stay at home." << endl;break;
            case -3:cout << "Samuel will visit relative." << endl;break;
            case -4:cout << "Samuel will visit relative." << endl;break;
            case -5:cout << "Samuel will stay at home." << endl;break;
            case -6:cout << "Samuel will prepare dinner." << endl;break;
        }
    }    
}
