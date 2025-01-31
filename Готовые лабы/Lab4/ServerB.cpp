﻿#include <iostream>
#include <string>
#include <clocale>
#include <ctime>
#include "Winsock2.h"
#include <vector>
#include <string>
#pragma comment(lib, "WS2_32.lib")
#pragma warning(disable:4996)
using namespace std;

string GetErrorMsgText(int code) {
    string msgText;
    switch (code) {
    case WSAEINTR: msgText = "WSAEINTR: Работа функции прервана "; break;
    case WSAEACCES: msgText = "WSAEACCES: Разрешение отвергнуто"; break;
    case WSAEFAULT: msgText = "WSAEFAULT: Ошибочный адрес"; break;
    case WSAEINVAL: msgText = "WSAEINVAL: Ошибка в аргументе"; break;
    case WSAEMFILE: msgText = "WSAEMFILE: Слишком много файлов открыто"; break;
    case WSAEWOULDBLOCK:msgText = "WSAEWOULDBLOCK: Ресурс временно недоступен"; break;
    case WSAEINPROGRESS:msgText = "WSAEINPROGRESS: Операция в процессе развития"; break;
    case WSAEALREADY:msgText = "WSAEALREADY: Операция уже выполняется "; break;
    case WSAENOTSOCK:msgText = "WSAENOCTSOCK: Сокет задан неправильно   "; break;
    case WSAEDESTADDRREQ:msgText = "WSAEDESTADDRREQ: Требуется адрес расположения "; break;
    case WSAEMSGSIZE:msgText = "WSAEMSGSIZE: Сообщение слишком длинное "; break;
    case WSAEPROTOTYPE:msgText = "WSAEPROTOTYPE: Неправильный тип протокола для сокета "; break;
    case WSAENOPROTOOPT:msgText = "WSAENOPROTOOPT: Ошибка в опции протокола"; break;
    case WSAEPROTONOSUPPORT:msgText = "WSAEPROTONOSUPPORT: Протокол не поддерживается "; break;
    case WSAESOCKTNOSUPPORT:msgText = "WSAESOCKTNOSUPPORT: Тип сокета не поддерживается "; break;
    case WSAEOPNOTSUPP:msgText = "WSAEOPNOTSUPP: Операция не поддерживается "; break;
    case WSAEPFNOSUPPORT:msgText = "WSAEPFNOSUPPORT: Тип протоколов не поддерживается "; break;
    case WSAEAFNOSUPPORT:msgText = "WSAEAFNOSUPPORT: Тип адресов не поддерживается протоколом"; break;
    case WSAEADDRINUSE:msgText = "WSAEADDRINUSE: Адрес уже используется "; break;
    case WSAEADDRNOTAVAIL:msgText = "WSAEADDRNOTAVAIL: Запрошенный адрес не может быть использован"; break;
    case WSAENETDOWN:msgText = "WSAENETDOWN: Сеть отключена "; break;
    case WSAENETUNREACH:msgText = "WSAENETUNREACH: Сеть не достижима"; break;
    case WSAENETRESET:msgText = "WSAENETRESET: Сеть разорвала соединение"; break;
    case WSAECONNABORTED:msgText = "WSAECONNABORTED: Программный отказ связи "; break;
    case WSAECONNRESET:msgText = "WSAECONNRESET: Связь восстановлена "; break;
    case WSAENOBUFS:msgText = "WSAENOBUFS: Не хватает памяти для буферов"; break;
    case WSAEISCONN:msgText = "WSAEISCONN: Сокет уже подключен"; break;
    case WSAENOTCONN:msgText = "WSAENOTCONN: Сокет не подключен"; break;
    case WSAESHUTDOWN:msgText = "WSAESHUTDOWN: Нельзя выполнить send: сокет завершил работу"; break;
    case WSAETIMEDOUT:msgText = "WSAETIMEDOUT: Закончился отведенный интервал  времени"; break;
    case WSAECONNREFUSED:msgText = "WSAECONNREFUSED: Соединение отклонено"; break;
    case WSAEHOSTDOWN:msgText = "WSAEHOSTDOWN: Хост в неработоспособном состоянии"; break;
    case WSAEHOSTUNREACH:msgText = "WSAEHOSTUNREACH: Нет маршрута для хоста"; break;
    case WSAEPROCLIM:msgText = "WSAEPROCLIM: Слишком много процессов "; break;
    case WSASYSNOTREADY:msgText = "WSASYSNOTREADY: Сеть не доступна "; break;
    case WSAVERNOTSUPPORTED:msgText = "WSAVERNOTSUPPORTED: Данная версия недоступна"; break;
    case WSANOTINITIALISED:msgText = "WSANOTINITIALISED: Не выполнена инициализация WS2_32.DLL"; break;
    case WSAEDISCON:msgText = "WSAEDISCON: Выполняется отключение"; break;
    case WSATYPE_NOT_FOUND:msgText = "WSATYPE_NOT_FOUND: Класс не найден"; break;
    case WSAHOST_NOT_FOUND:msgText = "WSAHOST_NOT_FOUND: Хост не найден"; break;
    case WSATRY_AGAIN:msgText = "WSATRY_AGAIN: Неавторизированный хост не найден"; break;
    case WSANO_RECOVERY:msgText = "WSANO_RECOVERY: Неопределенная  ошибка"; break;
    case WSANO_DATA:msgText = "WSANO_DATA: Нет записи запрошенного типа "; break;
    case WSA_INVALID_HANDLE:msgText = "WSA_INVALID_HANDLE: Указанный дескриптор события  с ошибкой"; break;
    case WSA_INVALID_PARAMETER:msgText = "WSA_INVALID_PARAMETER: Один или более параметров с ошибкой"; break;
    case WSA_IO_INCOMPLETE:msgText = "WSA_IO_INCOMPLETE: Объект ввода-вывода не в сигнальном состоянии"; break;
    case WSA_IO_PENDING:msgText = "WSA_IO_PENDING: Операция завершится позже"; break;
    case WSA_NOT_ENOUGH_MEMORY:msgText = "WSA_NOT_ENOUGH_MEMORY: Не достаточно памяти"; break;
    case WSA_OPERATION_ABORTED:msgText = "WSA_OPERATION_ABORTED: Операция отвергнута"; break;
    case WSAEINVALIDPROCTABLE:msgText = "WSAEINVALIDPROCTABLE: Ошибочный сервис"; break;
    case WSAEINVALIDPROVIDER:msgText = "WSAEINVALIDPROVIDER: Ошибка в версии сервиса"; break;
    case WSAEPROVIDERFAILEDINIT:msgText = "WSAEPROVIDERFAILEDINIT: Невозможно инициализировать сервис"; break;
    case WSASYSCALLFAILURE: msgText = "WSASYSCALLFAILURE: Аварийное завершение системного вызова"; break;
    default: msgText = "***ERROR***"; break;
    };
    return msgText;
}

