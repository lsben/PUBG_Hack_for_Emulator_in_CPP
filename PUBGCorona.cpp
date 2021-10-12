/*******************************************************************************************
********************************************************************************************
** Official site **** https://www.01000000000.com                                       ****
********************************************************************************************
**        Auther **** Programmer / Ayman                                                ****
********************************************************************************************
**         Email **** info@01000000000.com                                              ****
********************************************************************************************
**   Source code **** https://github.com/Zero-One-Billion/PUBG_Hack_for_Emulator_in_CPP ****
********************************************************************************************
*******************************************************************************************/


#include "pch.h"

int main()
{
    SetConsoleTitle(L"PUBG Corona");

    cout << "[Official site] Zero One Billion ( www.01000000000.com )\n";

    cout << "[+] Loading font file ...\n";
    if (!g_pESP->loadFont())
    {
        cout << "Can\'t load font file\n";
        system("pause");
        return 0;
    }
    cout << "Font file loaded successfully\n";

    cout << "[+] Connecting to driver ...\n";
    if (!g_pMemoryManager->init())
    {
        cout << "FAILED ... Error connecting driver. Run this app as \'Administrator\' and disable antivirus\n";
        system("pause");
        return 0;
    }
    cout << "SUCCESS ... Connected to driver successfully\n";

    cout << "[+] Getting process ID ...\n";
    int pid = g_pMemoryManager->getAowProcId();
    if (pid < 1)
    {
        cout << "FAILED ... Error getting process ID. Make sure the game is running\n";
        system("pause");
        return 0;
    }
    cout << "SUCCESS ... Process ID is " << pid << "\n";

    g_pMemoryManager->processId = pid;

    cout << "[+] Getting process handle ... \n";
    if (!g_pMemoryManager->getProcHandle())
    {
        cout << "FAILED ... Run this app as \'administrator\'\n";
        system("pause");
        return 0;
    }
    cout << "SUCCESS ...\n";

    g_pESP->init();

    g_pOverlay->createWindow();

    g_pESP->setDrawings();

    cout << "Ready\n";

    while (g_pOverlay->window.isOpen())
    {
        sf::Event event;
        while (g_pOverlay->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                cout << "Drawings error\n";
                Sleep(1000);
            }
        }
        g_pOverlay->window.clear(sf::Color::Transparent);
        g_pESP->getViewMatrix();
        g_pESP->scanEntityList();
        g_pOverlay->window.display();
    }
    system("pause");
}
