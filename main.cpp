#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <time.h>
#include <string>
#include <conio.h>
#include <stdio.h>

using namespace std;

void foo()
{
    float timestart=(float)clock()/(float)CLOCKS_PER_SEC;
    float delay=10;//sec
    float timeend=timestart+delay;
    int printed_time=(int)delay;

    cout<<"starting foo loop\n";
    while( true )
    {
        float timenow=(float)clock()/(float)CLOCKS_PER_SEC;
        if( timenow>=timeend )
        {
            break;
        }

        if( int(timeend-timenow)<printed_time )
        {
            printed_time=int(timeend-timenow);
            cout<<printed_time+1<<" sec left...foo"<<endl;
        }
    }
    cout<<"foo loop complete\n";
}

void bar(int x)
{
    //echo
    while(true)
    {
        string line;
        getline(cin,line);

        cout<<"out: "<<line<<endl;

        if(line=="exit") break;
    }

    cout<<"bar loop complete\n";
}

int main()
{
    thread first (foo);     // spawn new thread that calls foo()
    thread second (bar,0);  // spawn new thread that calls bar(0)

    cout << "main, foo and bar now execute concurrently...\n";

    // synchronize threads:
    first.join();                // pauses until first finishes
    second.join();               // pauses until second finishes

    cout << "foo and bar completed.\n";


    return 0;
}