//вопрос по теории: как расчитывается broadcast с ip 172.20.10.2 и маской подсети 255.255.254.0
//инверсия маски подсети, то в ответе 172.20.11.255
string SetErrorMsgText(string msgText, int code) {
    return msgText + GetErrorMsgText(code);
}

bool GetRequestFromClient(char* name, short port, struct sockaddr* from, int* flen) {
    SOCKET sS;
    SOCKADDR_IN serv;
    serv.sin_family = AF_INET;
    serv.sin_port = htons(port);
    serv.sin_addr.s_addr = INADDR_ANY;
    int reuse = 1;
    char buf[50];
    int len;

    if ((sS = socket(AF_INET, SOCK_DGRAM, NULL)) == INVALID_SOCKET) {
        throw SetErrorMsgText("socket: ", WSAGetLastError());
    }

    if (setsockopt(sS, SOL_SOCKET, SO_REUSEADDR, (const char*)&reuse, sizeof(reuse)) == SOCKET_ERROR) { //SO_BROADCAST
        throw SetErrorMsgText("setsockopt: ", WSAGetLastError());
    }

    if (bind(sS, (LPSOCKADDR)&serv, sizeof(serv)) == SOCKET_ERROR) {
        throw SetErrorMsgText("bind: ", WSAGetLastError());
    }

    while (true) {
        if ((len = recvfrom(sS, buf, sizeof(buf), NULL, from, flen)) == SOCKET_ERROR) {
            int errCode = WSAGetLastError();
            if (errCode == WSAETIMEDOUT) {
                return false;
            }
            else {
                closesocket(sS);
                throw SetErrorMsgText("recvfrom: ", errCode);
            }
        }

        if (strcmp(buf, name) == 0) {
            closesocket(sS);
            return true;
        }
    }
}

bool PutAnswerToClient(char* name, struct sockaddr* to, int* lto) {
    SOCKET sS;

    if ((sS = socket(AF_INET, SOCK_DGRAM, NULL)) == INVALID_SOCKET) {
        throw SetErrorMsgText("socket (PutAnswerToClient): ", WSAGetLastError());
    }

    if (sendto(sS, name, strlen(name) + 1, NULL, to, *lto) == SOCKET_ERROR) {
        closesocket(sS);
        throw SetErrorMsgText("sendto: ", WSAGetLastError());
    }

    closesocket(sS);
    return true;
}

void DiscoverServers(char* name, short port) {
    SOCKET sS;
    SOCKADDR_IN serv;
    serv.sin_family = AF_INET;
    serv.sin_port = htons(port);
    serv.sin_addr.s_addr = INADDR_ANY;
    int broadcast = 1;

    if ((sS = socket(AF_INET, SOCK_DGRAM, NULL)) == INVALID_SOCKET) {
        throw SetErrorMsgText("socket (DiscoverServers): ", WSAGetLastError());
    }

    if (setsockopt(sS, SOL_SOCKET, SO_BROADCAST, (char*)&broadcast, sizeof(broadcast)) == SOCKET_ERROR) {
        throw SetErrorMsgText("setsockopt (SO_BROADCAST): ", WSAGetLastError());
    }

    //настройка адреса для отправки
    serv.sin_addr.s_addr = inet_addr("172.20.10.15");
    int len = sizeof(serv);

    if (sendto(sS, name, strlen(name) + 1, 0, (struct sockaddr*)&serv, len) == SOCKET_ERROR) {
        throw SetErrorMsgText("sendto: ", WSAGetLastError());
    }

    //для получения ответов
    fd_set fds; //множество дескрипторов для select
    struct timeval tv; //для задания таймаута
    tv.tv_sec = 5;
    tv.tv_usec = 0;

    int serverCount = 0;

    cout << "Ожидание ответа от серверов..." << endl;

    //проверка на наличие ответов
    while (true) {
        FD_ZERO(&fds); //очистка набора дескрипторов перед каждым select()
        FD_SET(sS, &fds); //добавление сокета в набор для слежки позывного
        int activity = select(sS + 1, &fds, NULL, NULL, &tv);  //следим за чтением

        if (activity > 0) { //данные готовы для чтения
            SOCKADDR_IN from; //для хранения адреса
            int fromLen = sizeof(from);
            char buf[50];
            int recvLen = recvfrom(sS, buf, sizeof(buf), 0, (struct sockaddr*)&from, &fromLen);

            if (recvLen > 0 && strcmp(buf, name) == 0) {
                serverCount++;
                cout << "Сервер найден с позывным " << name << ". Адрес: "
                    << inet_ntoa(from.sin_addr) << ", порт: " << ntohs(from.sin_port) << endl;
            }
        }
        else {
            break;
        }
    }

    cout << "Найдено серверов: " << serverCount << endl;
    closesocket(sS);
}

int main()
{
    setlocale(LC_ALL, "RU");
    WSADATA wsaData;
    SOCKADDR_IN clnt;
    int lclnt = sizeof(clnt);

    try {
        if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0) {
            throw SetErrorMsgText("Startup: ", WSAGetLastError());
        }

        cout << "Сервер запущен. Ожидание подключения клиентов..." << endl;

        DiscoverServers((char*)"Hello", 2000);

        while (true) {
            memset(&clnt, 0, sizeof(clnt));

            if (GetRequestFromClient((char*)"Hello", 2000, (sockaddr*)&clnt, &lclnt)) {
                cout << "Получен правильный позывной от клиента." << endl;
                cout << "Параметры клиента: IP " << inet_ntoa(clnt.sin_addr) << ", порт " << ntohs(clnt.sin_port) << endl;

                if (PutAnswerToClient((char*)"Hello", (sockaddr*)&clnt, &lclnt)) {
                    cout << "Ответ отправлен клиенту." << endl;
                }
            }
            else {
                cout << "Таймаут ожидания запроса." << endl;
            }
        }

        if (WSACleanup() == SOCKET_ERROR) {
            throw SetErrorMsgText("Cleanup: ", WSAGetLastError());
        }
    }
    catch (string errorMsgText) {
        cout << endl << "WSAGetLastError: " << errorMsgText;
    }

    return 0;
}